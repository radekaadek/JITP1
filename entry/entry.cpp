#include "entry.h"
#include <string>

std::ostream& operator<<(std::ostream& os, const entry& e) {
	os << "[" << e.val << " " << e.cnt << "]";
	return os;
}

std::istream& operator>>(std::istream& is, entry& e) {
	// read input to a string
	std::string current, sum;
	while (is >> current) {
		sum += current;
		sum += " ";
	}
	// remove '[' and '] '
	sum = sum.substr(1, sum.size() - 3);
	// find last space
	std::string::size_type pos = sum.find_last_of(' ');
	// get val and cnt
	e.val = sum.substr(0, pos);
	e.cnt = std::stoi(sum.substr(pos + 1));
	return is;
}
