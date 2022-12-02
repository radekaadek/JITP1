#include "io_date.h"
#include <sstream>


using namespace std;


void test_valid_date(string input) {
	stringstream is(input);
	io_date dt;
	is >> dt;

	stringstream os;
	os << dt;
	
	if (os.str() != input) {
		cout << "ERROR: " << input << " -> " << os.str() << endl;
	}
}


void test_invalid_date(string input) {
	stringstream is(input);
	io_date dt;
	try {
		is >> dt;
		cout << "ERROR: " << input << " -> " << dt << endl;
	}
	catch (runtime_error& e) {
		cout << "OK: " << input << " -> " << e.what() << endl;
	}
}

int main()
{
	test_valid_date("2020-01-01");
	test_valid_date("2020-02-29");
	test_valid_date("2020-03-31");
	test_valid_date("2020-04-30");
	test_valid_date("2020-05-31");
	test_valid_date("2020-06-30");
	test_valid_date("2020-07-31");
	test_valid_date("2020-08-31");
	test_valid_date("2020-09-30");
	test_valid_date("2020-10-31");
	test_valid_date("2020-11-30");
	test_valid_date("2020-12-31");
	test_valid_date("2021-01-01");
	test_valid_date("2021-02-28");
	test_valid_date("2021-03-31");
	test_valid_date("2021-04-30");
	test_valid_date("2021-05-31");
	test_valid_date("2021-06-30");
	test_valid_date("2021-07-31");
	test_valid_date("2021-08-31");
	test_valid_date("2021-09-30");
	test_valid_date("2021-10-31");
	test_valid_date("2021-11-30");
	test_valid_date("2021-12-31");
	test_valid_date("2022-01-01");
	test_valid_date("2022-02-28");
	test_valid_date("2022-03-31");
	test_valid_date("2022-04-30");
	test_valid_date("2022-05-31");
	test_valid_date("2022-06-30");
	test_valid_date("2022-07-31");
	test_valid_date("2022-08-31");
	test_valid_date("2022-09-30");
	test_valid_date("2022-10-31");
	test_valid_date("2022-11-30");
	test_valid_date("2022-12-31");
	test_valid_date("2023-01-01");
	test_valid_date("2023-02-28");
	test_valid_date("2023-03-31");
	test_valid_date("2023-04-30");
	test_valid_date("2023-05-31");
	test_valid_date("2023-06-30");
	test_valid_date("2023-07-31");
	test_valid_date("2023-08-31");
	test_valid_date("2023-09-30");
	test_valid_date("2023-10-31");
	test_valid_date("2023-11-30");
	test_valid_date("2023-12-31");

	
	test_invalid_date("2020-02-30");
	test_invalid_date("2020-04-31");
	test_invalid_date("2020-06-31");
	test_invalid_date("2020-09-31");
	test_invalid_date("2020-11-31");
	test_invalid_date("2021-02-29");
	test_invalid_date("");
	test_invalid_date("2020-02-29-");
	test_invalid_date("1-02-29");
	test_invalid_date("2020-1-");
	test_invalid_date("2020-\n-15");
	test_invalid_date("");
	
	
	
}
