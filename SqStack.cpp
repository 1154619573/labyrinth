#include "head.h"

//1.��ʼ��ջ
void InitStack(StType*& s)
{
    s = (StType*)malloc(sizeof(StType));
    s->top = -1;
}

//2.����ջ
void DestroyStack(StType*& s)
{
    free(s);
}

//3.�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StType*& s)
{
    return (s->top == -1);
}

//4.��ջ
bool Push(StType*& s, Box e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

//5.��ջ
bool Pop(StType*& s, Box& e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

//6.ȡջ��Ԫ��
bool GetTop(StType*& s, Box& e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}