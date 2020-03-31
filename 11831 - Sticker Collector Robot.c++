#include<bits/stdc++.h>
using namespace std;
const int N=104;

int n,m,s,currentI,currentJ,nextI,nextJ,ans,f;
char currentD;
string maze[N];
string t,instructions;
int vis[N][N];

bool valid(int i,int j)
{
    return i<n&&i>=0&&j<m&&j>=0&&maze[i][j]!='#';
}

void startPosition()
{
    if(currentD=='S')nextI=currentI+1,nextJ=currentJ;
    if(currentD=='N')nextI=currentI-1,nextJ=currentJ;
    if(currentD=='O')nextJ=currentJ-1,nextI=currentI;
    if(currentD=='L')nextJ=currentJ+1,nextI=currentI;
}


void excuteInstructions(char c,int i)
{
    if(c=='D')
    {
        if(currentD=='L')nextI=currentI+1,nextJ=currentJ,currentD='S';
        else if(currentD=='N')nextI=currentI,nextJ=currentJ+1,currentD='L';
        else if(currentD=='S')nextI=currentI,nextJ=currentJ-1,currentD='O';
        else if(currentD=='O')nextI=currentI-1,nextJ=currentJ,currentD='N';
    }
    else if(c=='E')
    {
        if(currentD=='L')nextI=currentI-1,nextJ=currentJ,currentD='N';
        else if(currentD=='N')nextI=currentI,nextJ=currentJ-1,currentD='O';
        else if(currentD=='S')nextI=currentI,nextJ=currentJ+1,currentD='L';
        else if(currentD=='O')nextI=currentI+1,nextJ=currentJ,currentD='S';
    }
    else
    {
        if((c=='F'&&c==instructions[i-1]))
        {
            if(currentD=='L')nextJ=currentJ+1;
            if(currentD=='N')nextI=currentI-1;
            if(currentD=='S')nextI=currentI+1;
            if(currentD=='O')nextJ=currentJ-1;
        }
        if(valid(nextI,nextJ))
        {
            if(maze[nextI][nextJ]=='*'&&(currentI!=nextI||currentJ!=nextJ)&&!vis[nextI][nextJ])ans++;
            currentI=nextI,currentJ=nextJ;
            vis[currentI][currentJ]=1;
        }

    }

}


void traverse()
{
    ans=0;
    memset(vis,0,sizeof vis);
    startPosition();
    for(int i=0; i<s; ++i)excuteInstructions(instructions[i],i);
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&s))
    {
        if(!n&&!m&&!s)break;
        for(int i=0; i<n; ++i)cin>>maze[i];

        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(maze[i][j]=='N'||maze[i][j]=='S'||maze[i][j]=='L'||maze[i][j]=='O')
                    currentI=i,currentJ=j,currentD=maze[i][j];
        cin>>instructions;

        traverse();
        printf("%d\n",ans);
    }

    return 0;
}
