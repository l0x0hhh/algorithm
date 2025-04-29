#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define STAGES 4        // 总阶段数
#define NODES 3         // 每阶段最多节点数
#define INF 999999      // 无限大，表示无路径

// G[i][u][v] 表示从阶段 i 的节点 u 到阶段 i+1 的节点 v 的代价
int G[STAGES - 1][NODES][NODES] = {
    { {2, 1, 3}, {INF, 2, 1}, {3, INF, INF} },  // stage 0 -> stage 1
    { {3, 2, 4}, {1, INF, 2}, {2, 1, INF} },    // stage 1 -> stage 2
    { {4, INF, INF}, {2, 3, INF}, {1, 2, INF} } // stage 2 -> stage 3
};

int dp[STAGES][NODES];       // dp[i][u]: 从阶段 i 的节点 u 到终点的最小代价
int path[STAGES][NODES];     // path[i][u]: 从节点 u 最优转移到的下一个节点

// 初始化 DP 数组
void initializeDP() {
    for (int i = 0; i < STAGES; i++) {
        for (int j = 0; j < NODES; j++) {
            dp[i][j] = INF;
            path[i][j] = -1;
        }
    }

    // 最后一阶段的代价为0（终点只有一个节点：0）
    dp[STAGES - 1][0] = 0;
}

// 动态规划求解最小路径
void computeDP() {
    for (int i = STAGES - 2; i >= 0; i--) {
        for (int u = 0; u < NODES; u++) {
            for (int v = 0; v < NODES; v++) {
                if (G[i][u][v] != INF && dp[i][u] > G[i][u][v] + dp[i + 1][v]) {
                    dp[i][u] = G[i][u][v] + dp[i + 1][v];
                    path[i][u] = v;
                }
            }
        }
    }
}

// 输出最优路径
void printPath(int start) {
    printf("最小代价路径：%d", start);
    int current = start;
    for (int i = 0; i < STAGES - 1; i++) {
        if (path[i][current] == -1) break;
        printf(" -> %d", path[i][current]);
        current = path[i][current];
    }
    printf("\n最小总代价为：%d\n", dp[0][start]);
}

int main() {
    initializeDP();
    computeDP();
    printPath(0); // 从起点节点 0 开始
    return 0;
}
