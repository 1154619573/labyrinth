#include "head.h"

//1.³õÊ¼»¯Õ»
void InitStack(StType*& s)
{
    s = (StType*)malloc(sizeof(StType));
    s->top = -1;
}

//2.Ïú»ÙÕ»
void DestroyStack(StType*& s)
{
    free(s);
}

//3.ÅĞ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool StackEmpty(StType*& s)
{
    return (s->top == -1);
}

//4.½øÕ»
bool Push(StType*& s, Box e)
{
    if (s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

//5.½øÕ»
bool Pop(StType*& s, Box& e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

//6.È¡Õ»¶¥ÔªËØ
bool GetTop(StType*& s, Box& e)
{
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}