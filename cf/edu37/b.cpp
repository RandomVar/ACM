#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int cnt[1010];
int l[1010],r[1010];
int main(){
  int t;cin>>t;
  while(t--){
    //queue<int>que;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    int i=1;int time=1;
     //int f=i;
   /* while(i<=n){
        time++;
      while(time==l[i]){
         que.push(i);i++;
        }
    }*/
    time=1;
    for(int x=1;x<=n;x++){
        if(l[x]>time) {time++;x--;continue;}
        if(r[x]<time) cnt[x]=0;
        else cnt[x]=time++;
    }
    for(int j=1;j<n;j++)
        cout<<cnt[j]<<" ";
    cout<<cnt[n]<<endl;
  }

}
