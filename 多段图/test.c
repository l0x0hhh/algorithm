//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//#include <limits.h>
///*
// * 动态规划求解最短路径函数
// * 参数说明：
// *   graph: 邻接矩阵表示的图
// *   n: 顶点数量
// *   source: 源点(0-based)
// *   sink: 汇点(0-based)
// *   shortest_path: 用于返回最短路径的指针
// *   path_length: 用于返回路径长度的指针
// *   shortest_path_cost: 用于返回最短路径成本的指针
// *
// * 设计思路：
// * 1. 使用动态规划思想，dp数组记录到每个顶点的最短距离
// * 2. path数组记录路径前驱节点，用于回溯路径
// * 3. 通过双重循环更新最短距离
// * 4. 最后根据path数组回溯得到完整路径
// */
//void shortest_path_dp(double** graph, int n, int source, int sink, int** shortest_path, int* path_length, double* shortest_path_cost) {
//    // 初始化dp数组和path数组
//    double* dp = (double*)malloc(n * sizeof(double));
//    int* path = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        dp[i] = DBL_MAX;
//        path[i] = -1;
//    }
//    dp[source] = 0.0;  // 源点到自己的距离为0
//
//    // 动态规划计算最短路径
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i != j && graph[i][j] != DBL_MAX) {
//                if (dp[i] + graph[i][j] < dp[j]) {
//                    dp[j] = dp[i] + graph[i][j];
//                    path[j] = i;
//                }
//            }
//        }
//    }
//
//    // 回溯路径
//    *shortest_path = NULL;
//    *path_length = 0;
//    if (dp[sink] != DBL_MAX) {
//        // 计算路径长度
//        int u = sink;
//        int length = 0;
//        while (u != source) {
//            length++;
//            u = path[u];
//        }
//        length++;  // 包括源点
//
//        // 分配内存并存储路径
//        *shortest_path = (int*)malloc(length * sizeof(int));
//        u = sink;
//        for (int i = length - 1; i >= 0; i--) {
//            (*shortest_path)[i] = u + 1;  // 转换为1-based索引
//            u = path[u];
//        }
//        *path_length = length;
//    }
//
//    *shortest_path_cost = dp[sink];
//
//    free(dp);
//    free(path);
//}
//
//int main() {
//    int n, m;
//    printf("请输入顶点数: ");
//    scanf("%d", &n);
//    printf("请输入边数: ");
//    scanf("%d", &m);
//
//    // 初始化邻接矩阵
//    double** graph = (double**)malloc(n * sizeof(double*));
//    for (int i = 0; i < n; i++) {
//        graph[i] = (double*)malloc(n * sizeof(double));
//        for (int j = 0; j < n; j++) {
//            graph[i][j] = DBL_MAX;
//        }
//    }
//
//    // 输入边信息
//    for (int i = 0; i < m; i++) {
//        int u, v;
//        double w;
//        printf("请输入第%d条边及其权重（u, v, weight）: ", i + 1);
//        scanf("%d %d %lf", &u, &v, &w);
//        u--; v--;  // 转换为0-based索引
//        graph[u][v] = w;
//        graph[v][u] = w;  // 无向图
//    }
//
//    int source, sink;
//    printf("请输入源点: ");
//    scanf("%d", &source);
//    printf("请输入汇点: ");
//    scanf("%d", &sink);
//    source--; sink--;  // 转换为0-based索引
//
//    int* shortest_path;
//    int path_length;
//    double shortest_path_cost;
//    shortest_path_dp(graph, n, source, sink, &shortest_path, &path_length, &shortest_path_cost);
//
//    // 输出结果
//    if (path_length > 0) {
//        printf("最短路径: ");
//        for (int i = 0; i < path_length; i++) {
//            printf("%d ", shortest_path[i]);
//        }
//        printf("\n");
//        printf("最短路径成本: %lf\n", shortest_path_cost);
//        free(shortest_path);
//    }
//    else {
//        printf("没有可到达的路径\n");
//    }
//
//    // 释放内存
//    for (int i = 0; i < n; i++) {
//        free(graph[i]);
//    }
//    free(graph);
//
//    return 0;
//}