//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
////BFS 队列实现
//
//typedef struct {
//    int weight, value;
//    double ratio;
//    int index;
//} Item;
//
//typedef struct Node {
//    int level;       // 当前扩展到的物品下标
//    int weight;      // 当前总重量
//    int profit;      // 当前总价值
//    double bound;    // 当前结点的价值上界
//    int* selected;   // 当前物品选择情况（1 表示选，0 表示不选）
//    struct Node* next; // 用于普通队列（链式队列）
//} Node;
//
//// 计算从当前结点开始向下的最大可能价值（上界），用于剪枝
//double calculateBound(int level, int weight, int profit, int capacity, Item* items, int n) {
//    if (weight >= capacity) return 0;
//
//    double bound = profit;
//    int totalWeight = weight;
//
//    for (int i = level; i < n; i++) {
//        if (totalWeight + items[i].weight <= capacity) {
//            totalWeight += items[i].weight;
//            bound += items[i].value;
//        }
//        else {
//            int remain = capacity - totalWeight;
//            bound += items[i].ratio * remain;
//            break;
//        }
//    }
//    return bound;
//}
//
//// 按性价比排序
//int compareItems(const void* a, const void* b) {
//    Item* x = (Item*)a;
//    Item* y = (Item*)b;
//    return y->ratio - x->ratio > 0 ? 1 : -1;
//}
//
//// 队列基本操作
//typedef struct {
//    Node* front;
//    Node* rear;
//} Queue;
//
//void enqueue(Queue* q, Node* node) {
//    node->next = NULL;
//    if (q->rear) q->rear->next = node;
//    else q->front = node;
//    q->rear = node;
//}
//
//Node* dequeue(Queue* q) {
//    if (!q->front) return NULL;
//    Node* temp = q->front;
//    q->front = temp->next;
//    if (!q->front) q->rear = NULL;
//    return temp;
//}
//
//int* knapsackBFS(int n, int capacity, Item* items, int* maxProfit, int* totalWeight) {
//    qsort(items, n, sizeof(Item), compareItems);
//
//    Queue q = { NULL, NULL };
//    Node* root = (Node*)malloc(sizeof(Node));
//    root->level = 0;
//    root->weight = 0;
//    root->profit = 0;
//    root->bound = calculateBound(0, 0, 0, capacity, items, n);
//    root->selected = (int*)calloc(n, sizeof(int));
//    root->next = NULL;
//
//    enqueue(&q, root);
//    *maxProfit = 0;
//    int* bestSelected = (int*)calloc(n, sizeof(int));
//
//    while (q.front) {
//        Node* node = dequeue(&q);
//        if (node->level >= n) {
//            free(node->selected);
//            free(node);
//            continue;
//        }
//
//        int level = node->level;
//        // 构造“选该物品”的子结点
//        if (node->weight + items[level].weight <= capacity) {
//            Node* with = (Node*)malloc(sizeof(Node));
//            with->level = level + 1;
//            with->weight = node->weight + items[level].weight;
//            with->profit = node->profit + items[level].value;
//            with->selected = (int*)malloc(n * sizeof(int));
//            for (int i = 0; i < n; i++) with->selected[i] = node->selected[i];
//            with->selected[items[level].index - 1] = 1;
//            with->bound = calculateBound(with->level, with->weight, with->profit, capacity, items, n);
//            if (with->profit > *maxProfit) {
//                *maxProfit = with->profit;
//                *totalWeight = with->weight;
//                for (int i = 0; i < n; i++) bestSelected[i] = with->selected[i];
//            }
//            if (with->bound > *maxProfit) enqueue(&q, with);
//            else {
//                free(with->selected);
//                free(with);
//            }
//        }
//
//        // 构造“不选该物品”的子结点
//        Node* without = (Node*)malloc(sizeof(Node));
//        without->level = level + 1;
//        without->weight = node->weight;
//        without->profit = node->profit;
//        without->selected = (int*)malloc(n * sizeof(int));
//        for (int i = 0; i < n; i++) without->selected[i] = node->selected[i];
//        without->bound = calculateBound(without->level, without->weight, without->profit, capacity, items, n);
//        if (without->bound > *maxProfit) enqueue(&q, without);
//        else {
//            free(without->selected);
//            free(without);
//        }
//
//        free(node->selected);
//        free(node);
//    }
//
//    return bestSelected;
//}
//
//// 主函数（输入、输出模仿格式）
//int main() {
//    int n, capacity;
//
//    printf("请输入物品数量: ");
//    if (scanf("%d", &n) != 1 || n <= 0) {
//        printf("错误：物品数量必须是正整数。\n");
//        return 1;
//    }
//
//    printf("请输入背包容量: ");
//    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
//        printf("错误：背包容量必须是正整数。\n");
//        return 1;
//    }
//
//    Item* items = (Item*)malloc(n * sizeof(Item));
//
//    printf("\n请输入每个物品的重量和价值：\n");
//    for (int i = 0; i < n; i++) {
//        printf("物品 #%d:\n  重量: ", i + 1);
//        if (scanf("%d", &items[i].weight) != 1 || items[i].weight <= 0) {
//            printf("错误：重量必须是正整数。\n");
//            free(items);
//            return 1;
//        }
//        printf("  价值: ");
//        if (scanf("%d", &items[i].value) != 1 || items[i].value <= 0) {
//            printf("错误：价值必须是正整数。\n");
//            free(items);
//            return 1;
//        }
//        items[i].ratio = (double)items[i].value / items[i].weight;
//        items[i].index = i + 1;
//    }
//
//    int maxProfit = 0, totalWeight = 0;
//    int* bestSelected = knapsackBFS(n, capacity, items, &maxProfit, &totalWeight);
//
//    printf("\n背包能装入的最大价值: %d\n", maxProfit);
//    printf("选中的物品是:");
//    for (int i = 0; i < n; i++) {
//        if (bestSelected[i]) {
//            printf(" #%d(重量=%d, 价值=%d)", i + 1, items[i].weight, items[i].value);
//        }
//    }
//    printf("\n总重量: %d\n", totalWeight);
//
//    free(items);
//    free(bestSelected);
//    return 0;
//}
