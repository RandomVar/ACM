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
int a[10];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin>>a[0])
  {
      map<int,int>cnt;
      for(int i=1;i<6;i++)
      cin>>a[i],cnt[a[i]]++;
   cnt[a[0]]++;
   map<int,int>::iterator it;
   int f1=0,f2=0;
   for(it=cnt.begin();it!=cnt.end();it++)
   {
       if(it->second==4) f1++;
       if(it->second==2) f2++;
   }
   if(f1&&f2) cout<<"Elephant"<<endl;
   else if(f1) cout<<"Bear"<<endl;
   else cout<<"Hernia"<<endl;
      
  }


  }

