#include <iostream>
#include "global_lab_header.hpp"

using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Lab 1" << endl;
	L1::main();
	cout << "Lab 2.1 (X)" << endl;
	L2::X::main();
	cout << "Lab 2.2 (X)" << endl;
	L2::X::main();
	cout << "Lab 2.1 (Y)" << endl;
	L2::Y1::main();
	cout << "Lab 2.2 (Y)" << endl;
	L2::Y2::main();
	cout << "Lab 3" << endl;
	L3::main();
	return 0;
}
