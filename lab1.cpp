#include "global_lab_header.hpp"
#include <iostream>
#include <thread>

namespace L1
{
	void hello()
	{
		setlocale(LC_ALL, "russian");
		std::cout << "Здравствуй, параллельный мир\n";
	}

	int main()
	{
		std::thread t(hello);
		t.join();
		std::cin.get();
		return 0;
	}
}
