#include "entry.h"
#include <string>
#include <regex>


std::ostream& operator<<(std::ostream& os, const entry& e) {
	os << "[" << e.val << " " << e.cnt << "]";
	return os;
}


std::istream& operator>>(std::istream& is, entry& e) {
	// read characters from istream into a string
	// untill a regex match is found
	// if no match is found, set failbit and return is
	// if a match is found, set the e.val and e.cnt

	std::string s = "";
	std::string pattern = R"(\[[a-zA-Z0-9][[a-zA-Z0-9 ]*\b \d+\])";
	char c;
	while (is.get(c)) {
		s += c;
		if (std::regex_match(s, std::regex(pattern))) {
			e.val = s.substr(1, s.find_last_of(' ') - 1);
			e.cnt = std::stoi(s.substr(s.find_last_of(' ') + 1, s.size() - 2));
			// clear whitespace after the entry
			if (is.peek() == ' ') {
				is.get();
			}
			return is;
		}
	}
	is.setstate(std::ios_base::failbit);
	throw std::runtime_error("Wrong input");
	return is;
}
