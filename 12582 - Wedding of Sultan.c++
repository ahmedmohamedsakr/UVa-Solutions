#include<bits/stdc++.h>
using namespace std;
const int N=27;

int t;
string s;
char parent[N];
vector<char>adj[N];
bool seen[N];

void InsertData(char p,char lp,int i)
{
    while(i<s.size())
    {
        seen[s[i]-'A']=1;
        if(p==s[i])
        {
            p=lp;
            lp=parent[lp-'A'];
            i++;
        }
        else
        {
            adj[p-'A'].push_back(s[i]);
            parent[s[i]-'A']=p;
            lp=p;
            p=s[i];
            i++;
        }
    }
}

void init(int i)
{
    seen[i]=0;
    adj[i].clear();
}
int main()
{
    scanf("%d",&t);
    for(int q=1; q<=t; q++)
    {
        cin>>s;
        printf("Case %d\n",q);
        InsertData(s[0],s[0],1);
        for(int i=0; i<26; ++i)
        {
            if(seen[i])
            {
                char c='A'+i;
                if(c==s[0])printf("%c = %d",c,adj[i].size());
                else printf("%c = %d",c,adj[i].size()+1);
                puts("");
                init(i);
            }
        }
    }
    return 0;
}
