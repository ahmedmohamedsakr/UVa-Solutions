#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N =33, M = 1e3+2, OO = 0x3f3f3f3f;
int t,w,n,d[N],v[N],p[N],mem[N][M],f;
vector<pair<int,int> >vii;

int knapsack(int i=0,int rem=t)
{
    if(rem<0)return -OO;
    if(i==n)return 0;

    int & ret=mem[i][rem];
    if(~ret)return ret;
    ret=knapsack(i+1,rem);
    ret=max(ret,knapsack(i+1,rem-p[i])+v[i]);
    return ret;
}

void printSolution(int i=0,int rem=t)
{
    if(rem<0||i==n)return;

    int ret=knapsack(i,rem);

    if(ret==knapsack(i+1,rem))printSolution(i+1,rem);
    else vii.push_back({d[i],v[i]}),printSolution(i+1,rem-p[i]);

}

void init()
{
    vii.clear();
    memset(mem,-1,sizeof mem);
}

int main()
{
    //freopen("o.txt", "w", stdout);
    while(~scanf("%d%d%d",&t,&w,&n))
    {
        init();
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",d+i,v+i);
            p[i]=3*w*d[i];
        }
        if(f)puts("");
        f=1;
        printf("%d\n",knapsack());
        printSolution();
        printf("%d\n",vii.size());
        for(int i=0; i<vii.size(); ++i)printf("%d %d\n",vii[i].first,vii[i].second);
    }
    return 0;
}
