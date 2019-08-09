#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e6+5,M=1e8+5,OO=0x3f3f3f3f;
int n;
int pf[N],mu[N],freq[N];
void sieve()
{
    memset(mu,-1,sizeof mu);
    mu[1]=1;
    for(int i=2; i<=N; i++)
        if(!pf[i])for(int j=i; j<=N; j+=i){
            int p=0,k=j;
            while(k%i==0){k/=i,++p;}
            if(p>1)mu[j]=0;
            pf[j]+=p;
        }

   for(int i=2;i<=N;++i)if(!(pf[i]%2)&&mu[i]==-1)mu[i]=1;

   for(int i=1;i<=N;++i)freq[i]=freq[i-1]+mu[i];

}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    sieve();

    //for(int i=1;i<21;++i)cout<<i<<" "<<pf[i]<<" "<<" "<<mu[i]<<" "<<freq[i]<<endl;

    while(scanf("%d",&n)==1&&n){
       printf("%8d%8d%8d\n",n,mu[n],freq[n]);
    }
    return 0;
}
