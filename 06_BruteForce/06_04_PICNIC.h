#pragma once
#include<iostream>
using namespace std;

bool isFriend[10][10]={false};
int _lineCount(int n,bool isPicked[10]);
void Play();
int LineCount(int n);

void Play()
{
    int testcase;
    cin>>testcase;
    while(testcase-- > 0)
    {
        int n;
        int r;
        cin>>n>>r;

        for(int i =0;i<n;i++)
        {
            fill_n(isFriend[i],n,false);
        }
        int firstPair,secondPair;
        for(int i=0;i<r;i++){
            cin>> firstPair>>secondPair;
            isFriend[firstPair][secondPair] = isFriend[secondPair][firstPair] = true;
        }
        cout<<LineCount(n)<<endl;
    }
}

int _lineCount(int n,bool isPicked[10])
{
    int nextFirst = -1;
    for(int i =0; i < n; i++)
    {
        if(!isPicked[i]){
            nextFirst = i;
            break;
        }
    }
    if(nextFirst == -1) return 1;

    int count = 0;
    for(int pairWith = nextFirst + 1; pairWith<n; pairWith++)
    {
        if(!isPicked[pairWith] && isFriend[nextFirst][pairWith])
        {
            isPicked[nextFirst] = isPicked[pairWith] = true;
            count += _lineCount(n, isPicked);
            isPicked[nextFirst] = isPicked[pairWith] = false;
        }            
    }
    return count;
}

//피드백: 문제를 2개의 아이를 선택한 뒤 나머지 부분문제로 쪼개지 못했음. 한참 못풀고 답지 봄


int LineCount(int n)
{
    bool isPicked[10] = {false};
    return _lineCount(n,isPicked);
}

