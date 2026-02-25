#include<iostream>
#include<vector>
using namespace std;

void PrintPicked(const vector<int>& picked)
{
    for(int i = 0;i<picked.size();i++)
    {
        cout<<picked[i]<<" ";
    }
    cout<<endl;
}

void _pick(int n,int k, vector<int>& picked)
{
    if(picked.size() == k)
    {
        PrintPicked(picked);
        return;
    }

    int nowPicked = picked.empty() ? 0 : picked.back() + 1;
    for(int i = nowPicked; i < n; i++)
    {
        picked.push_back(i);
        _pick(n,k,picked);
        picked.pop_back();
    }
}
void Pick(int n,int k)
{
    vector<int> picked;
    _pick(n,k,picked);
}

