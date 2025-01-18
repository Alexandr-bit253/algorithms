#include <iostream>


static int countGreaterThan(const int* arr, const int sizeArr, const int point) {
	int left{ 0 }, right{ sizeArr - 1 }, middle{};

	while (left <= right) {
		middle = (left + right) / 2;
		if (arr[middle] > point) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}

	return sizeArr - left;
}


int main() {
	setlocale(LC_ALL, "rus");

	const int arr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	const int sizeArr = sizeof(arr) / sizeof(arr[0]);
	int point{};

	while (true) {
		std::cout << "Введите точку отсчёта: ";
		std::cin >> point;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: пожалуйста, введите целое число." << std::endl;
		}
		else {
			break;
		}
	}
	

	std::cout << "Количество элементов в массиве больших, чем " << point << ": "
		<< countGreaterThan(arr, sizeArr, point) << std::endl;

	return 0;
}