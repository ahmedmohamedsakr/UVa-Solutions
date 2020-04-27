#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N=2e2+5,M=1e6+5,OO=0x3f3f3f3f;
int m,n,p,from,to,colorZero,colorOne,ans;
bool isBiPartite;
vi adj[N];
int color[N];

void checkBiPartite(int src)
{
    queue<int>q;
    color[src]=0,isBiPartite=1;
    colorZero=1,colorOne=0;
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
                color[it]?colorOne++:colorZero++;
            }
            else if(color[it]==color[u])isBiPartite=0;
        }
    }
}

void init()
{
    for(auto &it:adj)it.clear();
    memset(color,OO,sizeof color);
    ans=0;
}

int main ()
{
    scanf("%d",&m);
    while(m--)
    {
        init();
        scanf(" %d",&n);
        for(from=1; from<=n; ++from)
        {
            scanf("%d",&p);
            for(int j=0; j<p; ++j)
            {
                scanf("%d",&to);
                if(find(adj[from].begin(),adj[from].end(),to)==adj[from].end()&&to<=n)
                {
                    adj[from].push_back(to);
                    adj[to].push_back(from);
                }
            }
        }
        for(int i=1; i<=n; ++i)
        {
            if(color[i]==OO)
            {
                checkBiPartite(i);
                if(isBiPartite)ans+=max(colorZero,colorOne);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
