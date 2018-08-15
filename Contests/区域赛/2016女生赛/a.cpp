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
struct node{
  string s;int num;
  bool operator<(const node &b)const{
  return num>b.num;
  }
}p[20];
int main(){
  int t;
  cin>>t;
  while(t--){
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
        cin>>p[i].s>>p[i].num;
     }
     sort(p,p+n);
     for(int i=0;i<n-1;i++)
        cout<<p[i].s<<" ";
     cout<<p[n-1].s<<endl;
  }
}

