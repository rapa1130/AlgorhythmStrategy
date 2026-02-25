#pragma once
#include<string>
#include<iostream>
using namespace std;

char board[5][5]=
{
    {'U','R','L','P','M'},
    {'X','P','R','E','T'},
    {'G','I','A','E','T'},
    {'X','T','N','Z','Y'},
    {'X','O','Q','R','S'}
};

int dirX[8] = {-1,0,1,1,1,0,-1,-1};
int dirY[8] = {-1,-1,-1,0,1,1,1,0};

bool isRange(int x,int y)
{
    return x>=0 && x<5 && y>=0 && y<5;
}

bool HasWord(int x,int y,const string& word)
{
    if(!isRange(x,y)) return false;
    if(board[y][x] != word.front()) return false;
    if(word.size() == 1) return true;
    
    for(int i =0;i<8;i++)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];
        if(HasWord(nextX,nextY,word.substr(1))) return true;
    }

    return false;
}