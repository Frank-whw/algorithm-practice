// 133. 克隆图
// 中等

// 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
// 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
// 测试用例格式：
// 简单起见，每个节点的值都和它的索引相同。
// 例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。
// 该图在测试用例中使用邻接列表表示。
// 邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
// 给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

typedef struct MyQueue
{
    struct Node *data[100];
    int front;
    int rear;
} MyQueue;
MyQueue *InitQueue()
{
    MyQueue *mq = malloc(sizeof(MyQueue));
    mq->front = mq->rear = 0;
    return mq;
}
struct Node *peek(MyQueue *mq)
{
    return mq->data[mq->front];
}
void push(MyQueue *mq, struct Node *node)
{
    mq->data[mq->rear] = node;
    mq->rear = (mq->rear + 1) % 100;
}

struct Node *pop(MyQueue *mq)
{
    struct Node *node = peek(mq);
    mq->front = (mq->front + 1) % 100;
    return node;
}
int isEmpty(MyQueue *mq)
{
    return mq->rear == mq->front;
}
struct Node *cloneGraph(struct Node *s)
{
    if (!s)
        return NULL;
    // 哈希表，用于记录原节点到克隆节点的映射
    struct Node *hashTable[101] = {NULL};
    struct Node *startClone = malloc(sizeof(struct Node));
    startClone->val = s->val;
    startClone->numNeighbors = 0;
    startClone->neighbors = malloc(sizeof(struct Node *) * s->numNeighbors);
    hashTable[s->val] = startClone;
    // 初始化队列
    MyQueue *mq = InitQueue();
    push(mq, s);
    // BFS遍历
    while (!isEmpty(mq))
    {
        struct Node *current = pop(mq);
        struct Node *currentClone = hashTable[current->val]; // 找到对应的克隆节点
        for (int i = 0; i < current->numNeighbors; i++)
        {
            struct Node *neighbour = current->neighbors[i];

            // 如果邻居还未被克隆
            if (!hashTable[neighbour->val])
            {
                struct Node *neighbourClone = malloc(sizeof(struct Node));
                neighbourClone->val = neighbour->val;
                neighbourClone->numNeighbors = 0;
                neighbourClone->neighbors = malloc(sizeof(struct Node *) * neighbour->numNeighbors);
                hashTable[neighbour->val] = neighbourClone;
                push(mq, neighbour);
            }

            // 建立克隆之间的邻居关系
            currentClone->neighbors[currentClone->numNeighbors++] = hashTable[neighbour->val];
        }
    }
    return startClone;
}

// bfs
// 题目挺抽象，初看不知道要干嘛
// 这边需要一个哈希表visited用于存储原节点到新节点的映射。