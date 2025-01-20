#include <iostream>


void countSort(int* arr, int size) {
	const int MIN_VALUE{ 10 };
	const int MAX_VALUE{ 24 };

	int count[MAX_VALUE - MIN_VALUE + 1] = { 0 };

	for (int i = 0; i < size; ++i) {
		count[arr[i] - MIN_VALUE]++;
	}

	int index{ 0 };
	for (int i = 0; i < MAX_VALUE - MIN_VALUE + 1; ++i) {
		while (count[i] > 0) {
			arr[index++] = i + MIN_VALUE;
			count[i]--;
		}
	}

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
	countSort(arr, sizeArr);
	std::cout << "Отсортированный массив:";
	printArr(arr, sizeArr);
	std::cout << std::endl << std::endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 
		16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17, };
	int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 
		21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 
		16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

	sortArr(arr1, sizeof(arr1) / sizeof(arr1[0]));
	sortArr(arr2, sizeof(arr2) / sizeof(arr2[0]));
	sortArr(arr3, sizeof(arr3) / sizeof(arr3[0]));

}