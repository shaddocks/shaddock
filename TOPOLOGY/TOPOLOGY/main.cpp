#include "stdafx.h"
#include<iostream>
#include"TOPOLOGY.h"
#include"FILE.h"
#include"MENU.h"
#define MAX 10000
using namespace std;

int main()
{
	int topology[100][100];
	bool judge[100];
	int node = 0;
	node= readfile(node, topology, judge);
	//Gplot(topology, number, side, judge);
	Menu(topology, node, judge);
	return 0;
	cout << "fg";
}

