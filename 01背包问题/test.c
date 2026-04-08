//#include <stdio.h>
//#include <stdlib.h>
//
//// 物品结构体，包含重量、价值和索引
//typedef struct {
//    int weight;
//    int value;
//    double ratio;  // 价值/重量比
//    int index;     // 原始索引
//} Item;
//
//// 比较函数，用于qsort按单位价值降序排序
//int compare(const void* a, const void* b) {
//    Item* itemA = (Item*)a;
//    Item* itemB = (Item*)b;
//    return (itemA->ratio < itemB->ratio) - (itemA->ratio > itemB->ratio);
//}
//
//// 计算剩余物品的价值上界
//double calculate_bound(int level, int n, int capacity, int current_weight, int current_value, Item* items) {
//    double bound = current_value;
//    int remaining_capacity = capacity - current_weight;
//
//    for (int i = level; i < n && remaining_capacity > 0; i++) {
//        if (items[i].weight <= remaining_capacity) {
//            bound += items[i].value;
//            remaining_capacity -= items[i].weight;
//        }
//        else {
//            // 部分装入计算上界
//            bound += (double)items[i].value * remaining_capacity / items[i].weight;
//            remaining_capacity = 0;
//        }
//    }
//    return bound;
//}
//
//// 回溯函数
//void backtrack(int level, int n, int capacity, int* current_weight, int* current_value,
//    int* best_value, int* current_choice, int* best_choice, Item* items) {
//    // 到达叶子节点，检查是否找到更优解
//    if (level == n) {
//        if (*current_value > *best_value) {
//            *best_value = *current_value;
//            for (int i = 0; i < n; i++) {
//                best_choice[items[i].index] = current_choice[i];
//            }
//        }
//        return;
//    }
//
//    // 计算右子树（不选当前物品）的上界
//    double right_bound = calculate_bound(level + 1, n, capacity, *current_weight, *current_value, items);
//    // 如果右子树可能包含更优解，递归处理
//    if (right_bound > *best_value) {
//        current_choice[level] = 0;
//        backtrack(level + 1, n, capacity, current_weight, current_value, best_value,
//            current_choice, best_choice, items);
//    }
//
//    // 计算左子树（选当前物品）的约束和上界
//    if (*current_weight + items[level].weight <= capacity) {
//        int temp_weight = *current_weight + items[level].weight;
//        int temp_value = *current_value + items[level].value;
//        double left_bound = calculate_bound(level + 1, n, capacity, temp_weight, temp_value, items);
//
//        // 如果左子树可能包含更优解，递归处理
//        if (left_bound > *best_value) {
//            *current_weight = temp_weight;
//            *current_value = temp_value;
//            current_choice[level] = 1;
//            backtrack(level + 1, n, capacity, current_weight, current_value, best_value,
//                current_choice, best_choice, items);
//            // 回溯
//            *current_weight -= items[level].weight;
//            *current_value -= items[level].value;
//        }
//    }
//}
//
//int main() {
//    int n = 3;  // 物品数量
//    int capacity = 30;  // 背包容量
//    Item items[] = {
//        {16, 45, 45.0 / 16.0, 0},
//        {15, 25, 25.0 / 15.0, 1},
//        {15, 25, 25.0 / 15.0, 2}
//    };
//
//    // 按单位价值降序排序
//    qsort(items, n, sizeof(Item), compare);
//
//    int current_weight = 0;
//    int current_value = 0;
//    int best_value = 0;
//
//    // 分配内存存储选择结果
//    int* current_choice = (int*)calloc(n, sizeof(int));
//    int* best_choice = (int*)calloc(n, sizeof(int));
//
//    // 回溯求解
//    backtrack(0, n, capacity, &current_weight, &current_value, &best_value,
//        current_choice, best_choice, items);
//
//    // 输出结果
//    printf("最大价值: %d\n", best_value);
//    printf("选择的物品: ");
//    for (int i = 0; i < n; i++) {
//        if (best_choice[i]) {
//            printf("物品%d ", i + 1);
//        }
//    }
//    printf("\n");
//
//    // 释放内存
//    free(current_choice);
//    free(best_choice);
//
//    return 0;
//}