#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e4+100;
int tree[maxn<<2];
int dp[maxn][1<<4];
int a[5][maxn];
int pos[maxn][5][2];
void pushup(int rt){
  tree[rt]=max(tree[rt*2],tree[rt*2+1]);
}

void build(int l,int r,int rt){
  if(l==r) {
      tree[rt]=0;
      return;
      }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}

int query(int l,int r,int L,int R,int rt){
 if(l>=L&&r<=R) 
       return tree[rt];
 int ans=0;
 int mid=(l+r)/2;
 if(L<=mid){
    ans=max(ans,query(l,mid,L,R,rt*2));
 }
 if(R>mid){
    ans=max(ans,query(mid+1,r,L,R,rt*2+1));
 }
 return ans;
}

void update(int l,int r,int index,int val,int rt){
  if(l==r) {
    tree[rt]=max(tree[rt],val);
    return;
  }
  int mid=(l+r)/2;
  if(index<=mid)
    update(l,mid,index,val,rt*2);

  else update(mid+1,r,index,val,rt*2+1);
  pushup(rt);
}
void init()
{
    mem(pos,0);

}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
        init();
        for(int i=0;i<4;i++)
        {
            for(int j=1;j<=n;j++)
             {
              cin>>a[i][j];
             if(pos[a[i][j]][i][0]==0) pos[a[i][j]][i][0]=j;
             ele pos[a[i][j]][i][1]=j;
             }
        }
        build(1,n,1);
         for(int i=1;i<=n;i++)
         {
             int left=n+1;int right=-1;
             for(int x=0;x<(1<<4);x++)
             {
                 int flag=1;
                 for(int j=0;j<4;j++)
                 {
                    if(pos[i][j][x&(1<<j)]==0) {flag=0;break;}
                     left=min(left,pos[i][j][x&(1<<j)]);
                     right=max(right,pos[i][j][x&(1<<j)]);
                 }
                 if(flag==0) continue;
                 int pre=query(1,n,1,left-1,1);//<=left-1
                 dp[i][x]=max(dp[i][x],pre+1);
             }
             int ans=0;
             for(int x=0;x<(1<<4);x++)
             {
                 ans=max(ans,dp[i][x]);
             }
              update(1,n,right,ans,1);
         }
         printf("%d\n",query(1,n,1,n,1));
    }
 return 0;
  }
