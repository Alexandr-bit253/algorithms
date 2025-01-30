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
	std::println();
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
}


int main() {
	setlocale(LC_ALL, "rus");

	int size1{ 6 }, size2{ 8 }, size3{ 10 };

	int* arr1 = new int[size1] { 1, 3, 6, 5, 9, 8 };
	int* arr2 = new int[size2] { 94, 67, 18, 44, 55, 12, 6, 42 };
	int* arr3 = new int[size3] { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	print_pyramid(arr1, size1);
	print_pyramid(arr2, size2);
	print_pyramid(arr3, size3);

	return 0;
}