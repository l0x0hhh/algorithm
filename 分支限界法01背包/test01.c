//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//// 优先队列分支限界法求解 0-1 背包问题
//
//// 物品结构体：存储单个物品的重量、价值、编号和单位价值比
//typedef struct {
//    int weight, value, index;   // 重量、价值和原始编号
//    double ratio;               // 价值/重量比，用于排序
//} Item;
//
//// 搜索树节点结构体：表示问题的一个可能状态
//typedef struct {
//    int level;                  // 当前处理的物品层级（深度）
//    int profit;                 // 当前节点的总价值
//    int weight;                 // 当前节点的总重量
//    double bound;               // 当前节点的价值上界（估算的最大可能价值）
//    int* selected;              // 记录当前分支对每个物品的选择情况（1-选择，0-不选）
//} Node;
//
//// 优先队列（最大堆）结构体：用于分支限界法的节点扩展
//typedef struct {
//    Node** data;                // 存储节点指针的数组
//    int size;                   // 当前队列中的节点数量
//    int capacity;               // 队列的最大容量
//} PriorityQueue;
//
//// ----------------- 优先队列实现（最大堆） -----------------
//
//// 创建一个新的优先队列
//PriorityQueue* createPQ(int cap) {
//    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
//    pq->data = (Node**)malloc(sizeof(Node*) * cap);
//    pq->size = 0;
//    pq->capacity = cap;
//    return pq;
//}
//
//// 交换两个节点指针
//void swap(Node** a, Node** b) {
//    Node* t = *a;
//    *a = *b;
//    *b = t;
//}
//
//// 向优先队列中插入一个节点（最大堆维护）
//void push(PriorityQueue* pq, Node* node) {
//    // 队列扩容处理
//    if (pq->size >= pq->capacity) {
//        pq->capacity *= 2;
//        pq->data = (Node**)realloc(pq->data, sizeof(Node*) * pq->capacity);
//    }
//    
//    // 插入新节点到队尾并向上调整堆
//    int i = pq->size++;
//    pq->data[i] = node;
//    while (i > 0) {
//        int p = (i - 1) / 2;  // 父节点索引
//        if (pq->data[p]->bound < pq->data[i]->bound) {
//            swap(&pq->data[p], &pq->data[i]);
//            i = p;
//        }
//        else break;  // 已满足堆性质，停止调整
//    }
//}
//
//// 从优先队列中取出优先级最高的节点（bound值最大的节点）
//Node* pop(PriorityQueue* pq) {
//    if (pq->size == 0) return NULL;
//    
//    // 取出堆顶节点
//    Node* top = pq->data[0];
//    pq->data[0] = pq->data[--pq->size];
//    
//    // 向下调整堆
//    int i = 0;
//    while (1) {
//        int l = 2 * i + 1, r = 2 * i + 2, max = i;
//        // 找出左右子节点中bound值较大的节点
//        if (l < pq->size && pq->data[l]->bound > pq->data[max]->bound) max = l;
//        if (r < pq->size && pq->data[r]->bound > pq->data[max]->bound) max = r;
//        
//        if (max != i) {
//            swap(&pq->data[i], &pq->data[max]);
//            i = max;
//        }
//        else break;  // 已满足堆性质，停止调整
//    }
//    return top;
//}
//
//// ----------------- 分支限界核心算法 -----------------
//
//// 比较函数：用于按单位价值比降序排序物品
//int compareItems(const void* a, const void* b) {
//    return ((Item*)b)->ratio > ((Item*)a)->ratio ? 1 : -1;
//}
//
//// 计算节点的价值上界（贪心策略）
//double calcBound(int level, int weight, int profit, Item* items, int n, int capacity) {
//    if (weight >= capacity) return 0;  // 重量已超限，上界为0
//    
//    double bound = profit;             // 初始上界为当前价值
//    int remain = capacity - weight;    // 剩余容量
//    
//    // 贪心选择剩余物品：优先选择单位价值比高的物品
//    for (int i = level; i < n; i++) {
//        if (items[i].weight <= remain) {
//            // 可以完整放入当前物品
//            remain -= items[i].weight;
//            bound += items[i].value;
//        }
//        else {
//            // 只能放入部分当前物品（计算比例价值）
//            bound += items[i].ratio * remain;
//            break;  // 容量已用完，退出计算
//        }
//    }
//    return bound;
//}
//
//// 分支限界法求解01背包问题
//int* knapsack(int n, int capacity, Item* items, int* maxProfit, int* totalWeight) {
//    // 按单位价值比降序排序物品
//    qsort(items, n, sizeof(Item), compareItems);
//
//    // 初始化优先队列
//    PriorityQueue* pq = createPQ(128);
//
//    // 初始化最优解信息
//    *maxProfit = 0;
//    *totalWeight = 0;
//    int* bestSelected = (int*)calloc(n, sizeof(int));  // 记录最优选择
//
//    // 创建根节点
//    Node* root = (Node*)malloc(sizeof(Node));
//    root->level = 0;                // 从第0层开始（还未选择任何物品）
//    root->profit = 0;               // 初始价值为0
//    root->weight = 0;               // 初始重量为0
//    root->bound = calcBound(0, 0, 0, items, n, capacity);  // 计算根节点的上界
//    root->selected = (int*)calloc(n, sizeof(int));  // 初始选择为空
//    push(pq, root);                 // 将根节点加入队列
//
//    // 主循环：处理优先队列中的节点
//    while (pq->size > 0) {
//        Node* v = pop(pq);          // 取出上界最大的节点
//        
//        // 剪枝条件：如果当前节点的上界不超过已知最优解，则跳过
//        if (v->bound <= *maxProfit || v->level >= n) {
//            free(v->selected);
//            free(v);
//            continue;
//        }
//
//        // ----------- 分支1：选中当前物品 -----------
//        Node* u = (Node*)malloc(sizeof(Node));
//        u->level = v->level + 1;                  // 进入下一层
//        u->weight = v->weight + items[v->level].weight;  // 更新重量
//        u->profit = v->profit + items[v->level].value;  // 更新价值
//        u->selected = (int*)calloc(n, sizeof(int));  // 复制选择状态
//        
//        // 复制父节点的选择状态并添加当前物品
//        for (int i = 0; i < n; i++) u->selected[i] = v->selected[i];
//        u->selected[items[v->level].index - 1] = 1;  // 标记选择当前物品
//
//        // 如果新节点是可行解且价值更高，则更新最优解
//        if (u->weight <= capacity && u->profit > *maxProfit) {
//            *maxProfit = u->profit;
//            *totalWeight = u->weight;
//            for (int i = 0; i < n; i++) bestSelected[i] = u->selected[i];
//        }
//        
//        // 计算新节点的上界
//        u->bound = calcBound(u->level, u->weight, u->profit, items, n, capacity);
//        
//        // 如果上界大于当前最优解，则加入队列继续扩展
//        if (u->bound > *maxProfit) push(pq, u);
//        else {
//            free(u->selected);
//            free(u);
//        }
//
//        // ----------- 分支2：不选当前物品 -----------
//        u = (Node*)malloc(sizeof(Node));
//        u->level = v->level + 1;                  // 进入下一层
//        u->weight = v->weight;                    // 重量不变
//        u->profit = v->profit;                    // 价值不变
//        u->selected = (int*)calloc(n, sizeof(int));  // 复制选择状态
//        
//        // 复制父节点的选择状态
//        for (int i = 0; i < n; i++) u->selected[i] = v->selected[i];
//        
//        // 计算新节点的上界
//        u->bound = calcBound(u->level, u->weight, u->profit, items, n, capacity);
//        
//        // 如果上界大于当前最优解，则加入队列继续扩展
//        if (u->bound > *maxProfit) push(pq, u);
//        else {
//            free(u->selected);
//            free(u);
//        }
//
//        // 释放当前处理完的节点
//        free(v->selected);
//        free(v);
//    }
//
//    // 清理优先队列资源
//    free(pq->data);
//    free(pq);
//    
//    return bestSelected;  // 返回最优选择
//}
//
//// ----------------- 主函数：用户输入输出 -----------------
//
//int main() {
//    int n, capacity;
//
//    // 输入物品数量
//    printf("请输入物品数量: ");
//    if (scanf("%d", &n) != 1 || n <= 0) {
//        printf("错误：物品数量必须是正整数。\n");
//        return 1;
//    }
//
//    // 输入背包容量
//    printf("请输入背包容量: ");
//    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
//        printf("错误：背包容量必须是正整数。\n");
//        return 1;
//    }
//
//    // 分配物品数组内存
//    Item* items = (Item*)malloc(n * sizeof(Item));
//    if (items == NULL) {
//        perror("malloc");
//        return 1;
//    }
//
//    // 输入每个物品的重量和价值
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
//        items[i].index = i + 1;                // 记录原始编号
//        items[i].ratio = (double)items[i].value / items[i].weight;  // 计算单位价值比
//    }
//    Item* items2 = (Item*)malloc(n * sizeof(Item));
//    if (items2 == NULL) {
//        perror("malloc");
//        return 1;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        items2[i].index = items[i].index;
//        items2[i].weight = items[i].weight;
//        items2[i].value = items[i].value;
//        items2[i].ratio = items[i].ratio;
//    }
//    // 调用分支限界法求解背包问题
//    int maxProfit = 0, totalWeight = 0;
//    int* selected = knapsack(n, capacity, items, &maxProfit, &totalWeight);
//
//    // 输出结果
//    printf("\n背包能装入的最大价值: %d\n", maxProfit);
//    printf("选中的物品是:");
//    for (int i = 0; i < n; i++) {
//        if (selected[i]) {
//            printf(" #%d(重量=%d, 价值=%d)", i + 1, items2[i].weight, items2[i].value);
//        }
//    }
//    printf("\n总重量: %d\n", totalWeight);
//
//    // 释放资源
//    free(items);
//    free(selected);
//    return 0;
//}