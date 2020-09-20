#include "global_lab_header.hpp"
#include <iostream>
#include <fstream>
#include <thread>

namespace L2
{
	namespace Y2
	{
		void fib(std::string name)
		{
			std::ofstream f(name, std::ios::out);
			if (f.is_open())
			{
				f << 1 << ' ' << 1;
				for (int a = 1, b = 1, i = 3; i <= 12; i++)
				{
					a += b;
					std::swap(a, b);
					f << ' ' << b;
				}
				f.close();
			}
		}

		void notify(std::string name)
		{
			std::thread f(fib, name);
			f.join();
			std::cout << "Поток закончил работу." << std::endl;
		}

		void app(std::string name)
		{
			std::fstream f(name, std::ios::in | std::ios::out);
			if (f.is_open())
			{
				int num, sum = 0;
				while (f >> num) sum += num;
				f.clear();
				f << ' ' << sum;
				f.close();
			}
			std::cout << "Поток дополнил файл." << std::endl;
		}

		int main()
		{
			std::string name = "Fibonacci.txt";

			std::thread th(notify, name);
			th.join();
			th = std::thread(app, name);
			th.join();
			std::cin.get();
			return 0;
		}
	}
}
