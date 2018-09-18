#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N =1e2+4,M=5e4+3,OO = 0x3f3f3f3f;
int n,m,a[N],total;
int mem[N][M];

int solve(int i=0,int sum=0)
{
    if(i==m)return abs(sum-(total-sum));
    int &ret=mem[i][sum];
    if(~ret)return ret;
    ret=min(solve(i+1,sum),solve(i+1,sum+a[i]));
    return ret;
}

void init()
{
    total=0;
    memset(mem,-1,sizeof mem);
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        init();
        scanf("%d",&m);
        for(int i=0; i<m; ++i)
        {
            scanf("%d",a+i);
            total+=a[i];
        }
        printf("%d\n",solve());
    }

    return 0;
}
