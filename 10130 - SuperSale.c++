#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e3+4,M=35,OO=0x3f3f3f3f;
int tc,n,W[N],P[N],g,a,MP;
int mem[N][M];
int solve(int i=0,int rem=a)
{
    if(rem<0)return -OO;
    if(i==n)return 0;
    int &ret=mem[i][rem];
    if(~ret)return ret;
    ret=solve(i+1,rem);
    ret=max(ret,solve(i+1,rem-W[i])+P[i]);
    return ret;
}

int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)scanf("%d%d",&P[i],&W[i]);
        MP=0;
        scanf("%d",&g);
        for(int i=0; i<g; ++i)
        {
            memset(mem,-1,sizeof mem);
            scanf("%d",&a);
            MP+=solve();
        }
        printf("%d\n",MP);
    }
    return 0;
}
