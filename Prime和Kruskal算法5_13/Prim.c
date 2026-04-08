#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

#define MAXV 100 // 最大顶点数

void primMST(int** graph, int vertices)
{
    int* parent = (int*)malloc(vertices * sizeof(int));   // 存储生成树中节点的父节点，即用来告诉你前一个节点是什么
    int* key = (int*)malloc(vertices * sizeof(int));     // 存储节点的键值（连接生成树的最小边权）（就是结点到其他结点的权值弄成数组）
    int* inMST = (int*)calloc(vertices , sizeof(int));   // 标记节点是否已加入生成树

    // 初始化
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0; // 从第0个顶点开始

    // 构建生成树，需要 vertices-1 条边
    for (int count = 0; count < vertices - 1; count++) {

        // 每轮都更新找到当前未加入生成树且键值最小的顶点
        int min_key = INT_MAX, min_index=0;
        for (int v = 0; v < vertices; v++) {//循环一轮找目前最小的顶点
            if (!inMST[v] && key[v] < min_key) {//未加入生成树（天然不会成环）
                min_key = key[v];
                min_index = v;
            }
        }

        inMST[min_index] = 1;  // 将顶点加入生成树

        // 更新 刚刚找到未加入生成树且键值最小的顶点 的相邻顶点的键值
        for (int v = 0; v < vertices; v++) {
            if (graph[min_index][v] && !inMST[v] && graph[min_index][v] < key[v]) {//有边&&未加入生成树&&边权小才更新key数组
                parent[v] = min_index;
                key[v] = graph[min_index][v];
            }
        }
    }

    // 打印最小生成树的边
    printf("Prim算法生成的最小生成树边:\n");
    int total_weight = 0;
    for (int i = 1; i < vertices; i++) {
        printf("边 %d - %d, 权重: %d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("总权重: %d\n", total_weight);

    // 释放内存
    free(parent);
    free(key);
    free(inMST);
}

int main() {
    int vertices=0, edges=0;
    printf("请输入顶点数：");
    scanf("%d", &vertices);
    printf("请输入边数：");
    scanf("%d", &edges);

    //初始化邻接矩阵
    int** graph = (int**)malloc(sizeof(int*) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = (int*)malloc(sizeof(int) * vertices);
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    //输入边的信息
    printf("输入边及其权重（格式：起点 终点 权重）:\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices && w >= 0) {//完善逻辑
            graph[u][v] = w;
            graph[v][u] = w;
        }
        else {
            printf("输入错误: 无效的顶点或权重\n");
            i--; // 重输
        }
    }

    primMST(graph, vertices);

    //释放内存
    for (int i = 0; i < vertices; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
