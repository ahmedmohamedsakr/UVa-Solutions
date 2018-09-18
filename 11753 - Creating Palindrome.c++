#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N =25,M=1e4+3,OO = 0x3f3f3f3f;
int t,n,k,a[M],ans,cnt;
int mem[M][N][N];

int solve(int i=0,int j=n-1,int p1=0,int p2=0)
{
    if(i>j)return 0;
    int &ret=mem[i][p1][p2];
    if(~ret)return ret;
    if(p1+p2>k)return OO;
    if(a[i]==a[j])return ret=solve(i+1,j-1,p1,p2);
    ret=min(solve(i,j-1,p1+1,p2),solve(i+1,j,p1,p2+1))+1;
    return ret;
}

void init()
{
    memset(mem,-1,sizeof mem);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; ++i)scanf("%d",a+i);
        ans=solve();
        if(ans>k)printf("Case %d: Too difficult\n",++cnt);
        else if(!ans)printf("Case %d: Too easy\n",++cnt);
        else printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}
