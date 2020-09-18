#include "global_lab_header.h"
#include <iostream>
#include <thread>

namespace L2
{
	namespace Y1
	{
		void fib()
		{
			for (int a = 1, b = 1, i = 3; i <= 12; i++)
			{
				a += b; std::swap(a, b);
			}
		}

		void notify()
		{
			std::thread f(fib);
			f.join();
			setlocale(LC_ALL, "russian");
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