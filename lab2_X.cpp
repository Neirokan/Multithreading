#include "global_lab_header.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <string>

namespace L2
{
	namespace X
	{
		// Вычисление и вывод числе Фибоначчи
		void fibonacci(const std::string& filename)
		{
			// Проверка открытия файла
			std::ofstream fout;
			if (!filename.empty())
				fout.open(filename);
			std::ostream& out = fout.is_open() ? fout : std::cout;

			// Вычисление и вывод
			uint16_t a, b, i;
			out << "1 1";
			for (a = 1, b = 1, i = 2; i < 12; i++)
			{
				a += b;
				std::swap(a, b);
				out << ' ' << b;
			}
			out << std::endl;

			// Закрытие файла
			if (fout.is_open())
				fout.close();
		}

		// Ожидает завершения вычисления чисел Фибоначчи и пишет об этом
		void waiter(const std::string& filename)
		{
			std::thread t(fibonacci, filename);
			t.join();
			std::cout << "Fibonacci function finished." << std::endl;
		}

		// Дописывает сумму чисел в файле в конец файла
		void sum_appender(const std::string& filename)
		{
			// Проверка открытия файла
			std::fstream f;
			if (filename.empty() || (f.open(filename, std::ios::in | std::ios::out), !f.is_open()))
				return;

			// Считывание и суммирование чисел
			uint16_t sum = 0, tmp;
			while (f >> tmp)
				sum += tmp;

			// Вывод суммы и закрытие файла
			f.clear();
			f << sum << std::endl;
			f.close();
			std::cout << "Appender function finished." << std::endl;
		}

		int main()
		{
			std::cout << "Enter file name (nothing for screen): ";
			std::string filename;
			std::getline(std::cin, filename);

			if (!filename.empty() && !utility::has_extension(filename))
				filename += ".txt";

			std::thread t(waiter, filename);
			t.join();

			t = std::thread(sum_appender, filename);
			t.join();

			std::cin.get();
			return 0;
		}
	}
}
