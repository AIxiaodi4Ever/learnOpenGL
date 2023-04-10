#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* Model is used to load the vertex and index format triangle mesh model */
class Model {
public:
	/* constructor Function using the vertex file path and index file path to load the vertex array and index array */
	Model(const char* vertexPath, const char* indexPath) {
		vertexLines = 0; // count the line number, used to allocate memory
		indexLines = 0;	
		std::ifstream vertexFile, indexFile;	// file stream used to load file
		// ensure ifstream can throw exceptions
		vertexFile.exceptions(std::ifstream::badbit);	// can't use failbit because eofbit will also set failbit then we can't get the line numbers
		indexFile.exceptions(std::ifstream::badbit);
		try
		{
			// open file
			vertexFile.open(vertexPath);
			indexFile.open(indexPath);

			std::string s;
			while (std::getline(vertexFile, s)) {
				++vertexLines;
			}
			s = "";
			while (std::getline(indexFile, s) ) {
				++indexLines;
			}
			s = "";

			std::cout << vertexLines << std::endl;
			
			vertexFile.clear(std::ios::goodbit);
			vertexFile.seekg(std::ios::beg);
			indexFile.clear(std::ios::goodbit);
			indexFile.seekg(std::ios::beg);

			vertex = new float[(long long)vertexLines * 3];
			index = new unsigned int[(long long)indexLines * 3];

			int idx = 0;
			float vertexValue = 0;
			while (vertexFile >> vertexValue) {
				vertex[idx++] = vertexValue;
			}
			//std::cout << idx << std::endl;
			idx = 0;
			unsigned int indexValue;
			while (indexFile >> indexValue) {
				index[idx++] = indexValue;
			}
			//std::cout << idx << std::endl;

			vertexFile.close();
			indexFile.close();

			calculateNormal();

			vertexAndNormal = new float[vertexLines * 6];
			for (int i = 0; i < vertexLines; ++i) {
				vertexAndNormal[i * 3] = vertex[i * 3];
				vertexAndNormal[i * 3 + 1] = vertex[i * 3 + 1];
				vertexAndNormal[i * 3 + 2] = vertex[i * 3 + 2];
				vertexAndNormal[i * 3 + 3] = normal[i * 3];
				vertexAndNormal[i * 3 + 4] = normal[i * 3 + 1];
				vertexAndNormal[i * 3 + 5] = normal[i * 3  +2];
			}
		}
		catch (const std::ifstream::failure& e)
		{
			std::cout << "ERROR::LOAD_MODEL_FILE_FAILED" << std::endl;
		}
	}

	~Model(){
		delete[]vertex;
		delete[]index;
		delete[]normal;
		delete[]vertexAndNormal;
	}

public:
	float* vertex;
	float* normal;
	float* vertexAndNormal;
	unsigned int* index;
	unsigned int vertexLines, indexLines;
	const float epsilon = 0.00001;
private:
	glm::vec3 calculateDiff(unsigned int xidx, unsigned int yidx) {
		glm::vec3 xy;
		xy.x = vertex[yidx * 3] - vertex[xidx * 3];
		xy.y = vertex[yidx * 3 + 1] - vertex[xidx * 3 + 1];
		xy.z = vertex[yidx * 3 + 2] - vertex[xidx * 3 + 2];
		return xy;
	}
	void setNormal(unsigned int idx, glm::vec3 vertexNormal) {
		/*if ((normal[idx * 3] > -epsilon && normal[idx * 3] < epsilon) &&
			(normal[idx * 3 + 1] > -epsilon && normal[idx * 3 + 1] < epsilon) &&
			(normal[idx * 3 + 2] > -epsilon && normal[idx * 3 + 2] < epsilon)) {
			normal[idx * 3] = vertexNormal.x;
			normal[idx * 3 + 1] = vertexNormal.y;
			normal[idx * 3 + 2] = vertexNormal.z;
		}
		else {
			vertexNormal.x += normal[idx * 3];
			vertexNormal.y += normal[idx * 3 + 1];
			vertexNormal.z += normal[idx * 3 + 2];
			vertexNormal = glm::normalize(vertexNormal);
			normal[idx * 3] = vertexNormal.x;
			normal[idx * 3 + 1] = vertexNormal.y;
			normal[idx * 3 + 2] = vertexNormal.z;
		}*/
		normal[idx * 3] = vertexNormal.x;
		normal[idx * 3 + 1] = vertexNormal.y;
		normal[idx * 3 + 2] = vertexNormal.z;
		if (normal[idx * 3 + 2] < 0.0f) {
			normal[idx * 3] = -normal[idx * 3];
			normal[idx * 3 + 1] = -normal[idx * 3 + 1];
			normal[idx * 3 + 2] = -normal[idx * 3 + 2];
		}
	}
	void calculateNormal() {
		normal = new float[(long long)vertexLines * 3];
		//memset(normal, 0, sizeof(float) * vertexLines * 3);
		for (int i = 0; i < vertexLines * 3; ++i) {
			normal[i] = 0.0f;
		}
		for (unsigned int i = 0; i < indexLines; ++i) {
			glm::vec3 ab, ac;
			glm::vec3 vertexNormal;
			unsigned int aidx, bidx, cidx;
			aidx = index[i * 3] - 1;
			bidx = index[i * 3 + 1] - 1;
			cidx = index[i * 3 + 2] - 1;
			ab = calculateDiff(aidx, bidx);
			ac = calculateDiff(aidx, cidx);
			vertexNormal = glm::normalize(cross(ac, ab));
			setNormal(aidx, vertexNormal);
			setNormal(bidx, vertexNormal);
			setNormal(cidx, vertexNormal);
		}
	}
};

#endif // !MODEL_LOADER_H
