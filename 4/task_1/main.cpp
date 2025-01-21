#include <iostream>


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	std::cout << "ƒинамический массив:";
	for (int i = 0; i < actual_size; ++i) {
		if (i > logical_size - 1) {
			std::cout << " _";
		}
		else {
			std::cout << " " << arr[i];
		}
	}
}


void fill_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < logical_size; ++i) {
		std::cout << "¬ведите arr[" << i << "]: ";
		std::cin >> arr[i];
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	int actual_size{}, logical_size{};

	while (true) {
		std::cout << "¬ведите фактический размер массива: ";
		std::cin >> actual_size;

		std::cout << "¬ведите логический размер массива: ";
		std::cin >> logical_size;

		if (logical_size > actual_size) {
			std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" 
				<< std::endl;
			continue;
		}

		break;
	}

	int* arr = new int[actual_size] {0};

	fill_dynamic_array(arr, logical_size, actual_size);

	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;

	return 0;
}