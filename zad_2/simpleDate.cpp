// Radoslaw Dabkowski (325683)
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "simpleDate.h"

const std::vector<int> simpleDate::days_in_months
= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool simpleDate::is_leap_year(int year) {
	if (year < 1) {
		throw std::invalid_argument("Year cannot be negative or zero");
	}
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool test_is_leap_year(int year, bool expected)
{
	if (simpleDate::is_leap_year(year) != expected)
	{
		std::cout << "Error in is_leap_year(" << year << ")\n";
		return false;
	}
	return true;

}

int simpleDate::days_in_month(int month, int year) {
	if (month < 1 || month > 12) {
		throw std::invalid_argument("Month must be between 1 and 12");
	}
	if (year < 0) {
		throw std::invalid_argument("Year cannot be negative");
	}
	if (month == 2 && is_leap_year(year)) {
		return 29;
	}
	uint8_t month_in_vector = month - 1;
	return days_in_months[month_in_vector];
}

bool test_days_in_month(int month, int year, int result)
{
	int days = simpleDate::days_in_month(month, year);
	if (days != result)
		std::cout << "days_in_month(" << month << ", " << year
		<< ") -> " << days << " instead of " << result << '\n';
	return days == result;
}

bool simpleDate::is_valid(int day, int month, int year) {
	if (year < 2020 || year > 2023) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day < 1 || day > days_in_month(month, year)) {
		return false;
	}
	return true;
}

bool test_is_valid(int day, int month, int year, bool expected)
{
	if (simpleDate::is_valid(day, month, year) != expected)
	{
		std::cout << "Error in is_valid(" << day << ", " << month << ", " << year << ")\n";
		return false;
	}
	return true;
}

simpleDate::simpleDate(int d, int m, int y) {
	if (!is_valid(d, m, y)){
		throw std::invalid_argument("Invalid date");
	}
	this->dday = d;
	this->dmonth = m;
	this->dyear = y;
}

void simpleDate::print() const {
	std::cout << dday << "-" << dmonth << "-" << dyear << std::endl;
}

void simpleDate::next_day() {
	if (dday == days_in_month(dmonth, dyear)) {
		if (dmonth == 12) {
			if (dyear == 2023) {
				return;
			}
			else {
				dyear++;
				dmonth = 1;
				dday = 1;
			}
		}
		else {
			dday = 1;
			dmonth++;
		}
	}
	else {
		dday++;
	}
}


void simpleDate::prev_day() {
	if (dday == 1) {
		if (dmonth == 1) {
			if (dyear == 2020) {
				return;
			}
			else {
				dyear--;
				dmonth = 12;
				dday = 31;
			}
		}
		else {
			dmonth--;
			dday = days_in_month(dmonth, dyear);
		}
	}
	else {
		dday--;
	}
}

bool operator==(const simpleDate& left, const simpleDate& right) {
	return left.dday == right.dday && left.dmonth == right.dmonth && left.dyear == right.dyear;
}

bool operator!=(const simpleDate& left, const simpleDate& right) {
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const simpleDate& right) {
	os << std::setfill('0') << std::setw(2) << right.dday << "-" << std::setfill('0') << std::setw(2) << right.dmonth << "-" << right.dyear;
	return os;
}
