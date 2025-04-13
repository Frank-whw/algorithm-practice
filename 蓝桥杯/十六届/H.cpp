// 试题 H: 扫地机器人
// 时间限制: 1.0s 内存限制: 256.0MB 本题总分：20 分
// 【问题描述】
// 在一个含有 n 个点 n 条边的无重边无自环的连通无向图中，有一个扫地机
// 器人在执行清扫作业，其中结点 i 的标记 ti ∈ {0, 1} 如果为 1 ，则说明该结点需
// 要进行清扫，扫地机器人在到达这个结点时会顺便进行清扫工作。机器人想知
// 道，如果选定任意结点出发，每条边只能经过一次的话，最多能清扫多少个待
// 清扫结点？
// 【输入格式】
// 输入的第一行包含一个正整数 n 。
// 第二行包含 n 个整数 t1, t2, · · · , tn ，相邻整数之间使用一个空格分隔。
// 接下来 n 行，每行包含两个正整数 ui
// , vi ，用一个空格分隔，表示结点 ui
// 和结点 vi 之间有一条边。
// 【输出格式】
// 输出一行包含一个整数表示答案。
#include <bits/stdc++.h>
using namespace std;
int findp(int *parent, int n, int x)
{
    if (parent[x] != x)
    {
        return parent[x] = findp(parent, n, parent[x]);
    }
    return parent[x];
}
void unite(int *parent, int n, int x, int y)
{
    int rx = findp(parent, n, x);
    int ry = findp(parent, n, y);
    if (rx != ry)
    {
        parent[rx] = ry;
    }
}
bool isConnected(int *parent, int n, int x, int y)
{
    return findp(parent, n, x) == findp(parent, n, y);
}
int main()
{
    int n;
    bool isNeed[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> isNeed[i];
    }
    // 并查集
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        unite(parent, n, x, y);
    }
    
}