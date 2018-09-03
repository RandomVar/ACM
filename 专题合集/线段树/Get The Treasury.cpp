/*https://blog.csdn.net/u013611908/article/details/44351043*/
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
const int maxn=2010;
struct seg{
  int x1,x2,y1,y2,z1,z2;
}s[maxn];
struct node{
    int x1,x2;int y;int s;
    bool operator<(const node &b)const{
        return y<b.y;
    }
};
vector<int>v1;
vector<int>v3;
vector<node>vec;
int col[maxn<<2];
int sum[maxn<<2][4];
int getidz(int x)
{
    return lower_bound(v3.begin(),v3.end(),x)-v3.begin();
}
int getidx(int x)
{
    return lower_bound(v1.begin(),v1.end(),x)-v1.begin()+1;
}

void pushup(int rt,int l,int r)
{
 if(col[rt]==1)
 {
     sum[rt][3]=sum[rt*2][2]+sum[rt*2+1][2]+sum[rt*2][3]+sum[rt*2+1][3];
     sum[rt][2]=sum[rt*2][1]+sum[rt*2+1][1];
     sum[rt][1]=v1[r]-v1[l-1]-sum[rt][3]-sum[rt][2];
     return;
 }
 if(col[rt]==2)
 {
      sum[rt][3]=sum[rt*2][1]+sum[rt*2+1][1]+sum[rt*2][2]+sum[rt*2+1][2]+sum[rt*2][3]+sum[rt*2+1][3];
      sum[rt][2]=v1[r]-v1[l-1]-sum[rt][3];
      sum[rt][1]=0;
      return;
  }
  if(col[rt]==3)
  {
      sum[rt][3]=v1[r]-v1[l-1];
      sum[rt][2]=sum[rt][1]=0;
     return;
  }
  if(col[rt]==0)
  {
      sum[rt][3]=sum[rt*2+1][3]+sum[rt*2][3];
      sum[rt][2]=sum[rt*2+1][2]+sum[rt*2][2];
      sum[rt][1]=sum[rt*2+1][1]+sum[rt*2][1];
      return;
  }
}

void update(int l,int r,int L,int R,int c,int rt){
    if(l>=L&&r<=R)
    {
        col[rt]+=c;
      //  cout<<col[rt]<<" "<<c<<endl;
        pushup(rt,l,r);
        return;
    }
    int mid=(l+r)/2;
    if(mid>=L) update(l,mid,L,R,c,rt*2);
    if(mid<R) update(mid+1,r,L,R,c,rt*2+1);
    pushup(rt,l,r);
}

int main(){
 
   int  t;int cas=0;
   scanf("%d",&t);
   while(t--)
   {
       int n;
       scanf("%d",&n);
       v1.clear();v3.clear();
       for(int i=1;i<=n;i++)
       {
           scanf("%d%d%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].z1,&s[i].x2,&s[i].y2,&s[i].z2);
           
           v1.pb(s[i].x1);v1.pb(s[i].x2);
         
           v3.pb(s[i].z1);v3.pb(s[i].z2);
       }
       sort(v1.begin(),v1.end()),v1.erase(unique(v1.begin(),v1.end()),v1.end());
       int m=v1.size();
       sort(v3.begin(),v3.end()),v3.erase(unique(v3.begin(),v3.end()),v3.end());
       ll ans=0;
       for(int i=0;i<v3.size()-1;i++)
       {
           mem(col,0);
           mem(sum,0);
           vec.clear();
           for(int j=1;j<=n;j++)
           {
               if(s[j].z1<=v3[i]&&s[j].z2>=v3[i+1])
                 {
                 vec.push_back(node{s[j].x1,s[j].x2,s[j].y1,1});
                 vec.push_back(node{s[j].x1,s[j].x2,s[j].y2,-1});
                 }    
           } 
           sort(vec.begin(),vec.end());//acrodding to y
           ll area=0;
           //cout<<vec.size()<<endl;
           for(int j=0;j<vec.size()-1;j++)
           {
               node e=vec[j];
              // cout<<e.x1<<" "<<e.x2<<" "<<e.y<<" "<<e.s<<endl;
              //if(e.x2>e.x1)
                update(1,m,getidx(e.x1),getidx(e.x2)-1,e.s,1); 
              area+=(ll)sum[1][3]*1LL*(vec[j+1].y-e.y);
           //  cout<<sum[1][3]<<" "<<area<<endl;
           }

          // cout<<endl;
          ans+=area*1LL*(v3[i+1]-v3[i]);
          //cout<<ans<<endl;
       }
      printf("Case %d: %lld\n",++cas,ans);
       }


 return 0;
  }

