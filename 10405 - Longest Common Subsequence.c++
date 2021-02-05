#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
string s1,s2;
int mem[N][N];
int LCS(int i=0,int j=0){
   if(i==s1.size()||j==s2.size())return 0;
   int &ret=mem[i][j];
   if(~ret)return ret;
   if(s1[i]==s2[j])return ret=LCS(i+1,j+1)+1;
   return ret=max(LCS(i+1,j),LCS(i,j+1));
}
int main(){
    while(getline(cin,s1)){
        getline(cin,s2);
        memset(mem,-1,sizeof mem);
        cout<<LCS()<<endl;
    }
    return 0;
} 
