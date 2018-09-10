/*TLE*/
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
const int maxn=2e5+100;
const ll mod=998244353;
typedef pair<ll,int> P;
vector<ll>v;
set<P>bit[maxn];
set<P>::iterator it;
int N;
ll res;
struct node{
   ll l,r;
   int id;
   int s;
}a[maxn];
int getid(ll x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+2;
}
int lowbit(int x){
return x&(-x);
}
void del(int x,P e)
{
   if(x<0) return;
   while(x<=N){
    if(bit[x].count(e))
           bit[x].erase(e);
    x+=lowbit(x);
   }
}
ll sum(int x,ll d,int c){
  ll ret=0;
  while(x>0){

      //cout<<"!"<<x<<" "<<bit[x].size()<<endl;
      for(it=bit[x].begin();it!=bit[x].end();)
      {
        
         P e=(*it);
     
        // cout<<e.first<<" "<<e.second<<endl;
          if(e.first>=d)
            {
                ret++;a[e.second].s=c;res=res*(e.second)%mod;
                
                 bit[x].erase(it);
                  del(x,e);
                // it++;
            }
        else it++;
        //else bit[x].erase(it);
        //if(it==bit[x].end()) break;
      }
  
    x-=lowbit(x);
  }
return ret;
}

void add(int x,P d){
    if(x<0) return;
   while(x<=N){
    bit[x].insert(d);
    x+=lowbit(x);
   }
}
void init(){
 for(int i=0;i<=N;i++)
   {
       bit[i].clear();
   
   }
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;int cas=0;
   scanf("%d",&t);
   while(t--)
   {
       int n,m;
       scanf("%d%d",&n,&m);
       v.clear();
       for(int i=1;i<=n;i++)
       {
           scanf("%lld%lld",&a[i].l,&a[i].r),v.push_back(a[i].l);
           a[i].id=i;
           a[i].s=0;
       }
       sort(v.begin(),v.end());
       v.erase(unique(v.begin(),v.end()),v.end());
       N=v.size()+2;
       //cout<<N<<endl;
       init();
       for(int i=1;i<=n;i++)
       {
           add(getid(a[i].l),make_pair(a[i].r,a[i].id));
       }
      // for(int i=1;i<=N;i++)
      //   sort(bit[i].rbegin(),bit[i].rend());
       ll ans=0;
       res=0;
        printf("Case #%d:\n",++cas);
       for(int i=1;i<=m;i++)
       {
           ll q;
           scanf("%lld",&q);
           q^=res;
           int x=getid(q);
           res=1;
           if(x==N) 
             ans=sum(x,q,i);
           else if(v[x-2]==q)
              ans=sum(x,q,i);
            else
              ans=sum(x-1,q,i);
           //  cout<<"*"<<x<<" "<<q<<endl;
          printf("%lld\n",ans);
         if(ans==0) res=0;
       }
      
       for(int i=1;i<n;i++)
       printf("%d ",a[i].s);
       printf("%d\n",a[n].s);
   }
 return 0;
  }
