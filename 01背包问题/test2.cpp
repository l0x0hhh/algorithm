//#include <stdio.h>
//#include <stdlib.h>
//
//// 全局变量定义
//float cw = 0.0;    // 当前背包重量
//float cv = 0.0;    // 当前背包价值
//float bestv = 0.0; // 当前最优价值
//int* x;            // 物品选择数组
//int* bestx;        // 最优选择数组
//int n;             // 物品数量
//float c;           // 背包容量
//float* w;          // 物品重量数组
//float* v;          // 物品价值数组
//
//// 回溯函数
//void KnapBacktrack(int i) {
//    if (i > n) { // 搜索到可行解
//        if (cv > bestv) {
//            bestv = cv;
//            for (int j = 1; j <= n; j++) {
//                bestx[j] = x[j];
//            }
//        }
//        return;
//    }
//    else {
//        if (cw + w[i] <= c) { // 走左子树（选择当前物品）
//            x[i] = 1;
//            cw += w[i];
//            cv += v[i];
//            KnapBacktrack(i + 1);
//            cw -= w[i]; // 回溯
//            cv -= v[i];
//        }
//        // 走右子树（不选择当前物品）
//        x[i] = 0;
//        KnapBacktrack(i + 1);
//    }
//}
//
//int main() {
//    // 示例输入数据
//    n = 3;          // 物品数量
//    c = 30.0;       // 背包容量
//    w = (float*)malloc((n + 1) * sizeof(float));
//    v = (float*)malloc((n + 1) * sizeof(float));
//    x = (int*)malloc((n + 1) * sizeof(int));
//    bestx = (int*)malloc((n + 1) * sizeof(int));
//
//    // 初始化物品重量和价值（索引从1开始）
//    w[1] = 16.0; v[1] = 45.0;
//    w[2] = 15.0; v[2] = 25.0;
//    w[3] = 15.0; v[3] = 25.0;
//
//    // 初始化选择数组
//    for (int i = 1; i <= n; i++) {
//        x[i] = 0;
//        bestx[i] = 0;
//    }
//
//    // 调用回溯函数
//    KnapBacktrack(1);
//
//    // 输出结果
//    printf("最大价值: %.2f\n", bestv);
//    printf("选择的物品: ");
//    for (int i = 1; i <= n; i++) {
//        if (bestx[i]) {
//            printf("物品%d ", i);
//        }
//    }
//    printf("\n");
//
//    // 释放内存
//    free(w);
//    free(v);
//    free(x);
//    free(bestx);
//
//    return 0;
//}