/*
another solution:
you can find the smallest prime which is larger than a
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e6;

int euler[maxn*2+10];
int ans[maxn+10];
void geteuler(){
    memset(ans,0,sizeof(ans));
  memset(euler,0,sizeof(euler));
  euler[1]=1;
  for(int i=2;i<=maxn*2;i++){
    if(!euler[i])
        for(int j=i;j<=maxn*2;j+=i){
          if(!euler[j])
             euler[j]=j;
         euler[j]=euler[j]/i*(i-1);
  }}
   euler[1]=0;int flag=0;
   for(int i=1;i<=maxn*2;i++){
    if(euler[i]>maxn+2) break;
    if(euler[i]>flag) {ans[euler[i]]=i;flag=euler[i];}
   }
}

int main(){
  // freopen("shujv.txt","r",stdin);
   // freopen("out2.txt","w",stdout);
  int t;
  cin>>t;int k=0;
  geteuler();
  while(k<t){
    k++;
    int n;
    cin>>n;ll cnt=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;int t=a;
        while(ans[t]==0){
            t++;
        }
        cnt+=ans[t];
    }
    cout<<"Case "<<k<<": "<<cnt<<" Xukha"<<endl;
  }
  return 0;
}
/*
3
12
2949 18554 16621 524 22014 4140 3009 30226 19871 14949 13564 28909
2953
23225
20785
789
41295
4309
3011
35273
20221
14951
13567
29521
*/
