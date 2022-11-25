#include "gi_date.h"
#include <iostream>

using namespace std;

void test(int day, int month, int year) {
	gi_date dt(day, month, year);
	if (dt.get_year() != year) {
		cout << "error: invalid year " << dt.get_year() << " instead of " << year << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_day() != day) {
		cout << "error: invalid day " << dt.get_day() << " instead of " << day << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_month() != month) {
		cout << "error: invalid month " << dt.get_month() << " instead of " << month << " for: " << day << "." << month << "." << year << endl;
	}
}

void test_prev_day(int day, int month, int year, int prev_day, int prev_month, int prev_year) {
	gi_date dt(day, month, year);
	dt.prev_day();
	if (dt.get_year() != prev_year) {
		cout << "error: invalid year " << dt.get_year() << " instead of " << prev_year << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_day() != prev_day) {
		cout << "error: invalid day " << dt.get_day() << " instead of " << prev_day << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_month() != prev_month) {
		cout << "error: invalid month " << dt.get_month() << " instead of " << prev_month << " for: " << day << "." << month << "." << year << endl;
	}
}

void test_next_day(int day, int month, int year, int next_day, int next_month, int next_year) {
	gi_date dt(day, month, year);
	dt.next_day();
	if (dt.get_year() != next_year) {
		cout << "error: invalid year " << dt.get_year() << " instead of " << next_year << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_day() != next_day) {
		cout << "error: invalid day " << dt.get_day() << " instead of " << next_day << " for: " << day << "." << month << "." << year << endl;
	}
	if (dt.get_month() != next_month) {
		cout << "error: invalid month " << dt.get_month() << " instead of " << next_month << " for: " << day << "." << month << "." << year << endl;
	}
}


