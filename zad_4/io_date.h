// Radoslaw Dabkowski (325683)

#pragma once

#include <iostream>
#include <vector>


class io_date {
	int day, month, year;
	void set_members(int day, int month, int year);
	static const std::vector<int> days_in_months;
	static bool is_leap_year(int year);
	static int days_in_month(int month, int year);
	static bool is_valid(int day, int month, int year);
	
public:
	io_date() : day(1), month(1), year(2020)
	{ }
	
	friend std::ostream& operator<<(std::ostream& os,
									const io_date& dt);
	friend std::istream& operator>>(std::istream& is,
										io_date& dt);
};
