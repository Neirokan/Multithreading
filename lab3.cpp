/**
 * Задание: создать 2 потока, где первый создает файл и записывает в него
 * произвольные данные, передает второму название созданного файла, а второй
 * в свою очередь открывает этот файл на чтение. После чтения, второй поток
 * отправляет сигнал первому потоку. Первый поток, получив сигнал о завершении
 * завершает свою работу.
 */

#include "global_lab_header.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>

namespace L3
{
	inline bool has_extension(const std::string& str)
	{
		size_t sep = str.find_last_of("\\/");
		size_t dot = str.find_last_of('.');
		return dot != str.npos && (sep == str.npos || dot > sep);
	}

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
		if (!has_extension(filename))
			filename += ".txt";
		std::ofstream fout(filename);
		if (!fout.is_open())
			return;

		for (uint32_t i = rand() % 100 + 10; i > 0; i--)
			fout << char(rand() % 95 + 32);

		fout.close();

		std::cout << "Поток 1 создал и записал файл." << std::endl;

		std::thread t(reader, std::ref(filename));
		t.join();

		std::cout << "Поток 1 закончил свою работу." << std::endl;
	}

	int main()
	{
		std::thread t (writer);
		t.join();
		std::cin.get();
		return 0;
	}
}
