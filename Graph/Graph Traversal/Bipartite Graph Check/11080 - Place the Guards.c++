#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N=2e2+5,M=1e6+5,OO=0x3f3f3f3f;
int t,v,e,cntParent,cntChild,from,to,ans;
bool isBiPartite;
vi adj[N];
int color[N];

bool checkBiPartite(int src)
{
    queue<int>q;
    color[src]=0;
    cntParent=1,cntChild=0;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:adj[u])
        {
            if(color[it]==OO)
            {
                color[it]=1-color[u];
                q.push(it);
                color[it]?cntChild++:cntParent++;
            }
            else if(color[it]==color[u])return 0;
        }
    }
    return 1;
}

void init()
{
    for(auto &it:adj)it.clear();
    memset(color,OO,sizeof color);
    ans=0;
    isBiPartite=1;
}

int main ()
{
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&v,&e);
        for(int i=0; i<e; ++i)
        {
            scanf("%d%d",&from,&to);
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        for(int i=0; i<v; ++i)
        {
            if(color[i]==OO)
            {
                if(!checkBiPartite(i))
                {
                    isBiPartite=0;
                    ans=-1;
                    break;
                }
              ans+=(cntParent&&cntChild)?min(cntParent,cntChild):max(cntParent,cntChild);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
