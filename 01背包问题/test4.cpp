#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_N 100//物品最大数量

int n;						// 物品数量
float capacity;				// 背包容量
float* weights;				// 物品质量数组
float* values;				// 物品价值数组
float current_weight;		// 当前背包质量
float current_value;		// 当前背包价值
float best_value;			// 最优价值
float best_value_weight;	// 最优价值时背包质量
bool solution[MAX_N];		// 当前解
bool best_solution[MAX_N];	// 最优解

void output()
{
	printf("选择的物品: ");
	for (int i = 1; i <= n; i++)
	{
		if (best_solution[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//回溯法
void KnapBacktrack(int i)
{
	if (i > n) {//到了叶子结点
		if (current_value > best_value)
		{
			best_value = current_value;
			best_value_weight = current_weight;
			for (int i = 1; i <= n; i++)
			{
				best_solution[i] = solution[i];// 更新最优解
			}
		}
		return;
	}

	if (current_weight + weights[i] <= capacity)//限界条件//左子树
	{
		solution[i] = true;
		current_weight += weights[i];
		current_value += values[i];

		KnapBacktrack(i + 1);//到下一层

		current_weight-= weights[i];//回退
		current_value -= values[i];

	}
	//尝试不选择第i个物品 右子树 //一定要放出来，不然走不进if里，当前都false不了
	solution[i] = false;
	KnapBacktrack(i + 1);//到下一层
}

int main()
{
	printf("请输入物品数量: ");
	scanf("%d", &n);
	printf("请输入背包容量: ");
	scanf("%f", &capacity);
	values = (float*)malloc(sizeof(float) * (n+1));
	weights = (float*)malloc(sizeof(float) * (n+1));
	if (values == NULL || weights == NULL)
	{
		perror("malloc!");
		exit(1);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("请输入第%d个物品的重量和价值:",i);
		scanf("%f %f", &weights[i], &values[i]);
	}

	// 初始化
	best_value = 0;
	current_weight = 0;
	current_value = 0;
	for (int i = 1; i <= n; i++) {
		solution[i] = false;
		best_solution[i] = false;
	}

	KnapBacktrack(1);

	// 输出最终结果
	printf("\n最优解:\n");
	printf("最大价值: %.2f\n", best_value);
	printf("当前背包质量: %.2f\n", best_value_weight);
	output();

	free(values);
	free(weights);
	return 0;
}