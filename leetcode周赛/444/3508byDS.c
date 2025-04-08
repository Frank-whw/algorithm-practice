#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int source;
    int destination;
    int timestamp;
} Packet;

typedef struct HashNode {
    Packet key;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode** table;
    int size;
} HashSet;

typedef struct {
    Packet* packets;
    int capacity;
    int front;
    int rear;
    HashSet* set;
} Router;

unsigned int hash(Packet key, int tableSize) {
    unsigned int h = 0;
    h = (h * 31 + key.source) % tableSize;
    h = (h * 31 + key.destination) % tableSize;
    h = (h * 31 + key.timestamp) % tableSize;
    return h % tableSize;
}

bool contains(HashSet* set, Packet key) {
    unsigned int index = hash(key, set->size);
    HashNode* node = set->table[index];
    while (node != NULL) {
        if (node->key.source == key.source && node->key.destination == key.destination && node->key.timestamp == key.timestamp) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void insert(HashSet* set, Packet key) {
    unsigned int index = hash(key, set->size);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = set->table[index];
    set->table[index] = newNode;
}

bool delete(HashSet* set, Packet key) {
    unsigned int index = hash(key, set->size);
    HashNode** ptr = &(set->table[index]);
    while (*ptr != NULL) {
        HashNode* current = *ptr;
        if (current->key.source == key.source && current->key.destination == key.destination && current->key.timestamp == key.timestamp) {
            *ptr = current->next;
            free(current);
            return true;
        }
        ptr = &(current->next);
    }
    return false;
}

HashSet* createHashSet(int size) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->size = size;
    set->table = (HashNode**)calloc(size, sizeof(HashNode*));
    return set;
}

void freeHashSet(HashSet* set) {
    for (int i = 0; i < set->size; i++) {
        HashNode* node = set->table[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(set->table);
    free(set);
}

Router* routerCreate(int memoryLimit) {
    Router* obj = (Router*)malloc(sizeof(Router));
    obj->capacity = memoryLimit + 1;
    obj->packets = (Packet*)malloc(sizeof(Packet) * obj->capacity);
    obj->front = 0;
    obj->rear = 0;
    obj->set = createHashSet(1000003);
    return obj;
}

bool routerAddPacket(Router* obj, int source, int destination, int timestamp) {
    Packet key = {source, destination, timestamp};
    if (contains(obj->set, key)) {
        return false;
    }
    if ((obj->rear + 1) % obj->capacity == obj->front) {
        Packet old = obj->packets[obj->front];
        delete(obj->set, old);
        obj->front = (obj->front + 1) % obj->capacity;
    }
    obj->packets[obj->rear] = key;
    insert(obj->set, key);
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

int* routerForwardPacket(Router* obj, int* retSize) {
    if (obj->front == obj->rear) {
        *retSize = 0;
        return NULL;
    }
    Packet p = obj->packets[obj->front];
    delete(obj->set, p);
    obj->front = (obj->front + 1) % obj->capacity;
    int* result = (int*)malloc(3 * sizeof(int));
    result[0] = p.source;
    result[1] = p.destination;
    result[2] = p.timestamp;
    *retSize = 3;
    return result;
}

int routerGetCount(Router* obj, int destination, int startTime, int endTime) {
    int count = 0;
    int i = obj->front;
    while (i != obj->rear) {
        Packet p = obj->packets[i];
        if (p.timestamp > endTime) {
            break;
        }
        if (p.destination == destination && p.timestamp >= startTime && p.timestamp <= endTime) {
            count++;
        }
        i = (i + 1) % obj->capacity;
    }
    return count;
}

void routerFree(Router* obj) {
    free(obj->packets);
    freeHashSet(obj->set);
    free(obj);
}