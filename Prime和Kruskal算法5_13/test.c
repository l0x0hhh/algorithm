#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//利用并查集实现Kruskal
//用到查询（路径压缩）
//用到合并

// 边结构体
typedef struct {
    int u, v, weight; // 边的一个端点u，另一个端点v，权重
} Edge;

// 并查集的find查询操作(找根的操作)
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]); // 路径压缩 将0 <- 1 <- 2 变成 0  这样提高效率  把沿途的每个节点的父节点都设为根节点即可。下一次再查询时，我们就可以省很多事。
                                                                    //    | |
                                                                    //    1 2
    return parent[i];
}

// 并查集的union合并操作  （按秩合并）
void unionSet(int parent[], int rank[], int x, int y) {
    if (x == y) return;//保留这句是更安全、健壮的编程习惯，如果将 unionSet 单独作为工具函数重用（比如别人调用时没判断 x != y），它能自我保护。

    if (rank[x] < rank[y])
        parent[x] = y;
    else if (rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[y] = x;
        rank[x]++;//只有相等才有rank+1。不相等的时候矮的挂高的，那你rank肯定还是高的，没有变化。
    }
}

// 边权重比较函数（升序）
int compareEdges(const void* a, const void* b)
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(Edge* edges, int V, int E)
{
    // 按权重排序所有边
    qsort(edges, E, sizeof(Edge), compareEdges);

    int* rank = (int*)calloc(V, sizeof(int));//用于并查集优化（按秩合并)
    //数组rank[]记录每个根节点对应的树的深度（如果不是根节点，其rank相当于以它作为根节点的子树的深度）。
    //一开始，把所有元素的rank（秩）设为1。合并时比较两个根节点，把rank较小者往较大者上合并。

    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;//每个顶点最开始是自己的父亲（开始自己就是帮派的老大
    }

    int total_weight = 0;
    // 遍历边
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        //这一步还没将edge[i]也就是将边加入结果中，所以找两端点各自老大是不是同一个人，如果是同一个人那么加入这个边就会成环。因此if要 !=
        int set_u = find(parent, u);//一个点帮派的老大
        int set_v = find(parent, v);//另一个点帮派的老大

        if (set_u != set_v) {
            printf("边 %d - %d, 权重: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            unionSet(parent, rank, set_u, set_v);//因为老大不是同一个人所以可以合并，如果不合并那么下一轮找老大就会有问题
            total_weight += edges[i].weight;
        }
    }

    printf("总权重: %d\n", total_weight);

    free(rank);
    free(parent);
}

int main() {
    int V, E;
    printf("请输入顶点数：");
    scanf("%d", &V);
    printf("请输入边数：");
    scanf("%d", &E);

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    printf("输入边及其权重（格式：起点 终点 权重）:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    printf("Kruskal算法生成的最小生成树边:\n");
    kruskalMST(edges, V, E);

    free(edges);
    return 0;
}