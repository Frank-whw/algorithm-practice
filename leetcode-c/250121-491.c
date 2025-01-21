// 491. 非递减子序列
// 中等

// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，
// 递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// int **result;
// int *resultSize;
// int resultTop;
// int *path;
// int pathTop;
// int* used;

// void copy()
// {
//     // printf("re");
//     int *temp = malloc(sizeof(int) * pathTop);
//     for (int i = 0; i < pathTop; i++)
//     {
//         temp[i] = path[i];
//     }
//     resultSize[resultTop] = pathTop;
//     result[resultTop++] = temp;
// }

// void backtracking(int *nums, int numsSize, int startIndex)
// {
//     if (pathTop >= 2)
//     {
//         copy();
//     }
//     for (int i = startIndex + 1; i < numsSize; i++)
//     {

//         if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0){
//             continue;
//         }
//         // printf("i:%d nums[i]:%d lastnum:%d\n", i, nums[i], path[pathTop - 1]);
//         if (i > 0 && nums[i] >= path[pathTop - 1])
//         {
//             path[pathTop++] = nums[i];
//             used[i] = 1;
//             backtracking(nums, numsSize, i);
//             pathTop -= 1;
//             used[i] = 0;
//         }
//     }
//     return;
// }

// int **findSubsequences(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
// {
//     result = malloc(sizeof(int *) * 100000);
//     resultSize = malloc(sizeof(int) * 100000);
//     resultTop = 0;
//     path = malloc(sizeof(int) * numsSize);
//     pathTop = 0;
//     used = malloc(sizeof(int) * numsSize);
//     for(int i = 0; i < numsSize; i++){
//         used[i] = 0;
//     }
//     for(int i = 0 ; i < numsSize - 1; i++){
//         path[pathTop++] = nums[i];
//         used[i] = 1;
//         backtracking(nums, numsSize, i);
//         used[i] = 0;
//         pathTop -= 1;
//     }

//     *returnSize = resultTop;

//     *returnColumnSizes = malloc(sizeof(int*) * resultTop);
//     for(int i = 0 ; i < resultTop; i++){
//         (*returnColumnSizes)[i] = resultSize[i];
//     }
//     return result;
// }


// 去重逻辑：同一父节点下的同层上使用过的元素不能再使用
// 以上代码不能通过[1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
// 原因在于：在后5个1中，前4个1和后4个1 都会组成相同的子集，比如1 11 111 1111，单纯用used数组无法做到彻底的去重
// used的前提是要数组有序，重复的元素在一起 比如输入[4,6,4,7]，输出为[[4,6],[4,6,7],[4,4],[4,4,7],[4,7],[6,7],[4,7]]




int* path;
int pathTop;
int** ans;
int ansTop;
int* length;
//将当前path中的内容复制到ans中
void copy() {
    int* tempPath = (int*)malloc(sizeof(int) * pathTop);
    memcpy(tempPath, path, pathTop * sizeof(int));
    length[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

//查找uset中是否存在值为key的元素
int find(int* uset, int usetSize, int key) {
    int i;
    for(i = 0; i < usetSize; i++) {
        if(uset[i] == key)
            return 1;
    }
    return 0;
}

void backTracking(int* nums, int numsSize, int startIndex) {
    //当path中元素大于1个时，将path拷贝到ans中
    if(pathTop > 1) {
        copy();
    }
    int* uset = (int*)malloc(sizeof(int) * numsSize);
    int usetTop = 0;
    int i;
    for(i = startIndex; i < numsSize; i++) {
        //若当前元素小于path中最后一位元素 || 在树的同一层找到了相同的元素，则continue
        if((pathTop > 0 && nums[i] < path[pathTop - 1]) || find(uset, usetTop, nums[i]))
            continue;
        //将当前元素放入uset
        uset[usetTop++] = nums[i];
        //将当前元素放入path
        path[pathTop++] = nums[i];
        backTracking(nums, numsSize, i + 1);
        //回溯
        pathTop--;
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //辅助数组初始化
    path = (int*)malloc(sizeof(int) * numsSize);
    ans = (int**)malloc(sizeof(int*) * 33000);
    length = (int*)malloc(sizeof(int*) * 33000);
    pathTop = ansTop = 0;

    backTracking(nums, numsSize, 0);

    //设置数组中返回元素个数，以及每个一维数组的长度
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int i;
    for(i = 0; i < ansTop; i++) {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}

// 正确思路：使用uset来去重，逻辑是判断nums[i]在本层是否被使用过
// 与used最大的区别在于：used只能检测相邻的数字是否被用过，只适用于排序后的数组
