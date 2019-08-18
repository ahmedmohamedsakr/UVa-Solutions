#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N =22, M = 1e2+2, OO = 0x3f3f3f3f;
int m,n,sum,v[N],mem[N][M];
string s;

int knapsack(int i=0,int rem=sum)
{
    if(rem==0)return 1;
    if(rem<0||i==n)return 0;

    int & ret=mem[i][rem];
    if(~ret)return ret;
    ret=knapsack(i+1,rem);
    ret+=knapsack(i+1,rem-v[i]);
    return ret;
}

void init()
{
    memset(mem,-1,sizeof mem);
    n=sum=0;
}

int main()
{
    //freopen("o.txt", "w", stdout);
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        init();
        getline(cin,s);
        stringstream in(s);
        while(in>>v[n])sum+=v[n++];
        if(sum&1){puts("NO");continue;}
        sum>>=1;
        puts(knapsack()?"YES":"NO");
    }
    return 0;
}
