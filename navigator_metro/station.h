#pragma once
#include <string>
#include <queue>
#include <iostream>


class station
{
	public:
		int id;                                               //����� �������

		std::string name;                                         //��� �������

		bool paired;                                          //������� ��

		std::queue<int> connected;

		void get_name()
		{
			std::cout << name << std::endl;
		}
};

