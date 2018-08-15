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
const int maxn=400;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int eps = 1e-8;
const int PI = acos(-1.0);
int sgn(int x) {/*判断x的正负性*/
    if(fabs(x) < eps) return 0;
    if(x < 0)return -1;
    else return 1;
     }
struct Point {
    int x,y;
    Point(){};
    Point(int _x,int _y){x=_x;y=_y;}
    Point operator- (const Point &b){
     return Point(x-b.x,y-b.y);
    }

    int operator^ (const Point &b){
    return x*b.y-y*b.x;
    }
    int operator*(const Point &b){
    return x*b.x+y*b.y;
    }
    };
    int dissq(Point a,Point b){
return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
Point lis[maxn];
int st[maxn],top;
bool cmp(Point a,Point b){
    int flag=sgn((a-lis[0])^(b-lis[0]));
 if(flag>0) return 1;
 if(flag==0&&sgn(dissq(a,lis[0])-dissq(b,lis[0]))<=0) return 1;
 return 0;
}

void graham(int n){
  Point p0;
  p0=lis[0];int k=0;
  for(int i=1;i<n;i++){
    if((p0.y>lis[i].y)||(p0.y==lis[i].y&&p0.x>lis[i].x)){
        p0=lis[i];
        k=i;
    }
  }
  lis[k]=lis[0];
  lis[0]=p0;
  sort(lis+1,lis+n,cmp);
  if(n==1){
    st[0]=0;
    top=1;
    return;
  }
  if(n==2){
    st[0]=0;
    st[1]=1;
    top=2;
    return;
  }
  st[0]=0;
  st[1]=1;
  top=2;
  for(int i=2;i<n;i++){
   while(top>1&&sgn((lis[st[top-1]]-lis[st[top-2]])^(lis[i]-lis[st[top-2]]))<=0)
        top--;
    st[top++]=i;


  }

}

int dp[maxn][maxn];
int cost[maxn][maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,p;
  while(cin>>n>>p){
    for(int i=0;i<n;i++)
        cin>>lis[i].x>>lis[i].y;
   graham(n);
   if(top<n)
    cout<<"I can't cut."<<endl;
   else{
        mem(dp,0x3f);
       mem(cost,0);
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
               cost[i][j]=(abs(lis[st[i]].x+lis[st[j]].x)*abs(lis[st[i]].y+lis[st[j]].y))%p;
         cost[i][i]=0;cost[i][(i+1)%n]=0;
         dp[i][i]=0;dp[i][(i+1)%n]=0;
       }

    for(int j=2;j<n;j++)
       for(int i=0;i+j<n;i++){
           for(int k=i+1;k<i+j;k++)
                  dp[i][(j+i)]=min(dp[i][(j+i)],dp[i][k]+dp[k][(i+j)]+cost[i][k]+cost[k][(i+j)]);
      }
     cout<<dp[0][n-1]<<endl;
   }

  }


}
