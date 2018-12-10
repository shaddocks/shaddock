#include"stdafx.h"
#include<iostream>
#define MAX 10000
#include"SPF.h"
#include"read.h"
using namespace std;
void Spf(int matrix[100][100], int vertex_num, int source, bool judge[100])
{
	bool visited[100];     // �������
	int  dist[100];        // Դ�㵽����i����̾���
	int  path[100];        // ��¼���·��·��
	memset(visited, 0, sizeof(visited));  // ��ʼ���������
	visited[source] = true;
	if (judge[source] == false) {
		cout << "����" << endl;
		return;
	}//�޸�
	for (int i = 0; i < vertex_num; i++)
	{
		dist[i] = matrix[source][i];
		path[i] = source;

	}

	int min_cost;        // Ȩֵ��С
	int min_cost_index;  // Ȩֵ��С���±�

	for (int i = 1; i < vertex_num; i++)  // �ҵ�Դ�㵽���� vertex_num-1 ��������·��
	{
		min_cost = MAX;

		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false && dist[j] < min_cost)  // �ҵ�Ȩֵ��С
			{
				min_cost = dist[j];
				min_cost_index = j;
			}
		}

		visited[min_cost_index] = true;  // �õ����ҵ������б��

		for (int j = 0; j < vertex_num; j++)  // ���� dist ����
		{
			if (visited[j] == false &&
				matrix[min_cost_index][j] != MAX &&  // ȷ������֮���б�
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