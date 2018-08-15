/**
https://www.nowcoder.com/acm/contest/13/E
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>id;
vector<int>pos[100010];
int a[100010];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k){
    for(int i=0;i<n;i++){
        cin>>a[i];
        id[a[i]]=0;
        }
    int tot=0;
    map<int,int>::iterator it;
    for(it=id.begin();it!=id.end();it++)
         it->second=++tot;
    for(int i=0;i<n;i++) a[i]=id[a[i]];
    //for(int i=0;i<n;i++)
      //  cout<<a[i];
    for(int i=0;i<n;i++){
        pos[a[i]].push_back(i);
    }
    //for(int i=1;i<=tot;i++)
      //  cout<<pos[i].size();
    int ans=0;
    for(int i=0;i<n;i++){
        int s=0;
        int j=1;int jishu=1;int cnt=0;
       while(j<pos[i].size()){
        while(cnt<=k&&j<pos[i].size()){
            cnt+=pos[i][j]-pos[i][j-1]-1;
            jishu++;
            j++;
        }
        if(cnt>k) {
           cnt-=pos[i][s+1]-pos[i][s]-1;
           jishu--;
           s++;
        }
        ans=max(ans,jishu);
    }
    }
     cout<<ans<<endl;
}
  return 0;
}
