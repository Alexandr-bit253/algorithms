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


void dfs(int** matrix, const int& n, const int& v, int* cids, const int& cid) {
	cids[v] = cid;
	for (int j = 0; j < n; ++j) {
		if (matrix[v][j] == 1 && cids[j] == 0) {
			dfs(matrix, n, j, cids, cid);
		}
	}
}


void components(int** matrix, const int& n) {
	int* cids = new int[n] {0};
	int cid{ 0 };
	

	for (int v = 0; v < n; ++v) {
		if (cids[v] == 0) {
			++cid;
			dfs(matrix, n, v, cids, cid);
		}
	}

	std::cout << "Принадлежность вершин компонентам связности:" << std::endl;

	for (int i = 0; i < n; ++i) {
		std::cout << i + 1 << " - " << cids[i] << std::endl;
	}

	std::cout << "Количество компонентов связности в графе: " << cid << std::endl;

	delete[] cids;
}


int main() {
	setlocale(LC_ALL, "rus");

	int n{}, first{};
	int** matrix = readFile(FILE_PATH, n);
	if (!matrix) return 1;

	components(matrix, n);

	freeMatrix(matrix, n);

	std::cout << std::endl;

	return 0;
}