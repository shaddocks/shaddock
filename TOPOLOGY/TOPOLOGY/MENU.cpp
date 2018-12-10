#include"stdafx.h"
#include<iostream>
#include"MENU.h"
#include"ADD.h"
#include"DELETE.h"
#include"READ.h"
#include"SPF.h"
#include"TOPOLOGY.h"
#include"FILE.h"
#include"MENU.h"
using namespace std;
void Menu(int G[100][100], int num,bool J[100]) {
	system("cls");
	int t = 0;
	int i = 0;
	int m = 0;
	cout << "***************************************" << endl;
	cout << "**********1:显示当前路由表*************" << endl;
	cout << "*************2:删除操作****************" << endl;
	cout << "*************3:增加操作****************" << endl;
	cout << "*************4:退出操作****************" << endl;
	cout << "***************************************" << endl;
	cout << "你的选择: ";
	cin >> i;
	if (i != 1 && i != 2 && i != 3 && i != 4) {
		cout << "错误，按任意键即将返回" << endl;
		getchar();
		getchar();
		Menu(G, num, J);
	}
	/*if (!isdigit(i)) {
		cout << "错误，按任意键即将返回" << endl;
		getchar();
		getchar();
		Menu(G, num, J);
	}*/
	switch(i) {
	case 1:
		cout << "请输入检索路由器: ";
		cin >> m;
		if (m > num) {
			cout << "错误，按任意键即将返回" << endl;
			getchar();
			getchar();
			Menu(G, num, J);
		}
		Spf(G, num, m-1, J); break;
	case 2:
		cout << "1;执行删边操作，2:执行删点操作: ";
		cin >> m;
		if (m != 1 && m != 2) {
			cout << "错误，按任意键即将返回" << endl;
			getchar();
			getchar();
			Menu(G, num, J);
		}
		if (m == 1) {
			Deleteside(G, num, J);
		}
		if (m == 2) {
			Deletenode(G, num, J);
			//--num;
		}
		break;
	case 3:
		cout << "1;执行加边操作，2:执行加点操作: ";
		cin >> m;
		if (m != 1 && m != 2) {
			cout << "错误，按任意键即将返回" << endl;
			getchar();
			getchar();
			Menu(G, num, J);
		}
		if (m == 1) {
			Addside(G, num, J);
		}
		if (m == 2) {
			t=Addnode(G, num, J);
			if(t==0)++num;
		}
		break;
	case 4:
		writefile(num, G, J);
		exit(0);
	}
	getchar();
	getchar();
	Menu(G, num, J);
}