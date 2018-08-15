#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=2*1e5+100;
struct node{
    int s,t;
    bool operator<(const node  &b)const{
    if(t==b.t) return s<b.s;
    return t<b.t;
    }
}a[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].t;
    }
    sort(a+1,a+1+n);
    int pre=a[1].t;
      int cnt=1;
    for(int i=2;i<=n;i++){
       if(a[i].s>pre){
        cnt++;pre=a[i].t;
       }
    }
 cout<<cnt<<endl;}
return 0;}
