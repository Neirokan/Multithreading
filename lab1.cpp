#include "global_lab_header.h"
#include <iostream>
#include <thread>

namespace L1
{
	void hello()
	{
		setlocale(LC_ALL, "russian");
		std::cout << "����������, ������������ ���\n";
	}

	int main()
	{
		std::thread t(hello);
		t.join();
		std::cin.get();
		return 0;
	}
}