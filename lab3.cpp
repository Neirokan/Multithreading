/*
  �������: ������� 2 ������, ��� ������ ������� ���� � ���������� � ���� ������������ ������,
  �������� ������� �������� ���������� �����, � ������ � ���� ������� ��������� ���� ���� �� ������.
  ����� ������, ������ ����� ���������� ������ ������� ������.
  ������ �����, ������� ������ � ���������� ��������� ���� ������.
*/

#include "global_lab_header.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>

namespace L3
{
	void reader(std::string& filename)
	{
		std::ifstream fout(filename);
		if (!fout.is_open())
			return;

		std::cout << "����� 2 �������� ���� ������." << std::endl;
	}

	void writer()
	{
		std::string filename;
		std::cout << "������� ��� �����: ";
		std::getline(std::cin >> std::ws, filename);
		std::ofstream fout(filename);
		if (!fout.is_open())
			return;

		for (uint32_t i = rand() % 100 + 10; i > 0; i--)
			fout << char(rand() % 100 + 100);

		fout.close();

		std::cout << "����� 1 ������ � ������� ����." << std::endl;

		std::thread t(reader, std::ref(filename));
		t.join();

		std::cout << "����� 1 �������� ���� ������." << std::endl;
	}

	int main()
	{

		std::cin.get();
		return 0;
	}
}
