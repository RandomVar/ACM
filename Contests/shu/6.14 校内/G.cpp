#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2*1e5;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int cnt[maxn+10];
int main(){
  int t;
  cin>>t;
  while(t--){
        memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans=0;

    for(int i=1;i<=maxn;i++){
        if(cnt[i]){
            ans+=cnt[i]/2;
        }
    }
    cout<<ans/2<<endl;
  }

}
