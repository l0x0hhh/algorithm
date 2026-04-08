//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MAX_N 100  // 物品最大数量
//
//int n;             // 物品数量
//float capacity;     // 背包容量
//float weights[MAX_N]; // 物品重量数组
//float values[MAX_N];  // 物品价值数组
//float best_value;    // 当前最优价值
//float current_weight; // 当前背包重量
//float current_value;  // 当前背包价值
//bool solution[MAX_N]; // 当前解
//bool best_solution[MAX_N]; // 最优解
//
//// 输出解决方案
//void output_solution(bool best_solution[]) {
//    printf("选择的物品: ");
//    for (int i = 1; i <= n; i++) {
//        if (best_solution[i]) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//}
//
//// 回溯函数
//void KnapBacktrack(int i) {
//    if (i > n) { // 到达叶子节点，找到一个可行解
//        if (current_value > best_value) {
//            best_value = current_value;
//            // 更新最优解
//            for (int j = 1; j <= n; j++) {
//                best_solution[j] = solution[j];
//            }
//            printf("找到一组解: 价值=%.2f\n", best_value);
//            output_solution(best_solution);
//        }
//        return;
//    }
//
//    // 尝试选择第i个物品（左子树）
//    if (current_weight + weights[i] <= capacity) {
//        solution[i] = true;
//        current_weight += weights[i];
//        current_value += values[i];
//
//        KnapBacktrack(i + 1); // 递归进入下一层
//
//        // 回溯，撤销选择
//        current_weight -= weights[i];
//        current_value -= values[i];
//        solution[i] = false;
//    }
//
//    // 尝试不选择第i个物品（右子树）
//    solution[i] = false;
//    KnapBacktrack(i + 1);
//}
//
//int main() {
//    // 输入物品数量和背包容量
//    printf("请输入物品数量: ");
//    scanf("%d", &n);
//    printf("请输入背包容量: ");
//    scanf("%f", &capacity);
//
//    // 输入每个物品的重量和价值（从1开始编号）
//    for (int i = 1; i <= n; i++) {
//        printf("请输入第%d个物品的重量和价值: ", i);
//        scanf("%f %f", &weights[i], &values[i]);
//    }
//
//    // 初始化
//    best_value = 0;
//    current_weight = 0;
//    current_value = 0;
//    for (int i = 1; i <= n; i++) {
//        solution[i] = false;
//        best_solution[i] = false;
//    }
//
//    // 开始回溯搜索
//    KnapBacktrack(1);
//
//    // 输出最终结果
//    printf("\n最优解:\n");
//    printf("最大价值: %.2f\n", best_value);
//    output_solution(best_solution);
//
//    return 0;
//}