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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=50010;
struct node{
 int x,w;

};
vector<node>edge[maxn];
int dp[maxn][3];
int ans[maxn][20][2];
void dfs1(int root,int pre){
	for(int i=0;i<edge[root].size();i++)
	{
		int x=edge[root][i].x;
		if(x==pre) continue;
		dfs1(x,root);
		int cost=dp[x][0]+edge[root][i].w;
		if(cost>=dp[root][0]){
			swap(cost,dp[root][0]);
			dp[root][1]=cost;
		}
		else if(cost>dp[root][1]){
			dp[root][1]=cost;
		}
	}
}
void dfs2(int root,int pre){
	for(int i=0;i<edge[root].size();i++){
		int x=edge[root][i].x;
		int w=edge[root][i].w;
		if(x==pre) continue;
		dp[x][2]=max(dp[root][2],dp[x][0]+w==dp[root][0]?dp[root][1]:dp[root][0])+w;
		dfs2(x,root);
	}
}
void ST(int n) {
    for(int i=1;i<=n;i++)
        ans[i][0][0]=ans[i][0][1]=max(dp[i][0],dp[i][2]);
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
               ans[i][j][0] = max(ans[i][j - 1][0], ans[i + (1 << (j - 1))][j - 1][0]);
              ans[i][j][1] = min(ans[i][j - 1][1], ans[i + (1 << (j - 1))][j - 1][1]);
             //cout<<ans[i][j][0]<<" "<<ans[i][j][1]<<endl;
        }
    }
}
int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;

    return max(ans[l][k][0],ans[r - (1 << k) + 1][k][0])-min(ans[l][k][1], ans[r - (1 << k) + 1][k][1]);
}
int main(){
  int n,m;
  while(cin>>n>>m&&n&&m){
    for(int i=0;i<=n;i++)
       edge[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v,x;
        cin>>u>>v>>x;
        edge[u].push_back(node{v,x});
       edge[v].push_back(node{u,x});
    }
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    dfs1(1,0);
    dfs2(1,0);
    ST(n);
    for(int i=0;i<m;i++){
        int ans=0;
        int q;
        cin>>q;
        int k=0;
        for(int j=1;k+j<=n;j++){
            while(k+j<=n&&RMQ(j,k+j)<=q){
                ans=max(ans,k+1);
                k++;
            }

        }
        cout<<ans<<endl;
    }
  }
}
