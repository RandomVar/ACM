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
struct node{
    int v;int c;
    bool operator<(const node &b)const{
        return c>b.c;
    }
}cnt[110];
int n,m;
int check(int mid)
{
    if(mid==0) return 1;
    int x=0;
    for(int i=0;i<m;i++)
    {
        int num=cnt[i].c;
        while(num>=mid)
        { 
            x++;
            num-=mid;
        }
        if(x>=n) return 1;
    }
    return 0;
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  // int n,m;
   while(cin>>n>>m)
   {
       for(int i=0;i<m;i++){
        int t;
        cin>>t;
        cnt[t].v=t;
        cnt[t].c++;
       }
       sort(cnt,cnt+100+1);
       int l=0;int r=100;
       int ans=0;
       while(l<=r)
       {
           int mid=(l+r)/2;
           //cout<<mid<<endl;
          // if(r==0&&check(mid)==0)
           //  break;
           if(check(mid))
             l=mid+1,ans=mid;
            else r=mid-1;
         //cout<<l<<" "<<r<<endl;
       }
        cout<<ans<<endl;
   }

 return 0;
  }

