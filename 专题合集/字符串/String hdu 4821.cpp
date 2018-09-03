/*
https://www.cnblogs.com/Norlan/p/4886383.html
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int seed=31;
const int maxn=1e5+10;
ull h[maxn];
ull base[maxn];
map<ull,int>mp;
void init(){
    base[0]=1;
  for(int i=1;i<maxn;i++)
    base[i]=base[i-1]*seed;

}
ull str_hash(int l,int r){

  return h[r]-h[l-1]*base[r-l+1];
}

int main(){
   int m,l;
   init();
   while(cin>>m>>l){
        string s;
         cin>>s;
         int ans=0;
         int len=s.size();
         h[0]=0;
     for(int i=0;i<len;i++){
           h[i+1]=h[i]*seed+s[i]-'a'+1;
     }
    for(int j=1;j<=l&&j+m*l<=len;j++){
        mp.clear();
     for(int i=j;i<=len&&i<m*l+j;i+=l){

        ull t=str_hash(i,i+l-1);
        mp[t]++;
     }
     if(mp.size()==m) ans++;
     for(int i=m*l+j;i+l-1<=len;i+=l){
        ull x=str_hash(i,i+l-1);
        mp[x]++;
        ull y=str_hash(i-m*l,i-m*l+l-1);
        mp[y]--;
        if(mp[y]==0) mp.erase(y);
        if(mp.size()==m) ans++;
     }
       //   cout<<mp.size()<<endl;
   }
    printf("%d\n",ans);
   }}


