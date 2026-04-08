#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
/*
* 参数说明：
* graph: 邻接矩阵表示的图
* n : 顶点数量
* source : 源点(0 - based)
* sink : 汇点(0 - based)
* shortest_path : 用于返回最短路径的指针
* path_length : 用于返回路径长度的指针
* shortest_path_cost : 用于返回最短路径成本的指针
*/

void shortest_path_dp(int** graph, int n, int source, int sink, int** shortest_path, int* path_length, int* shortest_path_cost)
{
	int* dp = (int*)malloc(sizeof(int) * n);
	int* path = (int*)malloc(sizeof(int) * n);//存前一个节点
	if (dp == NULL)
	{
		perror("malloc");
		exit(1);
	}
	if (path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	//初始化dp数组和path数组
	for (int i = 0; i < n; i++)
	{
		dp[i] = INT_MAX;
		path[i] = -1;
	}
	dp[source] = 0;  // 源点到自己的距离为0

	//动态规划算最小路径
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && graph[i][j] != INT_MAX)// 有边
			{
				if (dp[i]+graph[i][j]<dp[j])
				{
					dp[j] = dp[i] + graph[i][j];
					path[j] = i;
				}
			}
		}
	}

	// 回溯路径
	*shortest_path = NULL;
	*path_length = 0;
	if (dp[sink] != INT_MAX) {
		*shortest_path_cost = dp[sink];//以汇点结束的最短路径

		//求有多少节点
		int length = 0;
		int u = sink;
		while (u != source)
		{
			if (path[u] == -1)
			{
				break;
			}
			u = path[u];
			length++;
		}
		length++;//加上源点

		(*path_length) = length;

		*shortest_path = (int*)malloc(sizeof(int) * length);
		if (*shortest_path == NULL)
		{
			perror("malloc");
			exit(1);
		}
		u = sink;
		for (int i = length - 1; i >= 0; i--)
		{
			(*shortest_path)[i] = u + 1;//转化为数组下标
			u = path[u];
		}

	}
	free(dp);
	free(path);
}

int main() {
	int n, m;
	printf("请输入顶点数: ");
	scanf("%d", &n);
	printf("请输入边数: ");
	scanf("%d", &m);
	
	int** graph = (int**)malloc(sizeof(int*) * n);
	if (graph == NULL)
	{
		perror("malloc");
		exit(1);
	}
	//初始化邻接矩阵
	for (int i = 0; i < n; i++)
	{
		graph[i] = (int*)malloc(sizeof(int) * n);
		if (graph[i] == NULL)
		{
			perror("malloc");
			exit(1);
		}
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = INT_MAX;
		}
	}

	// 输入边信息
	for (int i = 0; i < m; i++) {
		int u, v;
		int w;
		printf("请输入第%d条边及其权重（u, v, weight）: ", i + 1);
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;  // 转换数组下标
		graph[u][v] = w; // 有向图
	}

	int source, sink;
	printf("请输入源点: ");
	scanf("%d", &source);
	printf("请输入汇点: ");
	scanf("%d", &sink);
	source--; sink--;  // 转换数组下标

	int* shortest_path;
	int path_length=0;//路径长度(路径上有多少点)
	int shortest_path_cost=0;//最短路径成本
	shortest_path_dp(graph, n, source, sink, &shortest_path, &path_length, &shortest_path_cost);

	// 输出结果
	if (path_length > 0) {
		printf("最短路径: ");
		for (int i = 0; i < path_length; i++) {
			printf("%d ", shortest_path[i]);
		}
		printf("\n");
		printf("最短路径成本: %d\n", shortest_path_cost);
		free(shortest_path);
	}
	else {
		printf("没有可到达的路径\n");
	}

	// 释放内存
	for (int i = 0; i < n; i++) {
		free(graph[i]);
	}
	free(graph);

	return 0;
}