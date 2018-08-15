#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
map<ll,ll>id;
vector<ll>vec[maxn];
int a[maxn];
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<maxn;i++)
      vec[i].clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        id[a[i]]=0;
        }
    map<ll,ll>::iterator it;
    ll cnt=0;
    for(it=id.begin();it!=id.end();it++){
        it->second=++cnt;
    }
    for(int i=1;i<=n;i++){
       a[i]=id[a[i]];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
     if(a[i]>i){
        vec[a[i]].push_back(i);
        ans+=vec[a[i]].size();
     }
     else{
        for(int j=0;j<vec[i].size();j++){
            int t=vec[i][j];
            if(a[i]>=t) ans++;
        }
     }
    }
    cout<<ans<<endl;

  }
return 0;
}
