// 2368. 受限条件下可到达节点的数目
// 题目难度Medium

// 现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。
// 给你一个二维整数数组 edges ，长度为 n - 1 ，
// 其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。
// 另给你一个整数数组 restricted 表示 受限 节点。
// 在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。
// 注意，节点 0 不 会标记为受限节点。

typedef struct MyQueue
{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} MyQueue;
MyQueue *InitQueue(int capacity)
{
    MyQueue *mq = malloc(sizeof(MyQueue));
    mq->data = malloc(sizeof(int) * capacity);
    mq->front = mq->rear = mq->size = 0;
    mq->capacity = capacity;
    return mq;
}
void push(MyQueue *mq, int val)
{
    mq->data[mq->rear] = val;
    mq->rear = (mq->rear + 1) % mq->capacity;
    mq->size += 1;
}
int pop(MyQueue *mq)
{
    int val = mq->data[mq->front];
    mq->size -= 1;
    mq->front = (mq->front + 1) % mq->capacity;
    return val;
}

int isInRestrict(int target, int *restricted, int restrictedSize)
{
    for (int i = 0; i < restrictedSize; i++)
    {
        if (target == restricted[i])
        {
            return 1;
        }
    }
    return 0;
}
int reachableNodes(int n, int **edges, int edgesSize, int *edgesColSize, int *restricted, int restrictedSize)
{
    // count记录可以到达的节点数量
    int count = 0;
    // 初始化visited
    int *visited = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // 链表矩阵
    int **table = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        table[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            table[i][j] = 0;
        }
    }

    // 读取edges
    for (int i = 0; i < n - 1; i++)
    {
        int a = edges[i][0], b = edges[i][1];
        table[a][b] = 1;
        table[b][a] = 1;
    }

    // 开始遍历
    MyQueue *mq = InitQueue(n);
    push(mq, 0);
    count += 1;
    visited[0] = 1;
    while (mq->size)
    {
        int size = mq->size;
        for (int i = 0; i < size; i++)
        {
            int point = pop(mq);
        
            for(int i = 0 ; i < n; i++){
                if(visited[i] == 0 && table[point][i] == 1 && !isInRestrict(i, restricted, restrictedSize)){
                    // 如果i没有被visit，而且point和i之间有连接+这个节点不是受限节点
                    printf("push: %d\n", i);
                    push(mq, i);
                    visited[i] = 1;
                    count += 1;
                }
            }
        }
    }
    return count;
}