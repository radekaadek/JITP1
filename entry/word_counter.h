// Radoslaw Dabkowski (325683)

#pragma once
#include "entry.h"
#include <vector>
#include <ostream>


class word_counter {
    std::vector<entry> word_cnt;
public:
    typedef std::vector<entry>::const_iterator const_iterator;
    const_iterator begin() const;
    const_iterator end() const;
    int add_word(const std::string& word);
    size_t size() const;
	void sort_alpha();
	void sort_count();
	friend std::ostream& operator<<(std::ostream& os, const word_counter& wc);
};
