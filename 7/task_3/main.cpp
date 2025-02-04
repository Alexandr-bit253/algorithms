#include <iostream>
#include <fstream>
#include <queue>


const std::string FILE_PATH{ "input.txt" };


int** readFile(const std::string& path, int& n) {
	std::ifstream fin(path);
	if (!fin) {
		std::cerr << "Cannot read file " << FILE_PATH << std::endl;
		return nullptr;
	}

	fin >> n;

	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> matrix[i][j];
		}
	}

	fin.close();

	return matrix;
}


void freeMatrix(int** matrix, int& n) {
	for (int i = 0; i < n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}


bool dfs(int** matrix, const int& n, const int& vertex, const int& prev, bool* visited) {
	visited[vertex] = true;

	for (int j = 0; j < n; ++j) {
		if (matrix[vertex][j]) {
			if (!visited[j]) {
				if (dfs(matrix, n, j, vertex, visited)) {
					return true;
				}
			}
			else if (j != prev) {
				return true;
			}
		}
	}

	return false;
}


bool isCyclic(int** matrix, const int& n) {
	bool* visited = new bool[n] {false};

	for (int v = 0; v < n; ++v) {
		if (!visited[v]) {
			if (dfs(matrix, n, v, -1, visited)) {
				delete[] visited;
				return true;
			}
		}
	}

	delete[] visited;

	return false;
}


int main() {
	setlocale(LC_ALL, "rus");

	int n{}, first{};
	int** matrix = readFile(FILE_PATH, n);
	if (!matrix) return 1;

	isCyclic(matrix, n) == true ? std::cout << "В графе есть цикл!" : std::cout << "В графе нет циклов";

	freeMatrix(matrix, n);

	std::cout << std::endl;

	return 0;
}