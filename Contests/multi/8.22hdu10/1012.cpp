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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n,m,k,w;
       scanf("%d%d%d%d",&n,&m,&k,&w);
       for(int i=1;i<=m;i++)
       {
           scanf("%d%d%d%d",&a[i].s,&a[i].t,&a[i].w,&a[i].op);
           val[a[i].s]++;
           val[a[i].t+1]--;
       }
       sort(a+1,a+1+m);
       int k=1;
       vector<int>vec;
       for(int i=1;i<=m;i++)
       {
           while(!vec.size())
           {
               if(a[vec[0]].t<=a[i].s)
                 vec.pop_front();
           }
            
             for(int f=0;f<i;f++)
             {
                 if(a[i].op==0)
                 {
                    dp[a[i].t][j+1][f]=max(dp[a[i].t][j+1][f],dp[pre][j][f-1]+a[i].w);
                    dp[a[i].t][j+1][f]=max(dp[a[i].t][j+1][f],dp[pre][j][f]+a[i].w-w);
                 }
                else
                {    
                    dp[a[i].t][j+1][f]=max(dp[a[i].t][j+1][f],dp[pre][j][f]+a[i].w);
                    dp[a[i].t][j+1][f]=max(dp[a[i].t][j+1][f],dp[pre][j][f-1]+a[i].w-w);
                }
             }
        }
            vec.push(i);
          }
       /*
       for(int i=1;i<=m;i++)
       {
           for(int j=s[i].s;j<=s[i].t;j++)
           {
               for
           }
       }*/
      /* for(int i=0;i<=n;i++)
       { 
          while(k<=m&&i==a[k].t)
          {
              if(a[k].op==0)
              {
                 if(dp[j].ans>dp[i].ans) dp[pre][j][f]+a[i].w;
              
              }
              else dp[i][j][f+1]=max(dp[i][j][f+1],dp[i][j][f]+a[i].w);
             k++;
          }
          dp[i][j][f]=max(dp[i][j][f],dp[i-1][j][f]);
          if(val[i]<=k-1) pre=i;  
       }*/
   }
 return 0;
  }

