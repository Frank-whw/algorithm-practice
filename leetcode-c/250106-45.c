// 45. 跳跃游戏 II
// 中等

// 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
// 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。
// 换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
// 0 <= j <= nums[i]
// i + j < n
// 返回到达 nums[n - 1] 的最小跳跃次数。
// 生成的测试用例可以到达 nums[n - 1]。

// 示例 1:
// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
// 从下标为 0 跳到下标为 1 的位置，跳 1 步，
// 然后跳 3 步到达数组的最后一个位置。

// typedef struct pair
// {
//     int i;
//     int value;
// } pair;
// typedef struct MyQueue
// {
//     pair val[10000];
//     int front;
//     int rear;
// } MyQueue;
// MyQueue *InitMq()
// {
//     MyQueue *mq = malloc(sizeof(MyQueue));
//     mq->front = mq->rear = 0;
//     return mq;
// }
// void push(MyQueue *mq, pair value)
// {
//     mq->val[mq->rear] = value;
//     mq->rear++;
// }
// pair peek(MyQueue *mq)
// {
//     return mq->val[mq->front];
// }
// pair pop(MyQueue *mq)
// {
//     pair val = peek(mq);
//     mq->front++;
//     return val;
// }
// int isEmpty(MyQueue *mq)
// {
//     return mq->rear == 10001;
// }

// int jump(int *nums, int numsSize)
// {
//     MyQueue *mq = InitMq();
//     pair p = {0, nums[0]};
//     push(mq, p);
//     int count = 0;
//     while (!isEmpty(mq))
//     {
//         int size = mq->rear - mq->front;
//         count += 1;
//         for(int s = 0; s < size; s++){
//             pair p = pop(mq);
//             printf("s:%d i:%d nums[i]:%d\n", s, p.i, p.value);
//             for (int j = 1; j < p.value; j++)
//             {
//                 int reach = p.i + j;
//                 if (reach >= numsSize - 1)
//                     return count;
//                 pair p = {reach, nums[reach]};
//                 push(mq, p);
//             }
//         }
        
//     }
//     return count;
// }


// 一开始用bfs的类似方法去做，应该是没有问题，但是时间复杂度太高了


int jump(int* nums, int numsSize) {
    if(numsSize == 1){
        return 0;
    }   
    int range = nums[0], start = 1;
    int step = 1;
    while(range < numsSize - 1){
        int temp = range;
        for(int i = start; i <= range; i++){
            temp = fmax(temp, i + nums[i]);
        }
        range = temp;
        step += 1;
    }
    return step;
}

// 现在的思路是：
// 用range记录当前的覆盖的最远距离，temp记录接下来可覆盖的最远距离