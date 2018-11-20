#include <bits/stdc++.h>

using namespace std;
const int N=20,M=15,OO=0x3f3f3f3f;
int n,cnt,vis[N],ans[N]= {1};
int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool isprime(int a)
{
    for(int x:prime)if(a==x)return 1;
    return 0;
}

void solve(int a=1)
{
    if(a==n)
    {
        if(!isprime(ans[n-1]+1))return;
        printf("1");
        for(int i=1; i<n; ++i)printf(" %d",ans[i]);
        puts("");
        return;
    }
    for(int i=2; i<=n; ++i)
    {
        if(vis[i])continue;
        if(isprime(ans[a-1]+i))
        {
            vis[i]=1;
            ans[a]=i;
            solve(a+1);
            vis[i]=0;
        }
    }

}

int main()
{
    while(~scanf("%d",&n))
    {
        if(cnt++)puts("");
        printf("Case %d:\n",cnt);
        memset(vis,0,sizeof vis);
        solve();
    }
    return 0;
}
