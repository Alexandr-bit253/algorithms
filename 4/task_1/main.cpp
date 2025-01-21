#include <iostream>


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	std::cout << "������������ ������:";
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
		std::cout << "������� arr[" << i << "]: ";
		std::cin >> arr[i];
	}
}


int main() {
	setlocale(LC_ALL, "rus");

	int actual_size{}, logical_size{};

	while (true) {
		std::cout << "������� ����������� ������ �������: ";
		std::cin >> actual_size;

		std::cout << "������� ���������� ������ �������: ";
		std::cin >> logical_size;

		if (logical_size > actual_size) {
			std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!" 
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