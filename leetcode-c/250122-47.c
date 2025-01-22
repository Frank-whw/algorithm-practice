// 47. 全排列 II
// 中等

// 给定一个可包含重复数字的序列 nums ，按任意顺序 
// 返回所有不重复的全排列。

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

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

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
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0){
            continue;
        }
        if(used[i] == 0){
            used[i] = 1;
            path[pathTop++] = nums[i];
            backTracking(nums, numsSize);
            used[i] = 0;
            pathTop -= 1;
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    result = malloc(sizeof(int*) * 10000);
    resultSize = malloc(sizeof(int) * 10000);
    resultTop = pathTop = 0;
    path = malloc(sizeof(int) * numsSize);
    used = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        used[i] = 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    backTracking(nums, numsSize);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int*) * resultTop);
    for(int i = 0; i < resultTop; i++){
        (*returnColumnSizes)[i] = resultSize[i];
    }
    return result;

}

// 回溯
// 在46题的基础上加一个树层去重
// 树层去重的逻辑是：在排序好的数组中，通过相邻的节点来判断是否重复使用
