// 455 分发饼干
// 简单
// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
// 但是，每个孩子最多只能给一块饼干。
// 对每个孩子 i，都有一个胃口值 g[i]，
// 这是能让孩子们满足胃口的饼干的最小尺寸；
// 并且每块饼干 j，都有一个尺寸 s[j] 。
// 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，
// 这个孩子会得到满足。
// 你的目标是满足尽可能多的孩子，并输出这个最大数值。

// 小饼干先喂给小胃口
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    if (sSize == 0)
        return 0;
    // 将2个数组排序为升序
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int numFedChildren = 0;
    int i;
    for (i = 0; i < sSize; ++i)
    {
        if (numFedChildren < gSize && g[numFedChildren] <= s[i])
        {
            numFedChildren++;
        }
    }
    return numFedChildren;
}

// 贪心算法
// 外循环是饼干的饱腹值，从小到大，如果饱腹值>=孩子的胃口，则+1
// 有意思的点：可以把i定义在循坏外面，便于调试 && ++i可能在性能上有一丢丢优势（在复杂的数据结构中，如迭代器），因为i++会创建一个临时对象
// 注意：cmp要定义成一个函数指针，接受2个const void*类型的参数