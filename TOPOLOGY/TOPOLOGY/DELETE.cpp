#include"stdafx.h"
#include "Delete.h"
#include<iostream>
#define MAX 10000
using namespace std;
/*void merge(int topology[100][100], bool judge[100],int e,int number) {
	//int i = e + 1;
	for (int i=e+1; i < number; ++i) {
		for (int j = 0; j < number; ++j) {
			topology[i - 1][j] = topology[i][j];
			topology[j][i - 1] = topology[j][i];
		}
	}
	for (int i = 0; i < number; ++i) {
		topology[number - 1][i] = topology[i][number - 1] = MAX;
	}
	//cout << "被删除节点后存在节点，该点之后节点序号将自动前排" << endl;
}*/

int Deletenode(int topology[100][100], int number, bool judge[100]) {
	int e, i;
	int p = 0;
	cout << "请输入要删除的节点标号: ";
	cin >> e;
	e = e - 1;
	if (judge[e] == false) {
		cout << "输入错误" << endl;
		return 0;
	}
	int num = number;
	for (i = 0; i < num; ++i) {
		if (topology[e][i] != MAX)++p;
	}
	for (int i = 0; i < num; ++i) {
		topology[e][i] = MAX;
		topology[i][e] = MAX;
		if (judge[i] != false) {
			int k = 0;
			for (int w = 0; w < num; ++w) {
				if (topology[i][w] == MAX)++k;
			}
			if (k == num)judge[i] = false;
		}
	}
	judge[e] = false;
	cout << "操作成功" << endl;
	//if (judge[e + 1] != false)merge(topology, judge,e,number);
	return p;
}

int Deleteside(int topology[100][100], int number, bool judge[100]) {
	int i, j;
	int p = 0, q = 0;
	cout << "请输入要删除的边的两个端点 :";
	cin >> i >> j;
	i = i - 1; j = j - 1;
	if (topology[i][j] == MAX) {
		cout << "输入错误" << endl;
		return 0;
	}
	topology[i][j] = MAX;
	topology[j][i] = MAX;
	for (int m = 0; m < 100; ++m) {
		if (topology[i][m] == MAX)++p;
	}
	if (p == 100)judge[i] = false;
	for (int n = 0; n < 100; ++n) {
		if (topology[i][n] == MAX)++q;
	}
	if (q == 100)judge[j] = false;
	cout << "操作成功" << endl;
	return 1;
}