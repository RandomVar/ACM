#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int cnt[250];
int main(){
  int t;
  cin>>t;
  while(t--){
    queue<int>que;
    int n,k;cin>>n>>k;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        cnt[x]=1;
        que.push(x);
        }
        int ans=1;
    while(!que.empty()){
        int e=que.front();
        que.pop();
        if(e+1<=n&&!cnt[e+1]){
            cnt[e+1]=cnt[e]+1;
            que.push(e+1);
           ans=cnt[e+1];
        }
        if(e-1>0&&!cnt[e-1]){
            cnt[e-1]=cnt[e]+1;
            que.push(e-1);
            ans=cnt[e-1];
        }
    }
    cout<<ans<<endl;
  }
}
