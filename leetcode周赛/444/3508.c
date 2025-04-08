// 3508. 设计路由器
// 请你设计一个数据结构来高效管理网络路由器中的数据包。每个数据包包含以下属性：

// source：生成该数据包的机器的唯一标识符。
// destination：目标机器的唯一标识符。
// timestamp：该数据包到达路由器的时间戳。
// 实现 Router 类：

// Router(int memoryLimit)：初始化路由器对象，并设置固定的内存限制。

// memoryLimit 是路由器在任意时间点可以存储的 最大 数据包数量。
// 如果添加一个新数据包会超过这个限制，则必须移除 最旧的 数据包以腾出空间。
// bool addPacket(int source, int destination, int timestamp)：将具有给定属性的数据包添加到路由器。

// 如果路由器中已经存在一个具有相同 source、destination 和 timestamp 的数据包，则视为重复数据包。
// 如果数据包成功添加（即不是重复数据包），返回 true；否则返回 false。
// int[] forwardPacket()：以 FIFO（先进先出）顺序转发下一个数据包。

// 从存储中移除该数据包。
// 以数组 [source, destination, timestamp] 的形式返回该数据包。
// 如果没有数据包可以转发，则返回空数组。
// int getCount(int destination, int startTime, int endTime)：

// 返回当前存储在路由器中（即尚未转发）的，且目标地址为指定 destination 且时间戳在范围 [startTime, endTime]（包括两端）内的数据包数量。
// 注意：对于 addPacket 的查询会按照 timestamp 的递增顺序进行。

#include <stdbool.h>

typedef struct
{
    int source;
    int destination;
    int timestamp;
} Packet;
typedef struct
{
    Packet *packets;
    int capacity;
    int front;
    int rear;
} Router;

Router *routerCreate(int memoryLimit)
{
    Router *r = malloc(sizeof(Router));
    r->capacity = memoryLimit + 1;
    r->packets = malloc(sizeof(Packet) *( memoryLimit+1));
    r->front = r->rear = 0;
    return r;
}

bool hasSamePacket(Router *obj, int source, int destination, int timestamp)
{
    for (int i = obj->front; i != obj->rear; i = (i + 1) % obj->capacity)
    {
        Packet p = obj->packets[i];
        if (p.source == source && p.destination == destination && p.timestamp == timestamp)
        {
            return 1;
        }
    }
    return 0;
}
int isFull(Router *obj)
{
    return (obj->rear + 1) % obj->capacity == obj->front;
}

bool routerAddPacket(Router *obj, int source, int destination, int timestamp)
{
    if (hasSamePacket(obj, source, destination, timestamp))
    {
        return false;
    }
    if (isFull(obj))
    {
        // 丢弃最老的数据包
        obj->front = (obj->front + 1) % obj->capacity;
    }

    // 插入新数据包（无论是否刚刚删了最旧的）
    Packet p = {source, destination, timestamp};
    obj->packets[obj->rear] = p;
    obj->rear = (obj->rear + 1) % obj->capacity;

    return true;
}
int isEmpty(Router *obj)
{
    return obj->front == obj->rear;
}
int *routerForwardPacket(Router *obj, int *retSize)
{
    if (isEmpty(obj))
    {
        *retSize = 0;
        return NULL;
    }
    Packet p = obj->packets[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    *retSize = 3;
    int *a = malloc(sizeof(int) * 3);
    a[0] = p.source;
    a[1] = p.destination;
    a[2] = p.timestamp;
    return a;
}

int routerGetCount(Router *obj, int destination, int startTime, int endTime)
{
    int count = 0;
    for (int i = obj->front; i != obj->rear; i = (i + 1) % obj->capacity)
    {
        Packet p = obj->packets[i];
        if (p.destination == destination && p.timestamp >= startTime && p.timestamp <= endTime)
        {
            count += 1;
        }
    }
    return count;
}

void routerFree(Router *obj)
{
    free(obj->packets);
    free(obj);
}

/**
 * Your Router struct will be instantiated and called as such:
 * Router* obj = routerCreate(memoryLimit);
 * bool param_1 = routerAddPacket(obj, source, destination, timestamp);

 * int* param_2 = routerForwardPacket(obj, retSize);

 * int param_3 = routerGetCount(obj, destination, startTime, endTime);

 * routerFree(obj);
*/