#include <iostream>
/*
Сложность по времени: O(2^n)
	т.к. каждый вызов функции делает вызов двух других.
Сложность по памяти: O(n)
	т.к. глубина рекурсивного стека пропорциональна входному значению `number`,
	птомучто каждый вызов сохраняется в стеке до завершения предыдущего
*/

int fibonachi(int number) {
	if (number == 1 || number == 2) {
		return 1;
	}
	
	return fibonachi(number - 1) + fibonachi(number - 2);
}


int main() {
	setlocale(LC_ALL, "rus");

	int number{};

	std::cout << "Введите номер числа Фибоначи: ";
	while (!(std::cin >> number) || number <= 0) {
		std::cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "Число Фибаначи: " << fibonachi(number) << std::endl;
}