#include <iostream>
#include <cmath>
#include <print>


uint64_t simpleStringHash(std::string& s, int& p, int& n) {
	uint64_t result{ 0 };

	for (size_t i = 0; i < s.size(); ++i) {
		result += s[i] * static_cast<uint64_t>(std::pow(p, i));
	}

	return result % n;
}


int main() {
	setlocale(LC_ALL, "rus");

	std::string s{};
	int p{}, n{};

	std::print("Введите p: ");
	std::cin >> p;

	std::print("Введите n: ");
	std::cin >> n;

	while (true) {
		std::print("Введите строку: ");
		std::cin >> s;

		std::cout << "Хэш строки " << s << " = " << simpleStringHash(s, p, n) << std::endl;

		if (s == "exit")
			break;
	}

	return 0;
}