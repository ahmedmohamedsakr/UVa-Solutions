#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N =2e2+2, M = (1<<32), OO = 0x3f3f3f3f;
int n,q,d,m,mem[N][20][11],a[N],cnt1;


int knapsack(ll i=0,ll sum=0,ll cnt=m)
{
    if(cnt==0)
    {
        if(sum==0)return 1;
        return 0;
    }
    if(i>=n)return 0;

    int & ret=mem[i][sum][cnt];
    if(~ret)return ret;
    ret=knapsack(i+1,((sum%d)+d)%d,cnt);
    ret+=knapsack(i+1,((sum%d)+(a[i]%d)+d)%d,cnt-1);
    return ret;
}

int main()
{

    while(~scanf("%d%d",&n,&q)&&(n||q))
    {
        for(int i=0; i<n; ++i)scanf("%d",a+i);
        printf("SET %d:\n",++cnt1);
        for(int i=1; i<=q; ++i)
        {
            memset(mem,-1,sizeof mem);
            scanf("%d%d",&d,&m);
            printf("QUERY %d: %d\n",i,knapsack());

        }
    }

    return 0;
}
