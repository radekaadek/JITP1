// Przesylam zadanie ponownie

#include <iostream>

using std::cout;
using std::cin;

int main() {
	double centimeters;
	cout << "Podaj dlugosc w cm: ";
	cin >> centimeters;
	//int inches = static_cast<int>(0.393701 * centimeters + 0.5);
	double inches_db = 0.393701 * centimeters;
	int inches_int = static_cast<int>(inches_db);
	if (inches_db - inches_int >= 0.5) {
		inches_int++;
	}

	
	int feet = inches_int / 12;
	inches_int = inches_int % 12;
	int yards = feet / 3;
	feet = feet % 3;
	cout << "Na dana dlugosc sklada sie: " << "\n";
	cout << yards << " jardow " << feet << " stop " << inches_int << " cali" << "\n";
	return 0;
}
