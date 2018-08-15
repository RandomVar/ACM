#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1100;
vector<int>a;
vector<int>g[maxn];
int n;
ll tree[maxn*maxn];

int lowbit(int x){
return x&(-x);
}
ll sum(int x){//求和
  ll ret=0;
  while(x>0){
    ret+=tree[x];
    x-=lowbit(x);
  }
return ret;
}

void update(int x,int d){//更新节点信息
    if(x<0) return;
   while(x<=n){
    tree[x]+=d;
    x+=lowbit(x);
   }
}

int main(){
//  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  //cin>>t;
  int cas=0;
  while(t--){

    int x,m,k;
    //cin>>x>>m>>k;
   scanf("%d%d%d",&x,&m,&k);
    a.clear();
    for(int i=0;i<=x;i++)
     g[i].clear();
   mem(tree,0);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        //cin>>x>>y;
        g[x].pb(y);
    }
    for(int i=1;i<=x;i++){
            if(g[i].size()==0) continue;
        sort(g[i].begin(),g[i].end());
        for(int j=0;j<g[i].size();j++){
            a.pb(g[i][j]);
        }
    }
   // sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    ll ans=0;
    n=m;
    for(int i=0;i<a.size();i++){
        int c=a[i];
        update(c,1);
        ans+=sum(n)-sum(c);

    }
    printf("Test case %d: %lld\n",++cas,ans);
   // cout<<"Test case "<<++cas<<": ";
    // cout<<ans<<endl;

  }


}
