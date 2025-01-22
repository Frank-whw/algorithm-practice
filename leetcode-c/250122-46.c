// 46. 全排列
// 中等

// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。
// 你可以 按任意顺序 返回答案。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** result;
int* resultSize;
int resultTop;
int* path;
int pathTop;
int* used;

int allUsed(int numsSize){
    for(int i = 0; i < numsSize; i++){
        if(used[i] == 0){
            // if not used
            return 0;
        }
    }
    return 1;
}

void copy(){
    int* temp = malloc(sizeof(int) * pathTop);
    for(int i = 0; i < pathTop; i++){
        temp[i] = path[i];
    }
    resultSize[resultTop] = pathTop;
    result[resultTop++] = temp;
}

void backTracking(int* nums, int numsSize){
    if(allUsed(numsSize)){
        copy();
        return;
    }
    for(int i = 0; i < numsSize; i++){
        if(used[i] == 0){
            used[i] = 1;
            path[pathTop++] = nums[i];
            backTracking(nums, numsSize);
            used[i] = 0;
            pathTop -= 1;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    result = malloc(sizeof(int*) * 10000);
    resultSize = malloc(sizeof(int) * 10000);
    resultTop = pathTop = 0;
    path = malloc(sizeof(int) * numsSize);
    used = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        used[i] = 0;
    }

    backTracking(nums, numsSize);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int*) * resultTop);
    for(int i = 0; i < resultTop; i++){
        (*returnColumnSizes)[i] = resultSize[i];
    }
    return result;

}

// 回溯
// 越来越随心应手了
// 本题无修改 一遍过

// 思路是通过used记录被使用的数字，然后遍历所有的num