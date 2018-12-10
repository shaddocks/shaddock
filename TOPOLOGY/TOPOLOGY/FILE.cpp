#include"stdafx.h"
#include<iostream>
#include<fstream>
#include"FILE.h"
#include"TOPOLOGY.h"
#define MAX 10000
using namespace std;
void writefile(int node, int a[100][100],bool judge[100]) {
	ofstream out;
	out.open("network.txt");
	if (out) {
		out << node;
		out << endl;
		for (int j = 0; j < node; ++j) {
			for (int k = 0; k < node; ++k) {
				out << a[j][k] << " ";
			}
			out << endl;
		}
		for (int i = 0; i < node; ++i) {
			out << judge[i] << " ";
		}
		out << endl;
		cout << "jiangke";
	}
	out.close();
}
int readfile(int node,int a[100][100],bool judge[100]) {
	int sid;
	int num = 0;
	ifstream in;
	in.open("network.txt");
	if (in) {
		in >> node;
		for (int i = 0; i < node; ++i) {
			for (int j = 0; j < node; ++j) {
				in >> a[i][j];
				a[j][i] = a[i][j];
			}
		}
		for (int i = node; i < 100; ++i) {
			for (int j = node; j < 100; ++j) {
				a[i][j] = a[j][i] = MAX;
			}
		}
		for (int i = 0; i < node; ++i) {
			in >> judge[i];
		}
		for (int i = node; i < 100; ++i) {
			judge[i] = false;
		}
		in.close();
		return node;
	}
	else {
		cout << "打开失败" << endl;
		cout << "请输入路由器的数目: ";
		cin >> node;
		cout << "请输入边的数目: ";
		cin >> sid;
		Gplot(a, node, sid, judge);
		return node;
	}
}
