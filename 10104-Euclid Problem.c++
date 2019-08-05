#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,M=10,OO=0x3f3f3f3f;
int x,y,d,A,B;
void extendedEuclid(int a,int b){
 if(b==0){x=1,y=0,d=a;return;}
 extendedEuclid(b,a%b);
 int temp=x;
 x=y;
 y=temp-a/b*y;
}

int main()
{
   while(scanf("%d%d",&A,&B)==2){
    extendedEuclid(A,B);
    printf("%d %d %d\n",x,y,d);
   }
    return 0;
}
