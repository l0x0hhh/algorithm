#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define STAGES 4        // �ܽ׶���
#define NODES 3         // ÿ�׶����ڵ���
#define INF 999999      // ���޴󣬱�ʾ��·��

// G[i][u][v] ��ʾ�ӽ׶� i �Ľڵ� u ���׶� i+1 �Ľڵ� v �Ĵ���
int G[STAGES - 1][NODES][NODES] = {
    { {2, 1, 3}, {INF, 2, 1}, {3, INF, INF} },  // stage 0 -> stage 1
    { {3, 2, 4}, {1, INF, 2}, {2, 1, INF} },    // stage 1 -> stage 2
    { {4, INF, INF}, {2, 3, INF}, {1, 2, INF} } // stage 2 -> stage 3
};

int dp[STAGES][NODES];       // dp[i][u]: �ӽ׶� i �Ľڵ� u ���յ����С����
int path[STAGES][NODES];     // path[i][u]: �ӽڵ� u ����ת�Ƶ�����һ���ڵ�

// ��ʼ�� DP ����
void initializeDP() {
    for (int i = 0; i < STAGES; i++) {
        for (int j = 0; j < NODES; j++) {
            dp[i][j] = INF;
            path[i][j] = -1;
        }
    }

    // ���һ�׶εĴ���Ϊ0���յ�ֻ��һ���ڵ㣺0��
    dp[STAGES - 1][0] = 0;
}

// ��̬�滮�����С·��
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

// �������·��
void printPath(int start) {
    printf("��С����·����%d", start);
    int current = start;
    for (int i = 0; i < STAGES - 1; i++) {
        if (path[i][current] == -1) break;
        printf(" -> %d", path[i][current]);
        current = path[i][current];
    }
    printf("\n��С�ܴ���Ϊ��%d\n", dp[0][start]);
}

int main() {
    initializeDP();
    computeDP();
    printPath(0); // �����ڵ� 0 ��ʼ
    return 0;
}
