#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair{
    int first;
    int second;
};

struct PQ{
    struct pair** heap;
    int size;
    int (*comp)(struct pair*, struct pair*);
};

void swap(struct pair** a, struct pair** b){
    struct pair* temp = *b;
    *b = *a;
    *a = temp;
}

int comp(struct pair* a, struct pair* b){
    return a->first - b->first;
}

struct PQ* initPQ(int (*comp)(struct pair*, struct pair*)){
    struct PQ* queue = malloc(sizeof(struct PQ));
    queue->heap = malloc(100000 * sizeof(struct pair*));
    queue->size = 0;
    queue->comp = comp;
    return queue;
}

void push(struct PQ* queue, struct pair* elm){
    int idx = queue->size;
    queue->heap[idx] = elm;
    queue->size++;

    while (idx > 0 && queue->comp(queue->heap[idx], queue->heap[(idx-1)/2]) < 0){
        swap(&(queue->heap[idx]), &(queue->heap[(idx-1)/2]));
        idx = (idx-1)/2;
    }
}

struct pair* pop(struct PQ* queue){
    if (queue->size == 0){
        return NULL;
    }
    struct pair* min_elm = queue->heap[0];
    queue->size--;
    queue->heap[0] = queue->heap[queue->size];

    int idx = 0;
    while (idx*2+1 < queue->size){
        int lchild = idx*2+1;
        int rchild = idx*2+2;
        int minchild = lchild;
        if (rchild < queue->size && queue->comp(queue->heap[rchild], queue->heap[lchild]) < 0){
            minchild = rchild;
        }
        if (queue->comp(queue->heap[minchild], queue->heap[idx]) < 0){
            swap(&(queue->heap[idx]), &(queue->heap[minchild]));
            idx = minchild;
        } else {
            break;
        }
    }

    return min_elm;
}

int SuperUglyNumber(int n, int* primes, int primesSize){
    int* indices = malloc(primesSize * sizeof(int));
    memset(indices, 0, primesSize * sizeof(int));
    int* dp = malloc(n * sizeof(int));
    dp[0] = 1;
    struct PQ* pq = initPQ(comp);
    for (int i = 0; i < primesSize; ++i) {
        struct pair* elm = malloc(sizeof(struct pair));
        elm->first = primes[i];
        elm->second = i;
        push(pq,elm);
    }
    for (int x = 1; x < n; ){
        struct pair* top = pop(pq);
        int val = top->first, id = top->second;
        if(val != dp[x-1])
            dp[x++]=val;
        indices[id]++;
        struct pair* new_elm = malloc(sizeof(struct pair));
        new_elm->first = primes[id] * dp[indices[id]];
        new_elm->second = id;
        push(pq,new_elm);
    }
    int result = dp[n-1];

    for (int i = 0; i < pq->size; i++)
        free(pq->heap[i]);
    free(pq->heap);
    free(pq);
    free(dp);
    free(indices);

    return result;
}

int solve(){
    int k;
    scanf("%d", &k);
    int n;
    scanf("%d", &n);
    int primes[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &primes[i]);
    int primesSize = sizeof(primes) / sizeof(primes[0]);
    int result = SuperUglyNumber(k, primes, primesSize);
    printf("%d\n", result);
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
