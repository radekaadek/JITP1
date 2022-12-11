#include "entry.h"
#include <sstream>

int main() {
	{
		std::string s = "[Yossarian 1]";
		// test s as >> input to entry
		std::istringstream is(s);
		entry e;
		is >> e;
		std::cout << e << std::endl;

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
}
