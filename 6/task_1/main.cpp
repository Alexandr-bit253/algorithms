#include <iostream>
#include <print>


int simpleStringHash(std::string& s) {
	int result{ 0 };

	for (auto letter : s) {
		result += letter;
	}

	return result;
}


int main() {
	setlocale(LC_ALL, "rus");

	std::string s{};

	while (true) {
		std::print("Введите строку: ");
		std::cin >> s;

		std::println("Наивный хэш строки {} = {}", s, simpleStringHash(s));

		if (s == "exit")
			break;
	}

	return 0;
}