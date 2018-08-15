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
ll x;int y;
bool operator<(const node &b)const{

return x<b.x;
}

};
const int maxn=1e5+100;
ll h[maxn],a[maxn];
priority_queue<node>q1;
map<int,int>mp;
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(scanf("%d%d",&n,&m)==2){
     for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
        //cin>>a[i];
        for(int i=1;i<n;i++)
            h[i]=abs(a[i]-a[i+1]);
     for(int i=0;i<m;i++){
       mp.clear();
       while(!q1.empty())
          q1.pop();
        int l,r;
        scanf("%d%d",&l,&r);
        //cin>>l>>r;

        for(int j=l;j<r;j++)
            q1.push(node{h[j],j});
        mp[l-1]=1;mp[r]=1;
        ll ans=0;
        map<int,int>::iterator p1,p2;
        while(!q1.empty()){
            node t=q1.top();
            q1.pop();
           // cout<<t.x<<" "<<t.y<<endl;
             p1=mp.lower_bound(t.y);
             p2=p1;p2--;
             ans+=(ll)(t.y-p2->first)*(p1->first-t.y)*t.x;
            // cout<<p1->first<<" "<<p2->first<<endl;
            // cout<<ans<<endl;
             mp[t.y]=1;
        }
        printf("%lld\n",ans);
          //cout<<ans<<endl;


     }


   }


}
