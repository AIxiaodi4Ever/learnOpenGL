#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

#include <glad/glad.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <learnopengl/mesh.h>
#include <learnopengl/shader_s.h>


#include <learnopengl/assimp_glm_helpers.h>
#include <learnopengl/animdata.h>

using namespace std;

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);

class Model {
public:
	Model(const char* path) {
		loadModel(path);
	}

	void Draw(Shader& shader) {
		for (unsigned int i = 0; i < meshes.size(); ++i) {
			meshes[i].Draw(shader);
		}
	}

	const vector<Mesh>& getMeshes() const {
		return meshes; 
	}

	const vector<Texture>& getTextures() const {
		return textures_loaded;
	}

	auto& GetBoneInfoMap() { return m_BoneInfoMap; }
	int& GetBoneCount() { return m_BoneCounter; }

private:
	// model data
	vector<Mesh> meshes;
	vector<Texture> textures_loaded;
	string directory;
	bool gammaCorrection;
    std::map<string, BoneInfo> m_BoneInfoMap;
    int m_BoneCounter = 0;

	void loadModel(string path) {
		Assimp::Importer import;
		std::cout << "assimp read file: " << path << std::endl;
		const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
			return;
		}
		directory = path.substr(0, path.find_last_of('/'));

		int totalVertices = 0, totalTextures = 0;
		for (int i = 0; i < scene->mNumMeshes; ++i) {
			totalVertices += scene->mMeshes[i]->mNumVertices;
		}
		for (int i = 0; i < scene->mNumMaterials; ++i) {
			totalTextures += scene->mMaterials[i]->GetTextureCount(aiTextureType_DIFFUSE);
			totalTextures += scene->mMaterials[i]->GetTextureCount(aiTextureType_SPECULAR);
			totalTextures += scene->mMaterials[i]->GetTextureCount(aiTextureType_NORMALS);
			totalTextures += scene->mMaterials[i]->GetTextureCount(aiTextureType_HEIGHT);
		}
		std::cout << "total vertices: " << totalVertices << std::endl;
		std::cout << "total texture: " << totalTextures << std::endl;

