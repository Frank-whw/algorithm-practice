// 406. 根据身高重建队列
// 中等

// 提示
// 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
// 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，
// 前面 正好 有 ki 个身高大于或等于 hi 的人。

// 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
// 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *p1, const void *p2)
{
    int *pp1 = *(int **)p1;
    int *pp2 = *(int **)p2;
    return pp1[0] == pp2[0] ? pp1[1] - pp2[1] : pp2[0] - pp1[0];
}
void moveBack(int **nums, int numsSize, int start, int end)
{
    for (int i = end; i > start; i--)
    {
        nums[i] = nums[i - 1];
    }
}
int **reconstructQueue(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes)
{
    qsort(people, peopleSize, sizeof(int *), cmp);
    for (int i = 0; i < peopleSize; i++)
    {
        int position = people[i][1];
        int *temp = people[i];
        moveBack(people, peopleSize, position, i);
        people[position] = temp;
    }

    *returnSize = peopleSize;
    *returnColumnSizes = malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return people;
}

// 2个维度 h和k
// 涉及到多个维度的题，一定是要先限制一个维度，不能同时兼顾 会顾此失彼