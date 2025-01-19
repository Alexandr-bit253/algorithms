#include <iostream>
/*
��������� �� �������: O(2^n)
	�.�. ������ ����� ������� ������ ����� ���� ������.
��������� �� ������: O(n)
	�.�. ������� ������������ ����� ��������������� �������� �������� `number`,
	�������� ������ ����� ����������� � ����� �� ���������� �����������
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

	std::cout << "������� ����� ����� ��������: ";
	while (!(std::cin >> number) || number <= 0) {
		std::cout << "������������ ����. ����������, ������� ������������� ����� �����: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "����� ��������: " << fibonachi(number) << std::endl;
}