#include"stdafx.h"
#include"READ.h"
#include<iostream>
#define MAX 10000
using namespace std;
void readtable(int *dist, int *path, int vertex_num, int source,bool judge[100]) {
	int a[100][100];
	int b[100];
	int k = 0;
	int r = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < vertex_num; i++)
	{
		k = 0;
		if (dist[i] < MAX) {
			if (i != source)
			{
				//cout << source + 1 << " 到 " << i + 1 << " 的最短距离是：" << dist[i] << "，路径是：" << i + 1;
				a[i][k] = i + 1; ++k;
				int t = path[i];
				while (t != source)
				{
					a[i][k] = t+1;
					++k;
					//cout << "--" << t + 1;
					t = path[t];
				}
				//cout << "--" << source + 1 << endl;
				a[i][k] = source + 1;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < vertex_num; ++i) {
		int y = 0;
			for (int j = 0; j < vertex_num; ++j) {
				if (a[i][j] != 0)++y;
			}
			b[i] = y;
	}
	cout << source + 1 << "的路由表对应如下: " << endl;
	for (int i = 0; i < vertex_num; ++i) {
		if (dist[i] < MAX) {
			if (i != source) {
				//int r = 0;
				//for (int j = b[i]; j >= 0; --j){
				int j = b[i] - 2;
				cout << "目的地" << "     " << "距离" << "      " << "下一跳" << endl;
				cout << i + 1 << "          " << dist[i] << "           ";
				if (a[i][j] != 0) {
					cout << a[i][j] << "  ";
					cout << endl;
				}
			}
		}
	}
	cout << "    asd";
cout<<"sdcs";
} 