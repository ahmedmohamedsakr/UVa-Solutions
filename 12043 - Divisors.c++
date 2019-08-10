#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+1,M=1e8+5,OO=0x3f3f3f3f;
int numOfDivisor[N],sumOfDivisor[N],t,a,b,k;
ll sumn,sumd;
void sieve()
{

    fill(numOfDivisor,numOfDivisor+N,2);
    iota(sumOfDivisor, sumOfDivisor+N, 0);
    numOfDivisor[1]=1,sumOfDivisor[1]=0;

    for(int i=2; i<=N; ++i)
        for(int j=i+i; j<=N; j+=i)
            numOfDivisor[j]++,sumOfDivisor[j]+=i;
}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        sumd=sumn=0;
        scanf("%d%d%d",&a,&b,&k);
        for(; a<=b; ++a)
            if(!(a%k))sumd+=sumOfDivisor[a]+1,sumn+=numOfDivisor[a];

        printf("%lld %lld\n",sumn,sumd);
    }
    return 0;
}

