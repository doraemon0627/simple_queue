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
    if (IsFull()) //if queue is full
        puts("Enqueue error: queue is full");
    else //if not
        CopyQData(&g_queue[++g_rear].data, data);
    /* Does prefix increacement and g_rear will be increased
    
    g_queue will be pointing at the next element which is empty and place that new element will be stored
    
    calls CopyQData to copy data(new element) to queue
    I can just do like : g_queue[++g_rear].data = data but it's less safer than assigning member of structer one-by-one
    
    ex:)
    s1.a = s1.a
    s1.d = s1.d
    
    is more safer than
    
    s1 = s2
    
    */
}

QData DeQueue(void)
{
    QData dequeued_data = {0}; 

    if (IsEmpty()) // if queue is empty
        puts("Dequeue error: queue is emty");
    else//if not
    {
        CopyQData(&dequeued_data, g_queue[++g_front].data);
        /* copies dequeued data(first element in queue) to dqueued_data
        
        Does prefix increacement and g_rear will be increased
        
        g_rear will be pointing at the element(the first element of queue)  which will be dequeued
        and copyqdata will copy dequeued element's data to deququed_data*/
    }
    return dequeued_data; // returns dequeued_data
}
