#include <string>


int pentadecimal2int(char digit) {
	if ('0' <= digit && digit <= '9')
		return static_cast<int>(digit - '0');
	else if ('A' <= digit && digit <= 'E')
		return static_cast<int>(digit - 'A' + 10);
	else if ('a' <= digit && digit <= 'e')
		return static_cast<int>(digit - 'a' + 10);
	else return -1;
}

char int2pentadecimal(int value) {
	if (0 <= value && value <= 9)
		return static_cast<char>(value + '0');
	else if (value >= 10 && value <= 14)
		return static_cast<char>(value - 10 + 'a');
	else return 'x';
}


int penta2int(const std::string& number) {
	if (number.empty()) {
		return -1;
	}
	int result = 0;
	for (char digit : number) {
		int value = pentadecimal2int(digit);
		if (value == -1) return -1;
		if (result > (INT32_MAX - value) / 15) return -1;
		result = result * 15 + value;
	}
	return result;
}


std::string int2penta(int value) {
	if (value < 0) return "x";
	std::string result = "";
	do {
		result = int2pentadecimal(value % 15) + result;
		value /= 15;
	} while (value > 0);
	return result;
}
