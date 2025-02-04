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


void bfs(int** matrix, int& n, int& start) {

	bool* visited = new bool[n] {false};
	std::queue<int> queue{};

	queue.push(start);
	visited[start] = true;

	std::cout << "Порядок обхода вершин:";

	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop();

		std::cout << " " << vertex + 1;

		for (int j = 0; j < n; ++j) {
			if (matrix[vertex][j] == 1 && !visited[j]) {
				queue.push(j);
				visited[j] = true;
			}
		}
	}

	delete[] visited;
}


int main() {
	setlocale(LC_ALL, "rus");

	int n{}, first{};
	int** matrix = readFile(FILE_PATH, n);
	if (!matrix) return 1;

	while (true) {
		std::cout << "В графе " << n << " вершин.Введите номер вершины, с которой начнётся обход: ";
		std::cin >> first;

		if (first > 0 && first <= n) {
			break;
		}
		std::cout << "Неверный ввод. Пожалуйста, попробуйте снова.\n";
	}

	bfs(matrix, n, --first);

	freeMatrix(matrix, n);

	return 0;
}