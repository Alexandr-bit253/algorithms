#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


const std::string FILE_PATH{"../input.txt"};


void dfs(const std::vector<std::vector<int>>& matrix,const size_t& vertex, std::vector<bool>& visited, std::stack<size_t>& order) {
    visited[vertex] = true;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if(matrix[vertex][i] == 1 && !visited[i]) {
            dfs(matrix, i, visited, order);
        }
    }
    order.push(vertex);
}


std::vector<int> topSort(const std::vector<std::vector<int>>& matrix) {
    std::stack<size_t> order{};
    std::vector<bool> visited(matrix.size(), false);

    for (size_t v = 0; v < matrix.size(); ++v) {
        if(!visited[v]) {
            dfs(matrix, v, visited, order);
        }
    }

    std::vector<int> result{};
    while (!order.empty()) {
        result.push_back(order.top() + 1);
        order.pop();
    }

    return result;
}


int main()
{
    std::ifstream inputFile{FILE_PATH};
    if(!inputFile.is_open()) {
        std::cout << "Cannot open file: " << std::filesystem::absolute(FILE_PATH) << std::endl;
        return 1;
    }

    int n{};
    inputFile >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();

    std::vector<int> order = topSort(matrix);

    std::cout << "Топологический порядок вершин: ";
    for(const int v : order) {
        std:: cout << v << " ";
    }

    std::cout << std::endl;

    return 0;
}
