/**
打hash表暴力

hash记录i是不是素数

prime记录第i个素数

*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000010;
bool has[MAXN];
int prime[MAXN/10];
void getPrime()//求素数
{
    memset(prime,0,sizeof(prime));
    memset(has,false,sizeof(has));
    for(int i=2;i<=MAXN;i++)
    {
        if(!has[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            has[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main(){
  int t;
  getPrime();
  cin>>t;int tt=0;
 while(t--){
    int n;
   cin>>n;
    int cnt=0;
   for(int i=1;prime[i]<=n/2;i++){
      if(!has[prime[i]]&&!has[n-prime[i]])
        cnt++;
}
  cout<<"Case "<<++tt<<": "<<cnt<<endl;
    //cout<<cnt<<endl;
 }
return 0;
}
