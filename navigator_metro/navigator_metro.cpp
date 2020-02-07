// navigator_metro.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include "station.h"
#include <iterator>
#include <vector>

using namespace std;



int main()
{
	station* arr_of_stations = new station[307];
	for (int i = 0; i < 307; i++)
	{
		arr_of_stations->id = i;
	}
	
	vector< vector<bool>> graph_of_stations = { {0,1,0,0,0,0,0,0,0,0,0,0},  //Алма-Атинская
											    {1,0,1,0,1,0,0,0,0,0,0,0},  //Красногвардейская
											    {0,1,0,1,0,0,0,0,0,0,0,0},  //Зябликово
											    {0,0,1,0,0,0,0,0,0,0,0,0},  //Шипиловская
											    {0,1,0,0,0,1,0,0,0,0,0,0},  //Домодедовская
											    {0,0,0,0,1,0,1,0,0,0,0,0},  //Орехово
											    {0,0,0,0,0,1,0,1,0,0,0,0},  //Царицыно
											    {0,0,0,0,0,0,1,0,1,0,0,0},  //Кантемировская
											    {0,0,0,0,0,0,0,1,0,1,0,1},  //Каширская(зел)
											    {0,0,0,0,0,0,0,0,1,0,1,0},  //Каширская(голуб)
											    {0,0,0,0,0,0,0,0,0,1,0,0},  //Варшавская
											    {0,0,0,0,0,0,0,0,1,0,0,0} };//Коломенская

	int number_of_stations = 12;   //потом сделать 307

	vector<vector<int>> list_of_connections(number_of_stations);
	for (int i = 0; i < number_of_stations; ++i)
		for (int j = 0; j < number_of_stations; ++j)
		{
			if (graph_of_stations[i][j]) list_of_connections[i].push_back(j);
		}

	queue<int> q;

	cout << "Vvedite stantsiu nachala" << endl;
	int begin;
	cin  >> begin;

	int end;
	cout << "Vvedite stantsiu kontsa" << endl;
	cin >> end;

	q.push(begin);

	vector<bool> visited(number_of_stations) ;   //потом сделать 307
	vector<int> count_of_rebers(number_of_stations), predki(number_of_stations);

	visited[begin] = true;

	predki[begin] = -1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (size_t i = 0; i < list_of_connections[current].size(); ++i)
		{
			int to = list_of_connections[current][i];
			if (!visited[to])
			{
				visited[to] = true;
				q.push(to);
				predki[to] = current;
				count_of_rebers[to] = count_of_rebers[current] + 1;
			}
			if (to == end)
			{
				vector<int> way;
				for (int j = to; j != -1; j = predki[j])
				{
					way.push_back(j);
				}
				reverse(way.begin(), way.end());
				for (size_t i = 0; i < way.size(); ++i)
				{
					cout << way[i] + 1 << " ";
				}
			}
		}

	}



	return 0;
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
