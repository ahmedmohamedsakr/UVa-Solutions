#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5,M=1e6+5,OO=0x3f3f3f3f;
int n,u,v,id,artPointsCount,outEdgeCount;
int vis[N],ids[N],low[N],artPoints[N];
string line;
vector<int>adj[N];

void articulationPoints(int root=1,int current=1,int parent=-1)
{
    if(root==parent)outEdgeCount++;
    vis[current]=1;
    low[current]=ids[current]=++id;
    for(int to:adj[current])
    {
        if(!vis[to])
        {
            articulationPoints(root,to,current);
            low[current]=min(low[current],low[to]);
            if(low[to]>=ids[current])artPoints[current]=1;
        }
        else if(to!=parent)low[current]=min(low[current],ids[to]);
    }

}

int findArtPoints()
{
    artPointsCount=outEdgeCount=id=0;
    articulationPoints();
    artPoints[1]=(outEdgeCount>1);
    for(int i=1; i<=n; ++i)if(artPoints[i])artPointsCount++;
    return artPointsCount;
}


void init()
{
    for(auto &it:adj)it.clear();
    memset(vis,0,sizeof vis);
    memset(low,0,sizeof low);
    memset(ids,0,sizeof ids);
    memset(artPoints,0,sizeof artPoints);
}

int main ()
{
    while(~scanf("%d",&n)&&n)
    {
        init();
        while(~scanf("%d",&u)&&u)
        {
            getline(cin,line);
            istringstream iss(line);
            for(v; iss>>v;)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        printf("%d\n",findArtPoints());
    }

}
