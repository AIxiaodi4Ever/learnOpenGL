#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <learnopengl/mesh.h>
#include <learnopengl/shader_s.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

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

private:
	// model data
	vector<Mesh> meshes;
	vector<Texture> textures_loaded;
	string directory;
	bool gammaCorrection;

	void loadModel(string path) {
		Assimp::Importer import;
		std::cout << "assimp read file" << std::endl;
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

	Mesh processMesh(aiMesh* mesh, const aiScene* scene) {
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;

		// process vertex posiitons, normals and texture coordinates
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			Vertex vertex;

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

		// return a mesh object created from the extracted mesh data
		return Mesh(vertices, indices, textures);
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