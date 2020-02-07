#pragma once
#include <string>
#include <queue>
#include <iostream>


class station
{
	public:
		int id;                                               //номер станции

		std::string name;                                         //имя станции

		bool paired;                                          //спарена ли

		std::queue<int> connected;

		void get_name()
		{
			std::cout << name << std::endl;
		}
};

