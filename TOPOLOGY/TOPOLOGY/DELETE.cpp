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
	//cout << "��ɾ���ڵ����ڽڵ㣬�õ�֮��ڵ���Ž��Զ�ǰ��" << endl;
}*/

int Deletenode(int topology[100][100], int number, bool judge[100]) {
	int e, i;
	int p = 0;
	cout << "������Ҫɾ���Ľڵ���: ";
	cin >> e;
	e = e - 1;
	if (judge[e] == false) {
		cout << "�������" << endl;
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
	cout << "�����ɹ�" << endl;
	//if (judge[e + 1] != false)merge(topology, judge,e,number);
	return p;
}

int Deleteside(int topology[100][100], int number, bool judge[100]) {
	int i, j;
	int p = 0, q = 0;
	cout << "������Ҫɾ���ıߵ������˵� :";
	cin >> i >> j;
	i = i - 1; j = j - 1;
	if (topology[i][j] == MAX) {
		cout << "�������" << endl;
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
	cout << "�����ɹ�" << endl;
	return 1;
}