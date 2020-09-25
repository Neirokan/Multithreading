/**
 * Задание: создать 2 потока, где первый создает файл и записывает в него
 * произвольные данные, передает второму название созданного файла, а второй
 * в свою очередь открывает этот файл на чтение. После чтения, второй поток
 * отправляет сигнал первому потоку. Первый поток, получив сигнал о завершении
 * завершает свою работу.
 */

#include "global_lab_header.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>
#include <random>
#include <chrono>

namespace L3
{
	void reader(std::string& filename)
	{
		std::ifstream fin(filename);
		if (!fin.is_open())
			return;

		char ch;

		while (fin >> ch) {}

		std::cout << "Поток 2 закончил свою работу." << std::endl;
	}

	void writer()
	{
		std::string filename;
		std::cout << "Введите имя файла: ";
		std::getline(std::cin >> std::ws, filename);
		if (!utility::has_extension(filename))
			filename += ".txt";
		std::ofstream fout(filename);
		if (!fout.is_open())
			return;

		std::minstd_rand rng(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<uint16_t> dist(32, 126);
		for (uint16_t i = dist(rng); i > 0; i--)
			fout << static_cast<char>(dist(rng));
		fout << std::endl;

		fout.close();

		std::cout << "Поток 1 создал и записал файл." << std::endl;

		std::thread t(reader, std::ref(filename));
		t.join();

		std::cout << "Поток 1 закончил свою работу." << std::endl;
	}

	int main()
	{
		std::thread t(writer);
		t.join();
		std::cin.get();
		return 0;
	}
}
