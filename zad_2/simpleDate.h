// Radoslaw Dabkowski (325683)
#pragma once
#include <iostream>
#include <vector>

class simpleDate {
private:
	int dday, dmonth, dyear;
	static const std::vector<int> days_in_months;
public:
	explicit simpleDate(int d = 1, int m = 1, int y = 2020);
	int day() const {
		return dday;
	}
	int month() const {
		return dmonth;
	}
	int year() const {
		return dyear;
	}
	void print() const;
	// modyfikacje daty
	void next_day();
	void prev_day();
	// funkcje pomocnicze
	static bool is_leap_year(int year);
	static bool is_valid(int day, int month, int year);
	static int days_in_month(int month, int year);
	friend std::ostream& operator<<(std::ostream& os, const simpleDate& right);
	friend bool operator==(const simpleDate& left, const simpleDate& right);
	friend bool operator!=(const simpleDate& left, const simpleDate& right);
};

bool test_is_leap_year(int year, bool expected);
bool test_days_in_month(int month, int year, int result);
bool test_is_valid(int day, int month, int year, bool expected);
