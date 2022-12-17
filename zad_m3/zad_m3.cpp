#include <iostream>

using namespace std;

const double gram_to_ounce = 0.0352739619;
const int ounces_in_pound = 16;
const int pounds_in_stone = 14;

int main() {
	int grams;
	cout << "Waga w gramach: ";
	cin >> grams;
	int ounces = grams * gram_to_ounce + 0.5;
	int pounds = ounces / ounces_in_pound;
	ounces = ounces % ounces_in_pound;
	int stones = pounds / pounds_in_stone;
	pounds = pounds % pounds_in_stone;
	if (ounces) cout << "uncje: " << ounces << " ";
	if (pounds) cout << "funty: " << pounds << " ";
	if (stones) cout << "kamienie: " << stones << " ";
	if (ounces + pounds + stones) cout << "uncje: 0";
	return 0;
}
