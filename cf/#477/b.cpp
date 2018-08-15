#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int c[100010];
bool cmp(int a,int b){
return a>b;
}
int main(){
  int n,a,b;
  while(cin>>n>>a>>b)
  {
      ll sum=0;
      for(int i=0;i<n;i++)
      {
          cin>>c[i];
          sum+=c[i];
      }
      sort(c+1,c+n,cmp);
      int cnt=0;
      for(int i=1;i<n;i++){
         if((c[0]*a*1.0)/sum<b)
           {sum-=c[i];cnt++;}
           else break;
       }
      cout<<cnt<<endl;
}}
