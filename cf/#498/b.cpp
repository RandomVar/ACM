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
   int v;int id;
   bool operator<(const node &b)const {
      //if(v==b.v) return id<b.id;
       return v>b.v;
   }
}a[2100];
bool cmp(node &x,node &y)
{
    return x.id<y.id;
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;int k;
   while(cin>>n>>k)
   {
       for(int i=1;i<=n;i++){
        cin>>a[i].v;a[i].id=i;
       }
       sort(a+1,a+1+n);
       sort(a+1,a+1+k,cmp);
       int sum=0;
       for(int i=1;i<=k;i++)
       {
           sum+=a[i].v;

       }
       cout<<sum<<endl;
       int pre=0;
       for(int i=1;i<k;i++)
       {
           cout<<a[i].id-pre<<" ";
           pre=a[i].id;
       }
       cout<<n-pre<<endl;
      // cout<<endl;
   }


 return 0;
  }

