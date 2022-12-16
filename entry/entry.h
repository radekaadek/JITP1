#pragma once
#include <iostream>


class entry {
public:
	entry(const std::string& s = "", int val = 0) : val(s), cnt(val) {}
	std::string operator*() const { return val; }
	operator int() const { return cnt; }
	int operator++(int) { int tmp = cnt; cnt++; return tmp; }
	bool operator<(const entry& e) const { return val < e.val; }
	friend std::ostream& operator<<(std::ostream& os, const entry& e);
	friend std::istream& operator>>(std::istream& is, entry& e);
private:
	std::string val;
	int cnt;
};

