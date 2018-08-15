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
int vec[maxn];
int id[maxn];
int cnt[maxn];
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  string s;
  while(cin>>s)
  {
      int len=s.size();
      int k=0;
      mem(cnt,0);
      mem(id,0);
      mem(vec,0);
      for(int i=0;i<len;i++)
      {
          if(s[i]=='1') cnt[1]++;
          if(s[i]=='2') {k++;id[k]=i;} 
          if(s[i]=='0') vec[k]++;
      }
      for(int j=1;j<=vec[0];j++)
       cout<<0;
       for(int j=1;j<=cnt[1];j++)
       cout<<1;
      for(int i=1;i<=k;i++)
      {
          cout<<2;
          for(int j=1;j<=vec[i];j++)
            cout<<0;
      }
      cout<<endl;
  }


  }

