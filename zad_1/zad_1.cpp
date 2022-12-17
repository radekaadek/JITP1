#include <iostream>
#include "pentadecimal.h"

using std::cout;
using std::endl;

int main() {
	cout << "12" << " -> " << penta2int("12") << endl;
	cout << "ade" << " -> " << penta2int("ade") << endl;
	cout << "ade" << " -> " << penta2int("ade") << endl;
	cout << "ade" << " -> " << penta2int("ade") << endl;
	cout << "ade" << " -> " << penta2int("ade") << endl;
	cout << 5235 << " -> " << int2penta(5235);
}
