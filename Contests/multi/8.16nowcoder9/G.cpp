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
int solve() {
    for(int i=1;i<=k;i++)
    {
        if()
    }
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
        int k=0;
         for(int i=1;i<=n;i++)
         {
             s[++k].a[0]=a[0][i];
             for(int x=0;x<(1<<4);x++)
             {
                 int flag=1;
                 for(int j=1;j<4;j++)
                 {
                     s[k].a[j]=pos[a[0][i]][j][x&(1<<j)];
                 }
               }
          }
       
    }
    
    }