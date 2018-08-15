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
const int maxn=1e5+100;
int flag;
struct node{
    int x,y;
    bool operator <(const node &b)const
    {
        if(flag&&y==b.y) return x>b.x; 
        if(y==b.y) return x<b.x;
        return y<b.y;
    } 
    bool operator ==(const node &b)const
    {
        if(y==b.y&&x==b.x) return 1;
        return 0; 
    } 
}a[maxn];
bool cmp(node &x,node &y){

  if(x.x==y.x) return x.y<y.y;
  if(flag) return x.x>y.x;
  return x.x<y.x;
}
vector<node>v;
int getid(node &x){
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int x[maxn];
int b[maxn];
int Search(int num,int low,int high) {
  int mid;
  while(low<=high)  {
    mid=(low+high)/2;
	if(num>=b[mid])  low=mid+1;
	else   high=mid-1;
	}
	 return low;
	 }
int DP(int n) {
    int i,len,pos;
    b[1]=x[1];
    len=1;
    for(i=2;i<=n;i++) {
        if(x[i]>=b[len])
		 {
        len=len+1; b[len]=x[i];  }
        else
        { pos=Search(x[i],1,len);
        b[pos]=x[i];
			   }}
    return len; }


int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       int sx,sy,tx,ty;
       cin>>sx>>sy>>tx>>ty;
       if(ty<sy){
           swap(sx,tx);
           swap(sy,ty);
       }
       flag=0;
       if(sx>tx) flag=1;
       v.clear();
       int c=0;
       for(int i=1;i<=n;i++)
       {
           int x,y;
          cin>>x>>y;
          if(x<min(sx,tx)||x>max(sx,tx)||y<sy||y>ty)
           continue;
           a[++c].x=x;a[c].y=y;
           v.push_back(a[c]);
   
       }
       sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
       sort(a+1,a+c+1,cmp);
     
      /* int k=0;
       int flag=0;
       if(sx>tx) flag=1;*/
       
       for(int i=1;i<=c;i++)
       {
            x[i]=getid(a[i]);
       
       }
      
       cout<<DP(c)<<endl;
   }


  }

