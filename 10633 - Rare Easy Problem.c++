
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N =1e4+1,M=1e9,OO = 0x3f3f3f3f;
ll c,s,e;

int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    while(scanf("%lld",&c)==1&&c)
    {
                                 //9x+y=c
       //a=9,d=10,b=1;               //when-> d=gcd(9,1)=1   x=0,y=1    -> multiply left and right by c x=0*c ,y=1*c d=1*9
                       //x=0,y=c;
       s=e=c*10/9;    //s=e=y*d/a;
      for(;s-s/10==c;--s);
      s++;
      if(s<=e){
            printf("%lld",s);
      for(ll n=s+1;n<=e;++n){
        //x0=x+n;  x0=0+n;
        printf(" %lld",n);
      }
     puts("");
    }
    }

    return 0;
}
