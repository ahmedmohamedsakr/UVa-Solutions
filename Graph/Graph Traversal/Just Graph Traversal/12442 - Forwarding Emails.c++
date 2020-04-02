#include<bits/stdc++.h>
using namespace std;
const int N=5e4+3;
int t,n,from,to,ans,numOfChild,maxNumOfChild,cnt;
vector<int>adj[N];
int vis[N];

void dfs(int u)
{
    vis[u]=cnt+1;
    for(int i=0; i<adj[u].size(); ++i)
    {
        int ch=adj[u][i];
        if(vis[ch]!=cnt+1)
        {
            numOfChild++;
            dfs(ch);
        }
    }
}

void init()
{
    memset(vis,0,sizeof vis);
    maxNumOfChild=-1,cnt=1;
    for(int i=1; i<=n; ++i)adj[i].clear();
}

int main()
{
    scanf("%d",&t);
    for(int q=1; q<=t; ++q)
    {
        scanf("%d",&n);
        init();
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",&from,&to);
            adj[from].push_back(to);
        }

        for(int i=1; i<=n; ++i)
        {
            numOfChild=0;
            if(vis[i]!=cnt)
            {
                dfs(i);
                if(maxNumOfChild<numOfChild)maxNumOfChild=numOfChild,ans=i;
                cnt++;
            }
        }
        printf("Case %d: %d\n",q,ans);
    }
    return 0;
}
