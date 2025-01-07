// 波动数列

// 观察这个数列：1 3 0 2 -1 1 -2 ...
// 这个数列中后一项总是比前一项增加2或者减少3。

// 栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加a或者减少b的
// 整数数列可能有多少种呢？

// 输入
// 输入的第一行包含四个整数 n s a b，含义如前面说述。
// 输出
// 输出一行，包含一个整数，表示满足条件的方案数。由于这个数很大，请输出方案数除以100000007的余数。

// 输入 4 10 2 3
// 输出 2

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MOD 100000007

int solution = 0;
void backtracking(int n, int s, int a, int b, int *nums, int index, int sum)
{
    if (index == n)
    {
        if (sum == s)
        {
            solution = (solution + 1) % MOD;
        }
        return;
    }

    nums[index] = nums[index - 1] + a;
    backtracking(n, s, a, b, nums, index + 1, sum + nums[index]);
    nums[index] = nums[index - 1] - b;
    backtracking(n, s, a, b, nums, index + 1, sum + nums[index]);
}
int main()
{
    int n, s, a, b;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    int minVal = s / n - (n - 1) * a / 2 - 1;
    int maxVal = s / n + (n - 1) * b / 2 + 2;
    int *nums = malloc(sizeof(int) * n);
    for (int i = minVal; i <= maxVal; i++)
    {
        nums[0] = i;
        backtracking(n, s, a, b, nums, 1, i);
    }
    printf("%d", solution);
}


// 以上使用回溯法，思路正确 逻辑正确 问题在于time limit exceeded
