#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void mem_copy(void *dest, const void *src, int n)
{
    char *cast_dest = (char *)dest;
    char *cast_src = (char *)src;

    for (int i = 0; i < n; i++)
    {
        *(cast_dest + i) = *(cast_src + i);
    }
}

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *queue = malloc(sizeof(Queue));

    queue->length = 0;
    queue->capacity = capacity;
    queue->storage = malloc(sizeof(int) * capacity);

    return queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    // if the len is = capacity double storage
    if (q->capacity == q->length)
    {
        // double capacity
        q->capacity = q->capacity * 2;
        // make a new pointer
        int *new_storage = malloc(q->capacity * sizeof(int));
        // copy old to new
        mem_copy(new_storage, q->storage, q->capacity * sizeof(int));
        // free the old storage
        free(q->storage);
        // add new storage
        q->storage = new_storage;
    }
    *(q->storage + q->length) = item;
    // increase the length
    q->length++;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->length == 0)
    {
        return 0;
    }
    // take off the front
    int val = *(q->storage);
    // shift everything left by one till
    q->length--;
    for (int i = 0; i < q->length; i++)
    {
        *(q->storage + i) = *(q->storage + i + 1);
        if (*(q->storage + i) == NULL)
        {
            break;
        }
    }

    return val;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->storage != NULL)
    {
        free(q->storage);
    }
    if (q != NULL)
    {
        free(q);
    }
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);
    // printf("%p\n", q);
    enqueue(q, 1);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage));
    enqueue(q, 2);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage + 1));
    enqueue(q, 3);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage + 1));
    enqueue(q, 4);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage + 1));
    enqueue(q, 5);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage + 1));
    enqueue(q, 6);
    // printf("cap %i\n", q->capacity);
    // printf("len %i\n", q->length);
    // printf("%d\n", *(q->storage + 1));

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif