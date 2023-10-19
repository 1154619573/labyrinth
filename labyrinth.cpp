#include "head.h"

int mg[6][6] =
{
    {1,1,1,1,1,1},{1,0,0,0,1,1},
    {1,0,1,0,0,1},{1,0,0,0,1,1},
    {1,1,0,0,0,1},{1,1,1,1,1,1}
};

bool mgpath(int xi, int yi, int xe, int ye)  //���:(xi,yi)�յ�:(xe,ye)
{
    Box path[MaxSize], e;       //���Թ�·��
    int i, j, di, i1, j1, k;         //i��j��ʾ��ǰ��λ��,i1��j1��ʾ��һ��λ��
    bool find;
    StType * st;
    InitStack(st);
    e.i = xi; e.j = yi; e.di = -1;    //����eΪ���
    Push(st, e);
    mg[xi][yi] = -1;
    while (!StackEmpty(st))      //ջ�ǿ�ʱѭ��
    {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;
        if (i == xe && j == ye)
        {
            printf("һ���Թ�·������:\n");
            k = 0;              //k��ʾ·���еķ�����
            //��ջ���������¼��path��
            while (!StackEmpty(st))
            {
                Pop(st, e);
                path[k++] = e;
            }
            while (k > 0)            //���·��
            {
                printf("\t(%d,%d)", path[k - 1].i, path[k - 1].j);
                k--;
            }
            printf("\n");
            DestroyStack(st);
            return true;
        }
        //��ջ���������п��ܵ�·��
        find = false;
        while (di < 3 && !find)
        {
            di++;
            switch (di)
            {
            case 0:i1 = i - 1; j1 = j; break;
            case 1:i1 = i; j1 = j + 1; break;
            case 2:i1 = i + 1; j1 = j; break;
            case 3:i1 = i; j1 = j - 1; break;
            }
            
            if (mg[i1][j1] == 0) find = true;
        }
        if (find)   //����һ������Ԫ����ջ
        {
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di = -1;
            Push(st, e);
            mg[i1][j1] = -1;
        }
        else      //û�п���Ԫ�أ�����ʱ��Ԫ����ջ
        {
            Pop(st, e);
            mg[e.i][e.j] = 0;
        }
    }
    DestroyStack(st);
    return false;
}