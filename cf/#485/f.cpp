#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7;
int cnt[maxn];
int main(){

  int n;int m;
  while(cin>>n>>m)
{
    memset(cnt,0,sizeof(cnt));
    int b=pow(2,n);
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        cnt[t]++;
        if(cnt[b-t]!=cnt[t]) cnt[b-t]++;
    }
    int ans=m;
    for(int i=0;i<=b;i++){
        if(cnt[i]==2) {ans--;cnt[b-i]=0;}
    }
    cout<<ans<<endl;
}
}
