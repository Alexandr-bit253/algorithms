#include <iostream>
#include <cmath>
#include <print>


uint64_t simpleStringHash(const std::string& s) {
	uint64_t result{ 0 };

	for (size_t i = 0; i < s.size(); ++i) {
		result += s[i];
	}

	return result;
}

int findSubstringLightRabinKapr(std::string& str, std::string& subStr) {
	size_t strSize = str.size();
	size_t subStrSize = subStr.size();

	uint64_t subStrHash = simpleStringHash(subStr);
	uint64_t strHash = simpleStringHash(str.substr(0, subStrSize));
	

	for (size_t i = 0; i < str.size(); ++i) {
		if (strHash == subStrHash) {
			if (str.substr(i, subStrSize) == subStr) {
				return i;
			}
		}

		if (i < strSize - subStrSize) {
			strHash -= str[i];
			strHash += str[i + subStrSize];
		}
	}

	return -1;
}


int main() {
	setlocale(LC_ALL, "rus");

	std::string str{}, subStr{};

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> str;

	while (true) {

		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> subStr;
		
		int result = findSubstringLightRabinKapr(str, subStr);

		if (result == -1) {
			std::cout << "Подстрока " << subStr << " не найдена" << std::endl;
		}
		else {
			std::cout << "Подстрока " << subStr << " найдена по индексу " << result << std::endl;
		}

		if (subStr == "exit")
			break;
	}

	return 0;
}