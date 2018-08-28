#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5,M=1e6+5,OO=0x3f3f3f3f;
int tc,n,s,cur,pre,total,mini,ans;
int use[N],dis[N],in[N];
vector<int>imp;
vector<int>adj[N];

void BFS(int src)
{
    memset(dis,OO,sizeof dis);
    queue<int>q;
    q.push(src);
    dis[src]=0;
    total=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(in[u]>1)total+=dis[u];
        for(auto it:adj[u])if(dis[it]==OO)dis[it]=dis[u]+1,q.push(it);
    }
}
int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&s);
        for(int i=1; i<=n; ++i)
        {
            in[i]=0;
            adj[i].clear();
        }
        for(int i=0; i<s; i++)
        {
            scanf("%d",&cur);
            in[cur]++;
            pre=cur;
            while(~scanf("%d",&cur),cur)
            {
                in[cur]++;
                adj[cur].push_back(pre);
                adj[pre].push_back(cur);
                pre=cur;
            }
        }
        mini=OO;
        for(int i=1; i<=n; ++i)
        {
            if(in[i]>1)
            {
                BFS(i);
                if(total<mini){
                    mini=total;
                    ans=i;
                }
            }
        }
        printf("Krochanska is in: %d\n",ans);
    }
    return 0;
}
