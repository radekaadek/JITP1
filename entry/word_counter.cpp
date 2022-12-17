// Radoslaw Dabkowski (325683)

// Troche zwalnia przy duzych ilosciach slow ale
// do 10000 ladnie liczy

#include "word_counter.h"
#include <algorithm>

word_counter::const_iterator word_counter::begin() const {
    return word_cnt.begin();
}

word_counter::const_iterator word_counter::end() const {
    return word_cnt.end();
}

int word_counter::add_word(const std::string& word) {
	for (entry& e : word_cnt) {
		if (*e == word) {
			e++;
			return (int)e;
		}
	}
	word_cnt.push_back(entry(word, 1));
	return 1;
}

size_t word_counter::size() const {
	return word_cnt.size();
}

void word_counter::sort_alpha() {
	std::sort(word_cnt.begin(), word_cnt.end(), [](const entry& a, const entry& b) {
		return *a < *b;
	});
}

void word_counter::sort_count() {
	std::sort(word_cnt.begin(), word_cnt.end(), [](const entry& a, const entry& b) {
		return (int)a > (int)b;
	});
}

std::ostream& operator<<(std::ostream& os, const word_counter& wc) {
	for (auto it = wc.begin(); it != wc.end(); it++)
		os << *it << '\n';
	return os;
}

