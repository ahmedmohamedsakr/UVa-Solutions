#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e6+1,M=1e8+5,OO=0x3f3f3f3f;
ll phi[N],m,n,t,freq[N],step[N],num;

void phiSieve()
{
    //memset(step,0,sizeof step);
    iota(phi, phi+N, 0);
    for(ll i = 2 ; i < N ; i += 1 + (i&1))
        if(phi[i] == i)
            for(ll j = i ; j < N ; j+=i)
                phi[j] -= phi[j]/i;
    step[2]=1;
    for(ll i=3; i<N; ++i){
        ll k=phi[i],c=1;
        //while(phi[k]!=1){
            //k=phi[k];
            //num++;
            if(step[k]!=0){c+=step[k];}
           // c++;
        //}
        step[i]=c;
    }

    for(int i=1;i<N;++i)freq[i]=freq[i-1]+step[i];

}

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    phiSieve();
    //cout<<num<<endl;
    //for(int i=2;i<N;++i)cout<<i<<" "<<step[i]<<" "<<phi[i]<<endl;
    //for(int i=0;i<11;++i)cout<<i<<" "<<phi[i]<<" "<<freq[i]<<endl;


    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",freq[m]-freq[n-1]);
    }
    return 0;
}

