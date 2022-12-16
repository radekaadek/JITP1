#include "word_counter.h"
#include <sstream>
#include <random>
#include <fstream>

int main() {
	srand(time(NULL));
	word_counter wc;
	if (wc.size() != 0)
		std::cout << "Invalid size() of empty counter () " << wc.size() << '\n';
	// add some random words
	std::vector<std::string> words = { "ala", "ma", "kota", "a", "kot", "ma", "ale" };
	for (int i = 0; i < 50; i++) {
		wc.add_word(words[rand() % words.size()]);
	}
	std::cout << "\n\n\n\n";
	// show all words and their counts
	for (auto it = wc.begin(); it != wc.end(); it++)
		std::cout << *it << '\n';
	std::cout << "\n\nSorted by count\n\n";
	// sort by count
	wc.sort_count();
	// show all words and their counts
	for (auto it = wc.begin(); it != wc.end(); it++)
		std::cout << *it << '\n';
	std::cout << "\n\nSorted by alpha\n\n";
	// sort by alpha
	wc.sort_alpha();
	// show all words and their counts
	for (auto it = wc.begin(); it != wc.end(); it++)
		std::cout << *it << '\n';
	std::cout << "\n\n\n\n";

	// test mobby dick
	word_counter md_cnt;
	std::ifstream is("moby_dick.txt");
	if (!is) {
		std::cout << "Error opening input file.\n";
		return 1;
	}
	std::string word;
	int max = 0;
	while (is >> word) {
		md_cnt.add_word(word);
	}
	is.close();
	// to oczywiście *dobry* zły pomysł
	std::cout << "\n\n-----------\n\n";
	md_cnt.sort_count();
	std::cout << md_cnt << "\n";
	/*
	{
		std::string s = "[Yossarian 1] [Clevinger 2]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e, b;
		is >> e >> b;
		std::cout << e << b << std::endl;

	}
	{
		std::string s = "[Clevinger 2]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;

	}
	{
		std::string s = "[Milo Minderbinder 234]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;

	}
	{
		std::string s = "[Major Major Major Major 345]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;

	}
	{
		std::string s = "[Catch 22 666]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;

	}
	{
		std::string s = "[]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	{
		std::string s = "[123]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	{
		std::string s = "<>";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	{
		std::string s = "[xyz --]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	{
		std::string s = "[32 32]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	{
		std::string s = "[milo -32]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;
	}
	*/
}
