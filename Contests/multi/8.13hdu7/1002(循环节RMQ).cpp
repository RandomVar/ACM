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
int lef[maxn][3][30],righ[maxn][3][30];
int l[3],r[3];
int ans[3];
int daan[3];
int flag;
void ST(int n) {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            for(int k=0;k<3;k++)
            {
               lef[i][k][j] = min(lef[i][k][j - 1], lef[i + (1 << (j - 1))][k][j - 1]);
               righ[i][k][j] = max(righ[i][k][j - 1], righ[i + (1 << (j - 1))][k][j - 1]);
            }
        }
    }
}

int RMQ(int s, int t,int w) {
    int k = 0;
    while ((1 << (k + 1)) <= t - s + 1) k++;
   for(int j=0;j<3;j++)
   {
       l[j]=min(l[j],min(lef[s][j][k],lef[t - (1 << k) + 1][j][k])-w);
       r[j]=max(r[j],max(righ[s][j][k],righ[t - (1 << k) + 1][j][k])-w);
    //   cout<<j<<" "<<l[j]<<" "<<r[j]<<endl;
   }
   return 1;
}

void solve(int n)
{
     for(int i=1;i<=n;i++)//len
       {
           for(int k=0;k<3;k++)
           {
               r[k]=0;l[k]=i+1;
           }
           for(int j=1;j<=n/i;j++)//kuai
           {
              // cout<<i<<" "<<i*(j-1)+1<<" "<<i*j<<endl;
               RMQ(i*(j-1)+1,i*j,i*(j-1));
           }
          if(i*(n/i)<n) RMQ(i*(n/i)+1,n,i*(n/i));
            //  cout<<i<<" "<<l[0]<<" "<<r[0]<<" "<<l[1]<<" "<<r[1]<<" "<<l[2]<<" "<<r[2]<<endl;
        
                if(r[0]<l[1]&&r[1]<l[2]&&r[0]<l[2])
                   {
                       flag=1;
                       //cout<<i<<" "<<l[0]<<" "<<r[0]<<" "<<l[1]<<" "<<r[1]<<" "<<l[2]<<" "<<r[2]<<endl;
                       ans[0]=r[0];
                       ans[1]=max(r[1]-r[0],0);
                       ans[2]=i-ans[0]-ans[1];
                       if(ans[0]<daan[0])
                       {
                         for(int k=0;k<3;k++)
                          daan[k]=ans[k];
                       }
                       else if(ans[0]==daan[0])
                       {
                           if(ans[1]<daan[1])
                           {
                               for(int k=0;k<3;k++)
                                daan[k]=ans[k];
                           }
                           else if(ans[1]==daan[1])
                           {
                               if(ans[2]<daan[2])
                               {
                                     daan[2]=ans[2];
                               }
                           }
                       }
                       
                   }
                 }
      
}
void init()
{
    for(int i=0;i<maxn;i++)
    {
        for(int k=0;k<3;k++)
        {
        lef[i][k][0]=maxn;
        righ[i][k][0]=0;
        }
    }
    for(int k=0;k<3;k++)
      daan[k]=maxn;
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int m;
       scanf("%d",&m);
       int n=0;
       init();
       flag=0;
       for(int i=0;i<m;i++)
       {
           int x;char s[2];
           scanf("%d%s",&x,s);
           lef[x][s[0]-'A'][0]=righ[x][s[0]-'A'][0]=x;
           n=max(n,x);
       }
       ST(n);
       solve(n);
       if(flag)
       {
           printf("%d %d %d\n",daan[0],daan[1],daan[2]);
       }
       else printf("No\n");
   }
 return 0;
  }
