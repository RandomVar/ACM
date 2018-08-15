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
int x,y;
bool operator<(const node &b)const{

return x<b.x;
}

};
const int maxn=1e5+100;
int h[maxn],a[maxn];
ll cnt1[maxn],cnt2[maxn];
int n;
void luangao(){
     priority_queue<node>q1;
    map<int,int>mp;
    for(int j=1;j<n;j++)
        q1.push(node{h[j],j});
     mp[0]=1;mp[n]=1;
    map<int,int>::iterator p1,p2;
        while(!q1.empty()){
            node t=q1.top();
            q1.pop();
           // cout<<t.x<<" "<<t.y<<endl;
             p1=mp.lower_bound(t.y);
             p2=p1;p2--;
             cnt1[t.y]=t.y-p2->first;
             cnt2[t.y]=p1->first-t.y;
             mp[t.y]=1;
        }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(cin>>n>>m){
     for(int i=1;i<=n;i++)
        cin>>a[i];
        for(int i=1;i<n;i++)
            h[i]=abs(a[i]-a[i+1]);
    luangao();
     for(int i=0;i<m;i++){

        int l,r;
        cin>>l>>r;
        ll ans=0;
     for(int j=l;j<r;j++)
       {
            ans+=min(cnt1[j],(ll)(j-l+1))*min(cnt2[j],(ll)r-j)*h[j];

       }
          cout<<ans<<endl;


     }


   }


}
