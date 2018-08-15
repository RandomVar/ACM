#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
using namespace std;
const int MAXN=10010;
const int mod=1000000007;
bool notprime[MAXN];
int tot;
int st[20010],nd[20010],ed[20010],val[20010];
vector<int>edge[20010];
void init() {
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
        if(!notprime[i]) {
            if(i>MAXN/i)continue;//防止溢出,或者i,j用long long
        for(int j=i*i;j<MAXN;j+=i)
           notprime[j]=true;}
           notprime[0]=notprime[1]=false;
  }
void dfs(int u,int pre){
  st[u]=tot;
  nd[tot]=u;
  for(int i=0;i<edge[u].size();i++){
    int t=edge[u][i];
    if(t==pre) continue;
    tot++;
    dfs(t,u);
  }
  ed[u]=tot;
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  //cin>>t;
  init();
  while(t--){
    int n,p;
//    cin>>n>>p;
  scanf("%d%d",&n,&p);
  for(int i=0;i<=n;i++)
    edge[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        //cin>>x>>y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    for(int i=1;i<=n;i++)
//        cin>>val[i];
           scanf("%d",&val[i]);
    tot=1;
    dfs(p,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
            int cnt=0;
            if(!notprime[val[i]]) continue;
        for(int j=st[i];j<=ed[i];j++){
            int t=val[nd[j]];
            if(!notprime[t]) continue;
            if(val[i]%t==0){
                cnt++;
            }
        }
    ans=(ans+cnt*i)%mod;
    }
    printf("%lld\n",ans);
//    cout<<ans<<endl;
  }
  return 0;
}
