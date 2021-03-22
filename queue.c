#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

Queue g_queue[QUEUE_SIZE]; // g means global

int g_rear = -1;
int g_front = -1;

void CopyQData(QData *dest, QData src) //just for safety
{
    stpcpy(dest->name, src.name);
}

bool IsFull(void)
{
    bool result = false;

    if (g_rear == QUEUE_SIZE - 1)
        result = true;

    return result;
}

bool IsEmpty(void)
{
    bool result = false;

    if (g_rear == g_front)
        result = true;

    return result;
}

void EnQueue(QData data)
{
    if (IsFull())
        puts("Enqueue error: queue is full");
    else
        CopyQData(&g_queue[++g_rear].data, data);
}

QData DeQueue(void)
{
    QData dequeued_data = {0};

    if (IsEmpty())
        puts("Dequeue error: queue is emty");
    else
    {
        CopyQData(&dequeued_data, g_queue[++g_front].data);
    }

    return dequeued_data;
}
