#include <bits/stdc++.h>

using namespace std;
#define unsigned long long ull;
const int N =1e3+125, M = 15, OO = 0x3f3f3f3f;
int isComp[N],n,k,mem[190][N][M],vr;
vector<int>v;

void sieve()
{
    isComp[0]=isComp[1]=1;
    for(int i=2; i*i<=N; i+=1+(i&1))
        if(!isComp[i])for(int j=i*i; j<=N; j+=i)isComp[j]=1;

    for(int i=2;i<=N;++i)if(!isComp[i])v.push_back(i);
}

int knapsack(int i=0,int rem=n,int cnt=k)
{
    if(cnt==0){
        if(rem==0)return 1;
        return 0;
    }
    if(i>=vr)return 0;

    int & ret=mem[i][rem][cnt];
    if(~ret)return ret;
    ret=knapsack(i+1,rem,cnt);
    if(rem-v[i]>=0)ret+=knapsack(i+1,rem-v[i],cnt-1);
    return ret;
}

int main()
{

    sieve();
    while(~scanf("%d%d",&n,&k)&&(n||k))
    {
        memset(mem,-1,sizeof mem);
        vr=upper_bound(v.begin(),v.end(),n)-v.begin();
        //cout<<vr<<endl;
        printf("%d\n",knapsack());
    }

    return 0;
}
