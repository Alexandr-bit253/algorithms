#include <iostream>


void merge(int* arr, int* left, int leftSize, int* right, int rightSize) {
	int i{ 0 }, j{ 0 }, k{ 0 };

	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			arr[k++] = left[i++];
		}
		else {
			arr[k++] = right[j++];
		}
	}

	while (i < leftSize) {
		arr[k++] = left[i++];
	}

	while (j < rightSize) {
		arr[k++] = right[j++];
	}
}


void mergeSort(int* arr, int size) {
	if (size <= 1) return;

	int mid = size / 2;

	int* left = new int[mid];
	int* right = new int[size - mid];

	for (size_t i = 0; i < mid; ++i) {
		left[i] = arr[i];
	}

	for (size_t i = mid; i < size; ++i) {
		right[i - mid] = arr[i];
	}

	mergeSort(left, mid);
	mergeSort(right, size - mid);

	merge(arr, left, mid, right, size - mid);

	delete[] left;
	delete[] right;
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
	mergeSort(arr, sizeArr);
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