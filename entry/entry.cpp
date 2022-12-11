#include "entry.h"
#include <string>

std::ostream& operator<<(std::ostream& os, const entry& e) {
	os << "[" << e.val << " " << e.cnt << "]";
	return os;
}

std::istream& operator>>(std::istream& is, entry& e) {
	// read input to a string
	std::string current = "", sum = "";
	while (is >> current) {
		sum += current;
		sum += " ";
	}
	// check if the string is empty or doesnt contain '[' or ']'
	if (sum.length() < 6 || sum[0] != '[' || sum[sum.size() - 2] != ']') {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	// remove "[" and "] "
	sum = sum.substr(1, sum.size() - 3);
	if (sum.empty()) {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	// find the last space
	std::string::size_type pos = sum.find_last_of(' ');
	if (pos == std::string::npos || pos == sum.size() - 1) {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	// get val and cnt
	if (sum.substr(0, pos).empty()) {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	if (sum.substr(pos + 1).empty() ||
		sum.substr(pos + 1).find_first_not_of("0123456789") != std::string::npos) {
		is.setstate(std::ios_base::failbit);
		return is;
	}
	e.val = sum.substr(0, pos);
	e.cnt = std::stoi(sum.substr(pos + 1));
	return is;
}
