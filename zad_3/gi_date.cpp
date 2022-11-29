// Radoslaw Dabkowski (325683)

#include "gi_date.h"
#include <algorithm>


gi_date::gi_date(int day, int month, int year) {
	if (!is_valid(day, month, year))
		throw std::invalid_argument("Invalid date");
	days_since_start = day - 1;
	for (int i = 1; i < month; ++i)
		days_since_start += days_in_month(i, year);
	for (int i = 2020; i < year; ++i)
		days_since_start += days_in_year(i);
}


int gi_date::get_year() const {
	int year = 2020;
	int days = days_since_start + 1;
	while (days > days_in_year(year)) {
		days -= days_in_year(year);
		++year;
	}
	return year;
}


int gi_date::get_month() const {
	int current_year = 2020;
	int days = days_since_start + 1;
	while (days > days_in_year(current_year)) {
		days -= days_in_year(current_year);
		++current_year;
	}
	int month = 1;
	while (days > days_in_month(month, current_year)) {
		days -= days_in_month(month, current_year);
		++month;
	}
	return month;
}


int gi_date::get_day() const {
	int current_year = 2020;
	int days = days_since_start + 1;
	while (days > days_in_year(current_year)) {
		days -= days_in_year(current_year);
		++current_year;
	}
	int month = 1;
	while (days > days_in_month(month, current_year)) {
		days -= days_in_month(month, current_year);
		++month;
	}
	return days;
}


void gi_date::next_day() {
	if (days_since_start < last_day_since) {
		++days_since_start;
	}
}


void gi_date::prev_day() {
	if (days_since_start > 0) {
		--days_since_start;
	}
}


gi_date& gi_date::operator+=(int days) {
	if (days > last_day_since) {
		days_since_start = 0;
	}
	
	days_since_start = std::min(std::max(0, days_since_start + days),
		last_day_since);
	return *this;
}


gi_date& gi_date::operator-=(int days) {
	if (-days > last_day_since) {
		days_since_start = 0;
	}
	days_since_start = std::min(std::max(0, days_since_start - days),
		last_day_since);
	return *this;
}


bool gi_date::is_leap_year(int year) {
    if (year < 1) {
        throw std::invalid_argument("Year cannot be negative or zero");
    }
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}


bool gi_date::is_valid(int day, int month, int year) {
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


int gi_date::days_in_month(int month, int year) {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Month must be between 1 and 12");
    }
    if (year < 0) {
        throw std::invalid_argument("Year cannot be negative");
    }
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    int month_in_vector = month - 1;
    return days_in_months[month_in_vector];
}


bool operator==(const gi_date& left, const gi_date& right) {
	return left.days_since_start == right.days_since_start;
}


bool operator!=(const gi_date& left, const gi_date& right) {
	return left.days_since_start != right.days_since_start;
}


bool operator<(const gi_date& left, const gi_date& right) {
	return left.days_since_start < right.days_since_start;
}


bool operator>(const gi_date& left, const gi_date& right) {
	return left.days_since_start > right.days_since_start;
}


bool operator<=(const gi_date& left, const gi_date& right) {
	return left.days_since_start <= right.days_since_start;
}


bool operator>=(const gi_date& left, const gi_date& right) {
	return left.days_since_start >= right.days_since_start;
}


int operator-(const gi_date& left, const gi_date& right) {
	return left.days_since_start - right.days_since_start;
}


std::ostream& operator<<(std::ostream& os, const gi_date& dt){
	os << dt.get_day() << "." << dt.get_month() << "." << dt.get_year();
	return os;
}


const std::vector<int> gi_date::days_in_months
= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


int gi_date::days_in_year(int year) {
	return is_leap_year(year) ? 366 : 365;
}