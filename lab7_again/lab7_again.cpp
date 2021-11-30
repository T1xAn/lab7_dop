#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <stack> 
#include <queue>
using namespace std;

struct node {
	int numb;
	node* next;
};
struct graf {
	node** nodes;
	int size;
};

void Google_search(int** a, int num, int* dist, int size) {
	queue <int> q;
	dist[num] = 0;
	int s = num;
	vector <int> path(size, -1);
	q.push(num);
	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int i = 0; i < size; i++) {
			if (a[num][i] > 0 && dist[i] > dist[num] + a[num][i]) {
				q.push(i);
				dist[i] = dist[num] + a[num][i];
				path[i] = num;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (dist[i] == 0)
			cout << endl << s << "->" << i << "= " << "Пути не существует " << endl;
		else {
			cout << endl << s << "->" << i << " = " << dist[i] << endl;

			vector<int> buff;
			for (int cur = i; cur != -1; cur = path[cur])
				buff.push_back(cur);
			reverse(buff.begin(), buff.end());

			cout << "Путь - ";
			for (size_t i = 0; i < buff.size(); ++i)
				cout << buff[i] << " -> ";

			cout << endl;
		}
	}
}

//void Google_search1(int** a, int num, int* dist, int size) {
//	queue <int> q;
//	/*stack <int> path_order;*/
//	int** arr = new int* [size];
//
//	for (int count = 0; count < size; ++count)
//		arr[count] = new int[size];
//	for (int row = 0; row < size; row++) {
//		for (int col = 0; col < size; col++) {
//			if (col == 0)
//			arr[row][col] = num;
//			else
//			arr[row][col] = 0;
//		}
//	}
//	dist[num] = 0;
//	q.push(num);
//	while (!q.empty()) {
//		num = q.front();
//		q.pop();
//		for (int i = 0; i < size; i++) {
//			if (a[num][i] > 0 && dist[i] > dist[num] + a[num][i]) {
//				q.push(i);
//				int col = 0;
//				int k = 0;
//				while (arr[i][col] != 0) {
//					k++;
//					col++;
//				}
//				
//				arr[i][k+1] = num;
//				dist[i] = dist[num] + a[num][i];
//			}
//		}
//
//	}
//
//	for (int row = 0; row < size; row++)
//	{
//		for (int col = 0; col < size; col++) {
//			cout << arr[row][col] << " ";
//		}
//		cout << endl << "   ";
//	}
//	cout << endl;
//
//}

/*void Google_search2(int** a, int num, int* dist, int size) {
	queue <int> q;
	stack <int> 
	dist[num] = 0;
	q.push(num);
	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int i = 0; i < size; i++) {
			if (a[num][i] > 0 && dist[i] > dist[num] + a[num][i]) {
				q.push(i);
				dist[i] = dist[num] + a[num][i];
			}
		}
	}
}*/

int main(int argc, char* argv[]) {
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	if (argc <= 1) {
		cout << "Веедите аргументы для правильной работы программы" << endl;
		return 1;
	}
	int rand_limit;
	if (strcmp(argv[1], "no"))
		rand_limit = 100;
	else
		rand_limit = 2;

	int size;

	cout << "   Введите размерность матрицы: ";
	cin >> size;
	cout << endl;

	int** arr = new int* [size];
	for (int count = 0; count < size; ++count)
		arr[count] = new int[size];

	if (strcmp(argv[2], "no")) {
		for (int row = 0; row < size; row++) {
			arr[row][row] = 0;
			for (int col = row + 1; col < size; col++) {
				arr[row][col] = rand() % rand_limit;
				arr[col][row] = rand() % rand_limit;
			}
		}
	}
	else {
		for (int row = 0; row < size; row++) {
			arr[row][row] = 0;
			for (int col = row + 1; col < size; col++) {
				arr[row][col] = rand() % rand_limit;
				arr[col][row] = arr[row][col];
			}
		}
	}
	cout << "   ";

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++) {
			cout << arr[row][col] << " ";
		}
		cout << endl << "   ";
	}
	cout << endl;


	auto distG = new int[size];
	for (int i = 0; i < size; i++)
		distG[i] = INT_MAX;
	cout << endl << "      Поиск кратчайшего пути в графе, представленным через матрицу смежности, реализованный на основе алгоритма поиска в ширину с использованием очереди" << endl << endl;
	cout << "   Введите номер вершины, с которой хотите начать обход: ";
	int start;
	cin >> start;


	Google_search(arr, start, distG, size);
	;
	cout << endl;
	for (int i = 0; i < size; i++)
		if (distG[i] == -1)
			cout << "   Кратчайший путь до вершины " << i << " = " << 0 << endl;
		else
			cout << "   Кратчайший путь до вершины " << i << " = " << distG[i] << endl;
}
	/*for (int i = 0; i < size; i++)
		distG[i] = INT_MAX;
	Google_search1(arr, start, distG, size);
	return 0;
}*/

