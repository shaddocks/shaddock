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
	cout << "**********1:��ʾ��ǰ·�ɱ�*************" << endl;
	cout << "*************2:ɾ������****************" << endl;
	cout << "*************3:���Ӳ���****************" << endl;
	cout << "*************4:�˳�����****************" << endl;
	cout << "***************************************" << endl;
	cout << "���ѡ��: ";
	cin >> i;
	if (i != 1 && i != 2 && i != 3 && i != 4) {
		cout << "���󣬰��������������" << endl;
		getchar();
		getchar();
		Menu(G, num, J);
	}
	/*if (!isdigit(i)) {
		cout << "���󣬰��������������" << endl;
		getchar();
		getchar();
		Menu(G, num, J);
	}*/
	switch(i) {
	case 1:
		cout << "���������·����: ";
		cin >> m;
		if (m > num) {
			cout << "���󣬰��������������" << endl;
			getchar();
			getchar();
			Menu(G, num, J);
		}
		Spf(G, num, m-1, J); break;
	case 2:
		cout << "1;ִ��ɾ�߲�����2:ִ��ɾ�����: ";
		cin >> m;
		if (m != 1 && m != 2) {
			cout << "���󣬰��������������" << endl;
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
		cout << "1;ִ�мӱ߲�����2:ִ�мӵ����: ";
		cin >> m;
		if (m != 1 && m != 2) {
			cout << "���󣬰��������������" << endl;
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