#include"stdafx.h"
#include"ADD.h"
#include<iostream>
#define MAX 10000
using namespace std;
int Addside(int topology[100][100], int number, bool judge[100]) {
	int i = 0, j = 0, l = 0;
	cout << "������ڵ�i���ڵ�j�ľ���: " << endl;
	cin >> i >> j >> l;
	i = i - 1; j = j - 1;
	if (l == 0)return 0;
	judge[i] = true;
	judge[j] = true;
	topology[i][j] = topology[j][i] = l;
	cout << "�����ɹ�" << endl;
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
		cout << "��ѡ����1�����ڵ�ǰ�Ŀ���λ����ӣ�2�����ڵ��һλ���: ";
		cin >> w;
		if(w==1){
			int f = 0;
			cout << "��ǰ�ɲ���λ����: ";
			for (int r = 0; r < t; ++r) {
				cout << k[r] + 1 << "  ";
			}
			cout << endl;
			cout << "��������λ��: ";
			cin >> f;
			f = f - 1;
			cout << "�����ӽڵ���صı���Ϊ: ";
			cin >> j;
			if (j == 0)return 0;
			int temp = number;
			++number;
			judge[f] = true;
			cout << "����������ص� " << "�ߵ�Ȩֵ: " << endl;
			for (int m = 0; m < j; ++m) {
				cin >> x >> y;
				judge[x - 1] = true;
				topology[f][x - 1] = topology[x - 1][f] = y;
			}
			cout << "�����ɹ�" << endl;
			return 1;
		}
		if(w==2){
			cout << "���������ڵ������һ���ڵ�" << endl;
			i = number + 1;
			i = i - 1;
			if (judge[i] == true || i == 0) {
				cout << "�������" << endl;
				return 0;
			}
			cout << "�����ӽڵ���صı���Ϊ: ";
			cin >> j;
			if (j == 0)return 0;
			int temp = number;
			++number;
			judge[i] = true;
			cout << "����������ص� " << "�ߵ�Ȩֵ: " << endl;
			for (int m = 0; m < j; ++m) {
				cin >> x >> y;
				judge[x - 1] = true;
				topology[i][x - 1] = topology[x - 1][i] = y;
			}
			cout << "�����ɹ�" << endl;
			return 0;
		}
		cout << "����" << endl;
		return 0;
	}
	else {
		cout << "��������һ���ڵ�" << endl;
		i = number + 1;
		i = i - 1;
		if (judge[i] == true || i == 0) {
			cout << "�������" << endl;
			return 0;
		}
		cout << "�����ӽڵ���صı���Ϊ: ";
		cin >> j;
		if (j == 0)return 0;
		int temp = number;
		++number;
		judge[i] = true;
		cout << "����������ص� " << "�ߵ�Ȩֵ: " << endl;
		for (int m = 0; m < j; ++m) {
			cin >> x >> y;
			judge[x - 1] = true;
			topology[i][x - 1] = topology[x - 1][i] = y;
		}
		cout << "�����ɹ�" << endl;
		return 0;
	}
}