int main()
{

	test_next_day(1, 1, 2020, 2, 1, 2020);
	test_next_day(31, 1, 2020, 1, 2, 2020);
	test_next_day(28, 2, 2020, 29, 2, 2020);
	test_next_day(29, 2, 2020, 1, 3, 2020);
	test_next_day(31, 12, 2020, 1, 1, 2021);
	test_next_day(28, 2, 2021, 1, 3, 2021);
	test_next_day(24, 3, 2021, 25, 3, 2021);
	test_next_day(31, 3, 2021, 1, 4, 2021);
	test_next_day(5, 11, 2021, 6, 11, 2021);
	test_next_day(30, 11, 2021, 1, 12, 2021);
	test_next_day(31, 12, 2021, 1, 1, 2022);
	test_next_day(31, 12, 2022, 1, 1, 2023);
	test_next_day(24, 3, 2023, 25, 3, 2023);
	test_next_day(31, 3, 2023, 1, 4, 2023);
	test_next_day(5, 11, 2023, 6, 11, 2023);
	test_next_day(30, 11, 2023, 1, 12, 2023);
	test_next_day(31, 12, 2023, 31, 12, 2023);
	test_prev_day(1, 1, 2020, 1, 1, 2020);
	test_prev_day(31, 1, 2020, 30, 1, 2020);
	test_prev_day(1, 2, 2020, 31, 1, 2020);
	test_prev_day(28, 2, 2020, 27, 2, 2020);
	test_prev_day(29, 2, 2020, 28, 2, 2020);
	test_prev_day(1, 3, 2020, 29, 2, 2020);
	test_prev_day(12, 12, 2020, 11, 12, 2020);
	test_prev_day(1, 1, 2021, 31, 12, 2020);
	test_prev_day(1, 3, 2021, 28, 2, 2021);
	test_prev_day(25, 3, 2021, 24, 3, 2021);
	test_prev_day(1, 4, 2021, 31, 3, 2021);
	test_prev_day(6, 11, 2021, 5, 11, 2021);
	test_prev_day(1, 12, 2021, 30, 11, 2021);
	test_prev_day(1, 1, 2022, 31, 12, 2021);
	test_prev_day(1, 1, 2023, 31, 12, 2022);
	test_prev_day(25, 3, 2023, 24, 3, 2023);
	test_prev_day(1, 4, 2023, 31, 3, 2023);
	test_prev_day(6, 11, 2023, 5, 11, 2023);
	test_prev_day(1, 12, 2023, 30, 11, 2023);
	test_prev_day(31, 12, 2023, 30, 12, 2023);


	test(1, 1, 2020);
	test(1, 2, 2020);
	test(1, 3, 2020);
	test(1, 4, 2020);
	test(1, 5, 2020);
	test(1, 6, 2020);
	test(1, 7, 2020);
	test(1, 1, 2020);
	test(1, 2, 2020);
	test(1, 3, 2020);
	test(1, 4, 2020);
	test(1, 5, 2020);
	test(1, 6, 2020);
	test(1, 7, 2020);
	test(1, 8, 2020);
	test(1, 9, 2020);
	test(1, 10, 2020);
	test(1, 11, 2020);
	test(1, 12, 2020);
	test(2, 1, 2020);
	test(2, 2, 2020);
	test(2, 3, 2020);
	test(2, 4, 2020);
	test(2, 5, 2020);
	test(2, 6, 2020);
	test(2, 7, 2020);
	test(2, 8, 2020);
	test(2, 9, 2020);
	test(2, 10, 2020);
	test(2, 11, 2020);
	test(2, 12, 2020);
	test(28, 2, 2020);
	test(29, 2, 2020);
	test(1, 3, 2020);
	test(1, 4, 2020);
	test(1, 5, 2020);
	test(1, 6, 2020);
	test(1, 7, 2020);
	test(1, 8, 2020);
	test(1, 9, 2020);
	test(1, 10, 2020);
	test(1, 11, 2020);
	test(1, 12, 2020);
	test(2, 1, 2020);
	test(2, 2, 2020);
	test(2, 3, 2020);
	test(2, 4, 2020);
	test(2, 5, 2020);
	test(2, 6, 2020);
	test(2, 7, 2020);
	test(2, 8, 2020);
	test(2, 9, 2020);
	test(2, 10, 2020);
	test(2, 11, 2020);
	test(2, 12, 2020);
	test(30, 12, 2020);
	test(31, 12, 2020);
	test(1, 1, 2021);
	test(1, 2, 2021);
	test(3, 2, 2021);
	test(28, 2, 2021);
	test(1, 3, 2021);
	test(1, 4, 2021);
	test(1, 5, 2021);
	test(1, 6, 2021);
	test(1, 7, 2021);
	test(1, 8, 2021);
	test(1, 9, 2021);
	test(1, 10, 2021);
	test(1, 11, 2021);
	test(1, 12, 2021);
	test(2, 1, 2021);
	test(2, 2, 2021);
	test(2, 3, 2021);
	test(2, 4, 2021);
	test(2, 5, 2021);
	test(2, 6, 2021);
	test(2, 7, 2021);
	test(2, 8, 2021);
	test(2, 9, 2021);
	test(2, 10, 2021);
	test(2, 11, 2021);
	test(2, 12, 2021);
	test(30, 12, 2021);
	test(31, 12, 2021);
	test(1, 1, 2022);
	test(1, 2, 2022);
	test(1, 3, 2022);
	test(1, 4, 2022);
	test(1, 5, 2022);
	test(1, 6, 2022);
	test(1, 7, 2022);
	test(1, 8, 2022);
	test(1, 9, 2022);
	test(1, 10, 2022);
	test(1, 11, 2022);
	test(1, 12, 2022);
	test(2, 1, 2022);
	test(2, 2, 2022);
	test(2, 3, 2022);
	test(2, 4, 2022);
	test(2, 5, 2022);
	test(2, 6, 2022);
	test(2, 7, 2022);
	test(2, 8, 2022);
	test(2, 9, 2022);
	test(2, 10, 2022);
	test(2, 11, 2022);
	test(2, 12, 2022);
	test(30, 12, 2022);
	test(31, 12, 2022);
	test(1, 1, 2023);
	test(1, 2, 2023);
	test(15, 2, 2023);
	test(28, 2, 2023);
	test(1, 3, 2023);
	test(1, 4, 2023);
	test(1, 5, 2023);
	test(1, 6, 2023);
	test(30, 12, 2023);
	test(31, 12, 2023);


    cout << "End of tests." << endl;
    return 0;
}
