#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int MAXN=10010;
const int mod=1000000007;
bool notprime[MAXN];
ll ans;
int val[20010];
vector<int>edge[20010];
int cnt[MAXN];
vector<int>f[MAXN];
void init() {
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
        if(!notprime[i]) {
            if(i>MAXN/i)continue;//·ÀÖ¹Òç³ö,»òÕßi,jÓÃlong long
        for(int j=i*i;j<MAXN;j+=i)
           notprime[j]=true;}
        notprime[0]=notprime[1]=false;
    for(int i=4;i<MAXN;i++){
        if(notprime[i]){
            for(int j=i;j<MAXN;j+=i)
                f[j].pb(i);
        }
    }
  }

void dfs(int u,int pre){

  ll ans1=0;
  int t=val[u];
  for(int i=0;i<f[t].size();i++){
    ans1+=cnt[f[t][i]];
  }
  //cout<<ans1<<endl;
  cnt[t]++;
  for(int i=0;i<edge[u].size();i++){
    int t=edge[u][i];
    if(t==pre) continue;
    dfs(t,u);
  }
   ll ans2=0;
   for(int i=0;i<f[t].size();i++){
    ans2+=cnt[f[t][i]];
  }
  //cout<<ans1<<" "<<ans2<<endl;
  ans=(ans+(ans2-ans1)*u)%mod;
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  //cin>>t;
  init();
  //cout<<f[10000].size()<<endl;
  while(t--){
    int n,p;
  scanf("%d%d",&n,&p);
  for(int i=0;i<=n;i++)
    edge[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        edge[x].pb(y);
        edge[y].pb(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    mem(cnt);
    ans=0;
    dfs(p,0);
    printf("%lld\n",ans);
  }
  return 0;
}
