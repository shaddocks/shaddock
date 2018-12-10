#include"stdafx.h"
#include<iostream>
#define MAX 10000
#include"SPF.h"
#include"read.h"
using namespace std;
void Spf(int matrix[100][100], int vertex_num, int source, bool judge[100])
{
	bool visited[100];     // 标记数组
	int  dist[100];        // 源点到顶点i的最短距离
	int  path[100];        // 记录最短路的路径
	memset(visited, 0, sizeof(visited));  // 初始化标记数组
	visited[source] = true;
	if (judge[source] == false) {
		cout << "错误" << endl;
		return;
	}//修改
	for (int i = 0; i < vertex_num; i++)
	{
		dist[i] = matrix[source][i];
		path[i] = source;

	}

	int min_cost;        // 权值最小
	int min_cost_index;  // 权值最小的下标

	for (int i = 1; i < vertex_num; i++)  // 找到源点到另外 vertex_num-1 个点的最短路径
	{
		min_cost = MAX;

		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false && dist[j] < min_cost)  // 找到权值最小
			{
				min_cost = dist[j];
				min_cost_index = j;
			}
		}

		visited[min_cost_index] = true;  // 该点已找到，进行标记

		for (int j = 0; j < vertex_num; j++)  // 更新 dist 数组
		{
			if (visited[j] == false &&
				matrix[min_cost_index][j] != MAX &&  // 确保两点之间有边
				matrix[min_cost_index][j] + min_cost < dist[j])
			{
				dist[j] = matrix[min_cost_index][j] + min_cost;
				path[j] = min_cost_index;
			}
		}
	}
	readtable(dist, path, vertex_num, source, judge);
	return;
}