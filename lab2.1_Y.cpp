#include "global_lab_header.hpp"
#include <iostream>
#include <thread>

namespace L2
{
	namespace Y1
	{
		void fib()
		{
			std::cout << 1 << ' ' << 1;
			for (int a = 1, b = 1, i = 3; i <= 12; i++)
			{
				a += b; std::swap(a, b); std::cout << ' ' << b;
			}
			std::cout << std::endl;
		}

		void notify()
		{
			std::thread f(fib);
			f.join();
			std::cout << "Поток закончил работу." << std::endl;
		}

		int main()
		{
			std::thread waiting(notify);
			waiting.join();
			std::cin.get();
			return 0;
		}
	}
}