		std::cout << "process node" << std::endl;
		processNode(scene->mRootNode, scene);
	}

	void processNode(aiNode* node, const aiScene* scene) {
		// process all the node's meshes (if any)
		for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
			std::cout << "mesh num: " << i << "  total mesh: " << node->mNumMeshes << std::endl;
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(processMesh(mesh, scene));
		}
		// then do the same for each of its children
		for (unsigned int i = 0; i < node->mNumChildren; ++i) {
			std::cout << "node num: " << i << " total children: " << node->mNumChildren << std::endl;
			processNode(node->mChildren[i], scene);
		}
	}

	void SetVertexBoneDataToDefault(Vertex& vertex)
	{
		for (int i = 0; i < MAX_BONE_INFLUENCE; i++)
		{
			vertex.m_BoneIDs[i] = -1;
			vertex.m_Weights[i] = 0.0f;
		}
	}

	Mesh processMesh(aiMesh* mesh, const aiScene* scene) {
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;

		// process vertex posiitons, normals and texture coordinates
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			Vertex vertex;
			SetVertexBoneDataToDefault(vertex);
			// position
			glm::vec3 v;
			v.x = mesh->mVertices[i].x;
			v.y = mesh->mVertices[i].y;
			v.z = mesh->mVertices[i].z;
			vertex.Position = v;
			// normal
			v.x = mesh->mNormals[i].x;
			v.y = mesh->mNormals[i].y;
			v.z = mesh->mNormals[i].z;
			vertex.Normal = v;
			// texture coordinate
			if (mesh->mTextureCoords[0]) {
				glm::vec2 vec;
				vec.x = mesh->mTextureCoords[0][i].x;
				vec.y = mesh->mTextureCoords[0][i].y;
				vertex.TexCoords = vec;
			}
			else {
				vertex.TexCoords = glm::vec2(0.0f, 0.0f);
			}
			
			vertices.push_back(vertex);
		}

		// process indices
		for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
			aiFace face = mesh->mFaces[i];
			for (unsigned int j = 0; j < face.mNumIndices; ++j) {
				indices.push_back(face.mIndices[j]);
			}
		}

		// process materials
		if (mesh->mMaterialIndex >= 0) {
			aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
			// diffuse maps
			vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
			textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
			// specular maps
			vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
			textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
			// normal maps
			vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");
			textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
			// height maps
			vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_height");
			textures.insert(textures.end(), textures.begin(), textures.end());
		}

		ExtractBoneWeightForVertices(vertices,mesh,scene);
		// return a mesh object created from the extracted mesh data
		return Mesh(vertices, indices, textures);
	}

    void SetVertexBoneData(Vertex& vertex, int boneID, float weight)
	{
		for (int i = 0; i < MAX_BONE_INFLUENCE; ++i)
		{
			if (vertex.m_BoneIDs[i] < 0)
			{
				vertex.m_Weights[i] = weight;
				vertex.m_BoneIDs[i] = boneID;
				break;
			}
		}
	}

	void ExtractBoneWeightForVertices(std::vector<Vertex>& vertices, aiMesh* mesh, const aiScene* scene)
	{
		auto& boneInfoMap = m_BoneInfoMap;
		int& boneCount = m_BoneCounter;

		for (int boneIndex = 0; boneIndex < mesh->mNumBones; ++boneIndex)
		{
			int boneID = -1;
			std::string boneName = mesh->mBones[boneIndex]->mName.C_Str();
			if (boneInfoMap.find(boneName) == boneInfoMap.end())
			{
				BoneInfo newBoneInfo;
				newBoneInfo.id = boneCount;
				newBoneInfo.offset = AssimpGLMHelpers::ConvertMatrixToGLMFormat(mesh->mBones[boneIndex]->mOffsetMatrix);
				boneInfoMap[boneName] = newBoneInfo;
				boneID = boneCount;
				boneCount++;
			}
			else
			{
				boneID = boneInfoMap[boneName].id;
			}
			assert(boneID != -1);
			auto weights = mesh->mBones[boneIndex]->mWeights;
			int numWeights = mesh->mBones[boneIndex]->mNumWeights;

			for (int weightIndex = 0; weightIndex < numWeights; ++weightIndex)
			{
				int vertexId = weights[weightIndex].mVertexId;
				float weight = weights[weightIndex].mWeight;
				assert(vertexId <= vertices.size());
				SetVertexBoneData(vertices[vertexId], boneID, weight);
			}
		}
	}

	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName) {
		vector<Texture> textures;
		for (unsigned int i = 0; i < mat->GetTextureCount(type); ++i) {
			aiString str;
			mat->GetTexture(type, i, &str);
			// check if the texture was loaded and if so, continue to next iteration: skip loading a new texture
			bool skip = false;
			for (unsigned int j = 0; j < textures_loaded.size(); ++j) {
				if (std::strcmp(textures_loaded[j].path.c_str(), str.C_Str()) == 0) {
					textures.push_back(textures_loaded[j]);	// a texture with the same name already been loaded, continue to next one
					skip = true;
					break;
				}
			} // j
			if (!skip) {
				Texture texture;
				texture.id = TextureFromFile(str.C_Str(), directory, false);
				texture.type = typeName;
				texture.path = str.C_Str();
				textures.push_back(texture);
				textures_loaded.push_back(texture); // store it as texture loaded for entire model, to ensure we won't unnecessarily load duplicate textures
			}

		} // i
		return textures;
	}

	unsigned int TextureFromFile(const char* path, const string &directory, bool gamma) {
		string filename = string(path);
		filename = directory + '/' + filename;
	
		unsigned int textureID;
		glGenTextures(1, &textureID);

		int width, height, nrComponents;
		unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data) {
			GLenum format;
			if (nrComponents == 1) {
				format = GL_RED;
			} else if (nrComponents == 3) {
				format = GL_RGB;
			} else if (nrComponents == 4) {
				format = GL_RGBA;
			}

			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		} else {
			std::cout << "Texture fail to load from path: " << path << std::endl;
			stbi_image_free(data);
		}

		return textureID;
	}

};

#endif