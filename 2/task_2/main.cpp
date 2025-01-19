#include <iostream>
#include <vector>


int fibonachi(int number, std::vector<int>& cache) {
	if (cache[number] != -1) {
		return cache[number];
	}

	cache[number] = fibonachi(number - 1, cache) + fibonachi(number - 2, cache);
	return cache[number];
}


int main() {
	setlocale(LC_ALL, "rus");

	int number{};

	std::cout << "������� ����� ����� ��������: ";
	while (!(std::cin >> number) || number <= 0) {
		std::cout << "������������ ����. ����������, ������� ������������� ����� �����: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
	}

	std::vector<int> cache(number + 1, -1);
	cache[0] = 0;
	cache[1] = 1;

	std::cout << "����� ��������: " << fibonachi(number, cache) << std::endl;
}