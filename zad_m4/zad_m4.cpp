// Radoslaw Dabkowski (325683)

#include <iostream>

using std::cout;

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
		return static_cast<char>(value - 10 + 'A');
	else return 'x';
}

bool test_pentadecimal2int(char digit, int value) {
	int result = pentadecimal2int(digit);
	if (result == value) return true;
	else {
		cout << "Test failed for pentadecimal2int(" << digit << ") = " << value << " (got " << result << ")" << "\n";
		return false;
	}
}

bool test_int2pentadecimal(int value, char digit) {
	char result = int2pentadecimal(value);
	if (result == digit) return true;
	else {
		cout << "Test failed for int2pentadecimal(" << value << ") = " << digit << " (got " << result << ")" << "\n";
		return false;
	}
}


int main()
{
	{
		cout << "Testing pentadecimal2int ..." << "\n";

		uint8_t no_pent2int_tests = 13;
		const char* test_pent2int_input = "/09:@AEF`aefg";
		const int8_t test_pent2int_output[13] { -1, 0, 9, -1, -1, 10, 14, -1, -1, 10, 14, -1, -1 };
		bool all_tests_passed = true;

		for (auto i = decltype(no_pent2int_tests){0}; i < no_pent2int_tests; ++i) {
			if (!test_pentadecimal2int(test_pent2int_input[i], test_pent2int_output[i]))
				all_tests_passed = false;
		}

		if (all_tests_passed) cout << "All tests for pentadecimal2int passed :)" << "\n\n";
		else cout << "Some tests for pentadecimal2int failed :(" << "\n\n";
	}
	
	{
		cout << "Testing int2pentadecimal ..." << "\n";

		const uint8_t no_int2pent_tests = 10;
		const int16_t test_int2pen_input[no_int2pent_tests] { -21, -2, -1, 0, 9, 10, 14, 15, 16, 17 };
		const char* test_int2pen_output = "xxx09AExxx";
		bool all_tests_passed = true;

		for (auto i = decltype(no_int2pent_tests){0}; i < no_int2pent_tests; ++i) {
			if (!test_int2pentadecimal(test_int2pen_input[i], test_int2pen_output[i]))
				all_tests_passed = false;
		}

		if (all_tests_passed) cout << "All tests for int2pentadecimal passed :)" << "\n";
		else cout << "Some tests for int2pentadecimal failed :(" << "\n";
	}
}