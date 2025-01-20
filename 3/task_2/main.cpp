#include <iostream>


int pivoting(int* arr, int pi, int size) {
	int left{ 0 }, right{ size - 1 }, pivot{ arr[pi] };

	std::swap(arr[pi], arr[right]);
	right--;

	while (true) {
		while (arr[left] < pivot) {
			left++;
		}

		while (arr[right] > pivot) {
			right--;
		}

		if (left >= right) return right;

		std::swap(arr[left], arr[right]);

		left++;
		right--;
	}
}


void quickSort(int* arr, int size) {
	if (size <= 1) return;

	int pi = rand() % size;

	int border = pivoting(arr, pi, size);

	quickSort(arr, border + 1);
	quickSort(arr + border + 1, size - border - 1);
}


void printArr(int* arr, int sizeArr) {
	for (size_t i = 0; i < sizeArr; ++i) {
		std::cout << " " << arr[i];
	}
}


void sortArr(int* arr, int sizeArr) {
	std::cout << "Исходный массив:";
	printArr(arr, sizeArr);
	std::cout << std::endl;
	quickSort(arr, sizeArr);
	std::cout << "Отсортированный массив:";
	printArr(arr, sizeArr);
	std::cout << std::endl << std::endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	sortArr(arr1, sizeof(arr1) / sizeof(arr1[0]));
	sortArr(arr2, sizeof(arr2) / sizeof(arr2[0]));
	sortArr(arr3, sizeof(arr3) / sizeof(arr3[0]));
}