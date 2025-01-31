#include <iostream>
#include <print>


void print_array(int*& arr, int& size_arr) {
	std::print("Исходный массив:");
	for (int i = 0; i < size_arr; ++i) {
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;
}


void print_pyramid(int*& arr, int& size_arr) {
	print_array(arr, size_arr);

	std::println("Пирамида:");

	std::println("0 root {}", arr[0]);

	for (int i = 0; i < size_arr; ++i) {
		int left_i{ 2 * i + 1 }, right_i{ 2 * i + 2 };
		int level{ 0 }, parent{ i };

		while (parent > 0) {
			parent = (parent - 1) / 2;
			level++;
		}

		if (left_i < size_arr) {
			std::println("{} left({}) {}", level + 1, arr[i], arr[left_i]);
		}
		if (right_i < size_arr) {
			std::println("{} right({}) {}", level + 1, arr[i], arr[right_i]);
		}
	}

	std::println();
}


class PyramidNavigator {
private:
	int* pyramid;
	int size{}, currentIndex{ 0 };


	void printArray() {
		std::print("Исходный массив:");
		for (int i = 0; i < size; ++i) {
			std::cout << " " << pyramid[i];
		}
		std::cout << std::endl;
	}


	void printPyramid() {
		std::println("Пирамида:");
		for (int i = 0; i < size; ++i) {
			int level{ 0 }, index{ i };
			while (index > 0) {
				index = (index - 1) / 2;
				level++;
			}

			if (i == 0) {
				std::println("{} root {}", level, pyramid[i]);
			}
			else {
				int parentIndex = (i - 1) / 2;
				std::string position = (i % 2 == 1) ? "left" : "right";
				std::println("{} {}({}) {}", level, position, pyramid[parentIndex], pyramid[i]);
			}
		}
	}


	void printCurrentPosition() {
		int level{ 0 }, index{ currentIndex };
		while (index > 0) {
			index = (index - 1) / 2;
			level++;
		}

		std::cout << "Вы находитесь здесь: " << level;
		if (currentIndex == 0)
			std::cout << " root ";
		else
			std::cout << " " << ((currentIndex % 2 == 1) ? "left" : "right") << "(" << pyramid[(currentIndex - 1) / 2] << ") ";
		std::cout << pyramid[currentIndex] << std::endl;
	}


public:
	PyramidNavigator(int arr[], int n) : pyramid(arr), size(n) {}


	void navigate() {
		printArray();
		printPyramid();
		printCurrentPosition();

		std::string command;
		
		while (true) {
			std::cout << "Введите команду: ";
			std::cin >> command;

			if (command == "exit") {
				break;
			}
			else if (command == "up") {
				if (currentIndex == 0)
					std::println("Ошибка! Отсутствует родитель");
				else {
					currentIndex = (currentIndex - 1) / 2;
					std::println("Ok");
				}
			}
			else if (command == "left") {
				int leftIndex = 2 * currentIndex + 1;
				if (leftIndex >= size) {
					std::println("Ошибка! Отсутствует левый потомок");
				}
				else {
					currentIndex = leftIndex;
					std::println("Ok");
				}
			}
			else if (command == "right") {
				int rightIndex = 2 * currentIndex + 2;
				if (rightIndex >= size) {
					std::println("Ошибка! Отсутствует правый  потомок");
				}
				else {
					currentIndex = rightIndex;
					std::println("Ok");
				}
			}
			else {
				std::println("Ошибка! Неизвестная команда");
			}
			printCurrentPosition();
		}

		std::println();
	}
};


int main() {
	setlocale(LC_ALL, "rus");

	int size1{ 6 }, size2{ 8 }, size3{ 10 };

	int* arr1 = new int[size1] { 1, 3, 6, 5, 9, 8 };
	int* arr2 = new int[size2] { 94, 67, 18, 44, 55, 12, 6, 42 };
	int* arr3 = new int[size3] { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	PyramidNavigator navigator1(arr1, size1);
	PyramidNavigator navigator2(arr2, size2);
	PyramidNavigator navigator3(arr3, size3);

	navigator1.navigate();
	navigator2.navigate();
	navigator3.navigate();

	return 0;
}