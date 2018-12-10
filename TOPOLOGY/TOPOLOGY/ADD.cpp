#include"stdafx.h"
#include"ADD.h"
#include<iostream>
#define MAX 10000
using namespace std;
int Addside(int topology[100][100], int number, bool judge[100]) {
	int i = 0, j = 0, l = 0;
	cout << "请输入节点i到节点j的距离: " << endl;
	cin >> i >> j >> l;
	i = i - 1; j = j - 1;
	if (l == 0)return 0;
	judge[i] = true;
	judge[j] = true;
	topology[i][j] = topology[j][i] = l;
	cout << "操作成功" << endl;
	return 1;
}

int Addnode(int topology[100][100], int number, bool judge[100]) {
	int i = 0, j = 0, x = 0, y = 0;
	int k[100] = { 0 };
	int t = 0;
	int w = 0;
	for (int y=0; y < number; ++y) {
		if (judge[y] == false) {
			k[t] = y;
			++t;
		}
	}
	if (t != 0) {
		cout << "您选择在1：最后节点前的空闲位置添加，2：最后节点后一位添加: ";
		cin >> w;
		if(w==1){
			int f = 0;
			cout << "当前可插入位置有: ";
			for (int r = 0; r < t; ++r) {
				cout << k[r] + 1 << "  ";
			}
			cout << endl;
			cout << "您想插入的位置: ";
			cin >> f;
			f = f - 1;
			cout << "与增加节点相关的边数为: ";
			cin >> j;
			if (j == 0)return 0;
			int temp = number;
			++number;
			judge[f] = true;
			cout << "依次输入相关点 " << "边的权值: " << endl;
			for (int m = 0; m < j; ++m) {
				cin >> x >> y;
				judge[x - 1] = true;
				topology[f][x - 1] = topology[x - 1][f] = y;
			}
			cout << "操作成功" << endl;
			return 1;
		}
		if(w==2){
			cout << "即将在最后节点后增加一个节点" << endl;
			i = number + 1;
			i = i - 1;
			if (judge[i] == true || i == 0) {
				cout << "输入错误" << endl;
				return 0;
			}
			cout << "与增加节点相关的边数为: ";
			cin >> j;
			if (j == 0)return 0;
			int temp = number;
			++number;
			judge[i] = true;
			cout << "依次输入相关点 " << "边的权值: " << endl;
			for (int m = 0; m < j; ++m) {
				cin >> x >> y;
				judge[x - 1] = true;
				topology[i][x - 1] = topology[x - 1][i] = y;
			}
			cout << "操作成功" << endl;
			return 0;
		}
		cout << "错误" << endl;
		return 0;
	}
	else {
		cout << "即将增加一个节点" << endl;
		i = number + 1;
		i = i - 1;
		if (judge[i] == true || i == 0) {
			cout << "输入错误" << endl;
			return 0;
		}
		cout << "与增加节点相关的边数为: ";
		cin >> j;
		if (j == 0)return 0;
		int temp = number;
		++number;
		judge[i] = true;
		cout << "依次输入相关点 " << "边的权值: " << endl;
		for (int m = 0; m < j; ++m) {
			cin >> x >> y;
			judge[x - 1] = true;
			topology[i][x - 1] = topology[x - 1][i] = y;
		}
		cout << "操作成功" << endl;
		return 0;
	}
}