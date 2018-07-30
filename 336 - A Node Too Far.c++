#include <bits/stdc++.h>

using namespace std;
const int N =1e4+5,OO = 0x3f3f3f3f;
int nc,dis[N],u,v,t,s,use[N],cnt2,cnt3;
vector<int>adj[N];
int bfs(int src)
{
    memset(dis,OO,sizeof dis);
    int cnt=1;
    dis[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int ch:adj[u])
            if(dis[ch]==OO)
            {
                dis[ch]=dis[u]+1;
                if(dis[ch]==t+2)return cnt;
                q.push(ch),cnt++;
            }

    }
    return cnt;
}
void init()
{
    cnt2=0;
    memset(adj,0,sizeof adj);
    memset(use,0,sizeof use);
}
int main()
{

    while(scanf("%d",&nc)==1,nc)
    {
        init();
        for(int i=0; i<nc; ++i)
        {
            scanf("%d%d",&u,&v);
            if(!use[u])cnt2++;
            use[u]=1;
            if(!use[v])cnt2++;
            use[v]=1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(scanf("%d%d",&s,&t)==2)
        {
            if(!t&&!s)break;
            if(use[s])
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cnt3,cnt2-bfs(s),s,t);
            else
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cnt3,cnt2,s,t);

        }

    }

    return 0;
}
