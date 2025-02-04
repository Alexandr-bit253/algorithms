#include <iostream>
#include <fstream>


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


void dfs(int** matrix, int& vertex, bool* visited, int& n) {
	std::cout << vertex + 1 << " ";
	visited[vertex] = true;

	for (int v = 0; v < n; ++v) {
		if (matrix[vertex][v] == 1 && !visited[v]) {
			dfs(matrix, v, visited, n);
		}
	}
}


void dfs(int** matrix, int& n) {
	bool* visited = new bool[n] {false};
	std::cout << "Порядок обхода вершин: ";

	for (int v = 0; v < n; ++v) {
		if (!visited[v]) {
			dfs(matrix, v, visited, n);
		}
	}

	delete[] visited;
}


int main() {
	setlocale(LC_ALL, "rus");

	int n{};
	int** matrix = readFile(FILE_PATH, n);
	if (!matrix) return 1;

	dfs(matrix, n);

	freeMatrix(matrix, n);

	return 0;
}