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
const double eps=1e-8;
const int maxn=500;
int sgn(double x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
struct node{
  double x,y;
}a[maxn],c[maxn];
double dissq(node x,node y)
{
 return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
vector<int>edge[maxn];
int used[maxn];//标记这条边有没有用过
int match[maxn];//标记右侧的点是否被匹配，以及匹配的是左侧哪个点
int nl;int nr;
bool find(int x){
  for(int i=0;i<edge[x].size();i++){
      int t=edge[x][i];
    if(!used[t]){
        used[t]=1;
        if(match[t]==0||find(match[t])){
            match[t]=x;
            return true;
        }
    }
  }
  return false;
}
int hungarian()
{
    int ans = 0;
    memset(match,0,sizeof(match));
    for (int i=1;i<=nl;i++) {
       memset(used,0,sizeof(used));
       if(find(i)) ans++;
    }
    return ans;
}

int check(double mid,int n)
{
    for(int i=0;i<=nl;i++)
      edge[i].clear();
       for(int i=1;i<=nl;i++)
      for(int j=1;j<=nr;j++)
      {
          if(sgn(dissq(a[i],c[j])-mid)<0) edge[i].pb(j);
      }
      int ans=nl+nr-hungarian();
   return ans>=n;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n>>nl>>nr)
  {
      for(int i=1;i<=nl;i++)
      {
          cin>>a[i].x>>a[i].y;
      }
      for(int i=1;i<=nr;i++)
        cin>>c[i].x>>c[i].y;
      double l=0;double r=1000000.0;
      while(sgn(r-l)>=0)
      {
          double mid=(l+r)/2;
         if(check(mid,n))
            l=mid+eps;
        else 
          r=mid-eps;
      }

      printf("%.8f\n",l);
     // cout<<l<<endl;
  }


  }

