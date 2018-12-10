#include"stdafx.h"
#include"TOPOLOGY.h"
#include"FILE.h"
#include<iostream>
#include<string.h>
#define MAX 10000
using namespace std;

void Gplot(int topology[100][100], int num, int sid, bool judge[100]){
	int number = num;
	int side = sid;
	int m = 0, n = 0, l = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			topology[i][j] = MAX;
		}
	}
	for (int r = 0; r < 100; ++r) {
		if (r < num)judge[r] = true;
		else {
			judge[r] = false;
		}
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i == j)topology[i][j] = 0;
		}
	}
	cout << "��������·�����ľ���(�� 1 2 6����Ϊ·����1��·����2�ľ���Ϊ6��" << endl;
	for (int i = 0; i < side; ++i) {
		cin >> m >> n >> l;
		judge[m - 1] = judge[n - 1] = true;
		topology[m - 1][n - 1] = topology[n - 1][m - 1] = l;
	}
	writefile(num, topology, judge);
}