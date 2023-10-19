#include <stdio.h>
#include <malloc.h>

#define MaxSize 50

typedef struct
{
    int i;
    int j;
    int di;
}Box;


typedef struct
{
    Box data[MaxSize]; //�������Ԫ��
    int top;           //ջ��ָ��
}StType;



bool mgpath(int xi, int yi, int xe, int ye);
bool GetTop(StType*& s, Box& e);
bool Pop(StType*& s, Box& e);
bool Push(StType*& s, Box e);
bool StackEmpty(StType*& s);
void DestroyStack(StType*& s);
void InitStack(StType*& s);

