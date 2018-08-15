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
const int maxn=10010;
char s[maxn];
int a[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,d;
  while(scanf("%d%d",&n,&d)==2)
  {
      scanf("%s",s);
      int k=0;
      int cnt=0;
      int x;
      for(x=0;x<n;x++)
        if(s[x]=='1') cnt++;
        else break;
      int tou=cnt;
      cnt=0;
      for(int i=x;i<n;i++)
        {
           if(s[i]=='1') cnt++;
           else if(cnt) 
             a[k++]=cnt,cnt=0;
        }
        int wei=0;
      //  cout<<a[k-1]<<endl;
     //  cout<<s[n-1]<<endl;
       if(s[n-1]=='1')
       {
        a[k++]=cnt;
        wei=a[k-1];
       // cout<<wei<<endl;
        k--;
       }
      
      sort(a,a+k);
      int ans=0;
      if(d==0)
      {
          ans=tou;
      }
      else if(d%2==0)
      {
          d/=2;
          int ans1=max(tou,wei);
          for(int i=k-1;i>k-1-d&&i>=0;i--)
          {
            ans1+=a[i];
          }
          int ans2=tou+wei;
          for(int i=k-1;i>k-1-d+1&&i>=0;i--)
           ans2+=a[i];
           ans=max(ans1,ans2);
      }                             
      else{
           int ans1=tou+wei;
           d=d/2;
           for(int i=k-1;i>k-1-d&&i>=0;i--)
           {
               ans1+=a[i];
           }
           int ans2=0;
           for(int i=k-1;i>k-1-d-1&&i>=0;i--)
           {
               ans2+=a[i];
           }
           ans=max(ans1,ans2);
        }

     printf("%d\n",ans);
  }
 return 0;
  }
