// 452. 用最少数量的箭引爆气球
// 中等

// 有一些球形气球贴在一堵用 XY 平面表示的墙面上。
// 墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

// 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。
// 在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

// 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

int cmp(const void *a, const void *b)
{
    return (*((int **)a))[0] > (*((int **)b))[0];
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    qsort(points, pointsSize, sizeof(points[0]), cmp);
    int result = 1;
    int left = points[0][0], right = points[0][1];
    for (int i = 1; i < pointsSize; i++)
    {
        if (points[i][0] > right)
        {
            left = points[i][0];
            right = points[i][1];
            result += 1;
            continue;
        }
        if (points[i][0] > left && points[i][0] <= right)
        {
            // 如果新的左边界，在[left, right]内
            left = points[i][0];
        }
        if (points[i][1] < right && points[i][1] >= left)
        {
            right = points[i][1];
        }
    }
    return result;
}

// 本题思路还是不够明确，代码实现也比较丑陋
// 核心思路是求并集，求并集前需要对整个数组排序，
// 目的是方便模拟气球被射爆的过程，当遍历跳过这个气球的时候就代表这个气球被射爆了
// 当有了思路之后仍需不断提炼重点，下面附上标答

int cmp(const void *a,const void *b)
{
    return ((*((int**)a))[0] > (*((int**)b))[0]);
} 

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    //将points数组作升序排序
    qsort(points, pointsSize, sizeof(points[0]),cmp);
    
    int arrowNum = 1;
    int i = 1;
    for(i = 1; i < pointsSize; i++) {
        //若前一个气球与当前气球不重叠，证明需要增加箭的数量
        if(points[i][0] > points[i-1][1])
            arrowNum++;
        else
            //若前一个气球与当前气球重叠，判断并更新最小的x_end
            points[i][1] = points[i][1] > points[i-1][1] ? points[i-1][1] : points[i][1];
    }
    return arrowNum;
}