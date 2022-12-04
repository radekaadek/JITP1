// Radoslaw Dabkowski (325683)

#include "io_date.h"
#include <iomanip>

void io_date::set_members(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}


const std::vector<int> io_date::days_in_months = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};



bool io_date::is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}


int io_date::days_in_month(int month, int year) {
	if (month == 2 && is_leap_year(year)) {
		return 29;
	}
	uint8_t month_index = month - 1;
	return days_in_months[month_index];
}


bool io_date::is_valid(int day, int month, int year) {
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


std::istream& operator>>(std::istream& is, io_date& dt) {
	int year, month, day;
	char sep1, sep2;
	if (is >> year >> sep1 >> month >> sep2 >> day) {
		if (sep1 != '-' || sep2 != '-' ||
				!io_date::is_valid(day, month, year)) {
			is.setstate(std::ios_base::failbit);
			throw std::runtime_error("Invalid input date.");
			return is;
		}
		dt.set_members(day, month, year);
	}
	else {
		throw std::runtime_error("Invalid input date.");
	}
	return is;
}


std::ostream& operator<<(std::ostream& os, const io_date& dt) {
	os << dt.year << '-' << std::setfill('0') << std::setw(2) << dt.month 
		<< '-' << std::setfill('0') << std::setw(2) << dt.day;
	return os;
}
