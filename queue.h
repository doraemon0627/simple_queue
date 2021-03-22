#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> //bool is defined here (Since c99)

#define NAME_MAX_SIZE 100
#define QUEUE_SIZE 100

typedef struct _queue_data
{
    char name[NAME_MAX_SIZE];
}QData; // you have to change CopyQData function if you change this

typedef struct _array_queue
{
    QData data;
}Queue;

bool IsFull(void);
bool IsEmpty(void);

void EnQueue(QData data);
QData DeQueue(void);

void CopyQData(QData *dest, QData src);

#endif