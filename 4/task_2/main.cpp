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
	std::cout << std::endl;
}


void fill_dynamic_array(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < logical_size; ++i) {
		std::cout << "¬ведите arr[" << i << "]: ";
		std::cin >> arr[i];
	}
}


void append_to_dynamic_array(int*& arr, int added, int& logical_size, int& actual_size) {
	if (logical_size < actual_size) {
		arr[logical_size] = added;
		logical_size++;
	}
	else {
		actual_size = (actual_size == 0) ? 1 : actual_size * 2;
		int* new_array = new int[actual_size];

		for (int i = 0; i < logical_size; i++) {
			new_array[i] = arr[i];
		}

		new_array[logical_size] = added;
		logical_size++;

		delete[] arr;
		arr = new_array;
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	int actual_size{}, logical_size{}, added{};

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

	while (true) {
		std::cout << "¬ведите элемент дл€ добавлени€: ";
		std::cin >> added;

		if (added == 0) {
			break;
		}

		append_to_dynamic_array(arr, added, logical_size, actual_size);
		print_dynamic_array(arr, logical_size, actual_size);
	}

	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;

	return 0;
}