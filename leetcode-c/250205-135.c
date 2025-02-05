// 135. 分发糖果
// 困难

// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
// 你需要按照以下要求，给这些孩子分发糖果：

// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
int max(int a, int b){
    return a > b ? a : b;
}
int minOne(int* ratings, int ratingSize){
    int min = ratings[0], index = 0;
    for(int i = 1; i < ratingSize; i++){
        if(ratings[i] < min){
            index = i;
            min = ratings[i];
        } 
    }
    return index;
}
int candy(int* ratings, int ratingsSize) {
    // 初始化
    int* candy = malloc(sizeof(int) * ratingsSize);
    for(int i = 0; i < ratingsSize; i++){
        candy[i] = 1;
    }
    // 右孩子 ＞ 左孩子
    for(int i = 1;i < ratingsSize; i++){
        if(ratings[i] > ratings[i - 1]){
            candy[i] = candy[i - 1] + 1;
        }
    }
    // 左孩子 ＞ 有孩子
    // 注意：max->保证同时满足中间大于2边
    for(int i = ratingsSize - 2; i >= 0; i--){
        if(ratings[i] >ratings[i + 1]){
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }
    int count = 0;
    for(int i = 0; i < ratingsSize; i++){
        // printf("%d ", candy[i]);
        count += candy[i];
    }
    return count;
}

// 贪心  
// 本题采用了两次贪心的策略：
// 一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
// 一次是从右到左遍历，只比较左边孩子评分比右边大的情况。