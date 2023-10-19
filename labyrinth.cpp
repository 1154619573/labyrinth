#include "head.h"

int mg[6][6] =
{
    {1,1,1,1,1,1},{1,0,0,0,1,1},
    {1,0,1,0,0,1},{1,0,0,0,1,1},
    {1,1,0,0,0,1},{1,1,1,1,1,1}
};

bool mgpath(int xi, int yi, int xe, int ye)  //起点:(xi,yi)终点:(xe,ye)
{
    Box path[MaxSize], e;       //出迷宫路径
    int i, j, di, i1, j1, k;         //i、j表示当前的位置,i1、j1表示下一个位置
    bool find;
    StType * st;
    InitStack(st);
    e.i = xi; e.j = yi; e.di = -1;    //设置e为入口
    Push(st, e);
    mg[xi][yi] = -1;
    while (!StackEmpty(st))      //栈非空时循环
    {
        GetTop(st, e);
        i = e.i; j = e.j; di = e.di;
        if (i == xe && j == ye)
        {
            printf("一条迷宫路径如下:\n");
            k = 0;              //k表示路径中的方块数
            //出栈并将坐标记录到path中
            while (!StackEmpty(st))
            {
                Pop(st, e);
                path[k++] = e;
            }
            while (k > 0)            //输出路线
            {
                printf("\t(%d,%d)", path[k - 1].i, path[k - 1].j);
                k--;
            }
            printf("\n");
            DestroyStack(st);
            return true;
        }
        //入栈：遍历所有可能的路线
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
        if (find)   //将下一个可走元素入栈
        {
            st->data[st->top].di = di;
            e.i = i1; e.j = j1; e.di = -1;
            Push(st, e);
            mg[i1][j1] = -1;
        }
        else      //没有可走元素，将此时的元素退栈
        {
            Pop(st, e);
            mg[e.i][e.j] = 0;
        }
    }
    DestroyStack(st);
    return false;
}