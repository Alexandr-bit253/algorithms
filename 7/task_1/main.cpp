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
}


int main() {
	int n{};
	int** matrix = readFile(FILE_PATH, n);

	return 0;
}