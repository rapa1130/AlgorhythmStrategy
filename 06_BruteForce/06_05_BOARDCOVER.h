#include<stdio.h>
#include<stdlib.h>
//boardcover


// 입력받기

int** board = NULL;
int w,h;

void Input()
{
    
    scanf("%d",&w);
    scanf("%d",&h);
    board = (int**) malloc(w * sizeof(int*));
    for(int i =0;i<w;i++) board[i] = (int*) calloc(h, sizeof(int));

    char ch;
    while(getchar() != '\n');
    for(int i=0;i<w;i++)
    {
        for(int j =0;j<h;j++)
        {
            ch = getchar();
            if(ch == '.')
            {
                board[i][j] = 0;
            }
            else if(ch == '#')
            {
                board[i][j] = 1;
            }
            else
            {
                printf("input error!! \n");
            }
        }
        while(getchar() != '\n');
    }
}
//시도 가능 체크함수

void PrintBoard()
{
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(board[i][j] == 0)
            {
                printf(".");
            }
            else if(board[i][j] == 1){
                printf("#");
            }else{
                printf("?");
            }
        }
        printf("\n");
    }
}


// 4가지 시도를 데이터화하기.
int xDir[4][3]={
    {0,0,-1},
    {0,0,1},
    {0,1,1},
    {0,0,1}
};
int yDir[4][3]=
{
    {0,1,1},
    {0,1,1},
    {0,0,1},
    {0,1,0}
};

int isRightIndex(int x,int y)
{
    return x>=0 && x<h && y>=0 && y<w;
}
//칠해주는/ 지워주는 함수
int Fill(int x, int y, int method,int isFill)
{
    int nextX;
    int nextY;
    int isRight = 1;
    for(int i =0;i<3;i++)
    {
        nextX = x +xDir[method][i];
        nextY = y +yDir[method][i];
        if(isRightIndex(nextX,nextY))
        {
            board[nextY][nextX] += isFill;
            if(board[nextY][nextX]>1) isRight =0;
        }
        else{
            isRight = 0;
        }
    }
    return isRight;
}

// 재귀함수로 처리하는 함수 짜기(방법의 수)

void FindXY(int* x, int* y)
{
    for(int i=0;i<w;i++)
    {
        for(int j = 0;j<h;j++)
        {
            if(board[i][j] > 1)
            {
                *x = -2;
                return;
            }
            if(board[i][j] == 0)
            {
                *x = j;
                *y = i;
                return;
            }
        }
    }
    *x = -1;
    return;
}

int BoardCoverCount()
{
    int x,y;
    FindXY(&x,&y);
    printf("x:%d y:%d \n",x,y);
    if(x == -1) return 1;
    if(x == -2) return 0;

    

    int count = 0;
    for(int i =0; i < 4 ;i++)
    {
        if(Fill(x,y,i,1))
        {
            PrintBoard();
            count += BoardCoverCount();
        }
        Fill(x,y,i,-1);
    }
    return count;
}


