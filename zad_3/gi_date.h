// Radoslaw Dabkowski (325683)

#pragma once

#include <iostream>
#include <vector>

class gi_date {
public:
    explicit gi_date(int day = 1, int month = 1, int year = 2020);

    int get_year() const;
    int get_month() const;
    int get_day() const;

    void next_day();
    void prev_day();

    gi_date& operator+=(int days);
    gi_date& operator-=(int days);

    static bool is_leap_year(int year);
    static bool is_valid(int day, int month, int year);
    static int days_in_month(int month, int year);
	
	friend bool operator==(const gi_date& lhs, const gi_date& rhs);
	friend bool operator!=(const gi_date& lhs, const gi_date& rhs);
	friend bool operator<(const gi_date& lhs, const gi_date& rhs);
	friend bool operator>(const gi_date& lhs, const gi_date& rhs);
	friend bool operator<=(const gi_date& lhs, const gi_date& rhs);
	friend bool operator>=(const gi_date& lhs, const gi_date& rhs);
	friend int operator-(const gi_date& lhs, const gi_date& rhs);
    friend std::ostream& operator<<(std::ostream& os, const gi_date& right);
	
private:
    int days_since_start;
    static const int last_day_since = 365 * 3 + 366 - 1;
    static const std::vector<int> days_in_months;
    static int days_in_year(int year);
};
