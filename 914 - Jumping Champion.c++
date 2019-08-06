#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e6+5,M=1e8+5,OO=0x3f3f3f3f;
int t,l,u,f,maxi,ans;
vector<int>v;
int isComp[N],freq[N];
void sieve()
{
    isComp[0]=isComp[1]=1;
    for(int i=2; i*i<=N; ++i)
        if(!isComp[i])for(int j=i*i; j<=N; j+=i)isComp[j]=1;

    for(int i=2; i<=N; ++i)if(!isComp[i])v.push_back(i);
}

int main()
{
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        memset(freq,0,sizeof freq);
        f=maxi=ans=0;
        scanf("%d%d",&l,&u);
        l=lower_bound(v.begin(),v.end(),l)-v.begin();
        u=upper_bound(v.begin(),v.end(),u)-v.begin()-1;
        
        if(u>l)
        {
            for(int i=l+1; i<=u; ++i)
            {
                int j=v[i]-v[i-1];
                freq[j]++;
                if(freq[j]>maxi)maxi=freq[j],ans=j,f=0;
                else if(freq[j]==maxi)f=1;
            }
        }
        else f=1;

        if(!f)printf("The jumping champion is %d\n",ans);
        else printf("No jumping champion\n");

    }


    return 0;
}
