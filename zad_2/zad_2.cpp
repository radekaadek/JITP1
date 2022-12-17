#include <iostream>
#include "simpleDate.h"


int main() {

	simpleDate dt1(23, 2, 2021);
	simpleDate dt2(24, 2, 2021);
	if (dt1 != dt2){
		std::cout << dt1;
	}



	// test is_leap_year
	test_is_leap_year(2020, true);
	test_is_leap_year(2021, false);
	test_is_leap_year(2022, false);
	test_is_leap_year(2023, false);
	test_is_leap_year(2000, true);
	test_is_leap_year(1900, false);
	test_is_leap_year(1800, false);
	test_is_leap_year(1700, false);
	test_is_leap_year(1600, true);
	test_is_leap_year(1500, false);
	test_is_leap_year(1400, false);
	test_is_leap_year(1300, false);
	test_is_leap_year(1200, true);
	test_is_leap_year(1100, false);
	test_is_leap_year(1000, false);
	test_is_leap_year(900, false);
	test_is_leap_year(800, true);
	test_is_leap_year(700, false);
	test_is_leap_year(600, false);
	test_is_leap_year(500, false);
	test_is_leap_year(400, true);
	test_is_leap_year(300, false);
	test_is_leap_year(200, false);
	test_is_leap_year(100, false);
	// test days_in_month
	test_days_in_month(1, 2020, 31);
	test_days_in_month(2, 2020, 29);
	test_days_in_month(2, 2021, 28);
	test_days_in_month(3, 2020, 31);
	test_days_in_month(3, 2021, 31);
	test_days_in_month(4, 2020, 30);
	test_days_in_month(4, 2021, 30);
	test_days_in_month(5, 2020, 31);
	test_days_in_month(5, 2021, 31);
	test_days_in_month(6, 2020, 30);
	test_days_in_month(6, 2021, 30);
	test_days_in_month(7, 2020, 31);
	test_days_in_month(7, 2021, 31);
	test_days_in_month(8, 2020, 31);
	test_days_in_month(8, 2021, 31);
	test_days_in_month(9, 2020, 30);
	test_days_in_month(9, 2021, 30);
	test_days_in_month(10, 2020, 31);
	test_days_in_month(10, 2021, 31);
	test_days_in_month(11, 2020, 30);
	test_days_in_month(11, 2021, 30);
	test_days_in_month(12, 2020, 31);
	test_days_in_month(12, 2021, 31);
	// test is_valid
	test_is_valid(1, 1, 2020, true);
	test_is_valid(31, 1, 2020, true);
	test_is_valid(29, 2, 2020, true);
	test_is_valid(28, 2, 2020, true);
	test_is_valid(28, 2, 2021, true);
	test_is_valid(31, 3, 2020, true);
	test_is_valid(30, 4, 2020, true);
	test_is_valid(31, 5, 2020, true);
	test_is_valid(30, 6, 2020, true);
	test_is_valid(31, 7, 2020, true);
	test_is_valid(31, 8, 2020, true);
	test_is_valid(30, 9, 2020, true);
	test_is_valid(31, 10, 2020, true);
	test_is_valid(30, 11, 2020, true);
	test_is_valid(31, 12, 2020, true);
	test_is_valid(32, 1, 2020, false);
	test_is_valid(29, 2, 2021, false);
	test_is_valid(32, 3, 2020, false);
	test_is_valid(31, 4, 2020, false);
	test_is_valid(32, 5, 2020, false);
	test_is_valid(31, 6, 2020, false);
	test_is_valid(32, 7, 2020, false);
	test_is_valid(32, 8, 2020, false);
	test_is_valid(31, 9, 2020, false);
	test_is_valid(32, 10, 2020, false);
	test_is_valid(31, 11, 2020, false);
	test_is_valid(32, 12, 2020, false);
	return 0;
	
}
