#include <filesystem>
#include <iostream>
#include <fstream>


const std::string FILE_PATH {"../input.txt"};


int main() {
    std::ifstream inputFile{FILE_PATH};

    if (!inputFile.is_open()) {
        std::cout << "Cannot open file: " << std::filesystem::absolute(FILE_PATH) << std::endl;
        return 1;
    }

    int n{};
    inputFile >> n;

    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();

    std::cout << "Текстовый вид орграфа:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << ": ";
        bool hasEdge{false};

        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if(hasEdge) std::cout << " ";
                std::cout << j + 1;
                hasEdge = true;
            }
        }

        if (!hasEdge) std::cout << "нет";

        std::cout << std::endl;
    }

    return 0;
}
