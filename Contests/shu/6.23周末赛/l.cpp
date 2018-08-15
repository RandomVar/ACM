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
const int maxn=1e6+100;
int n;
int p[maxn];
void init(){
  for(int i=1;i<=n;i++)
    p[i]=i;/*根节点初始化为自己*/
}
int find(int x){
 return x==p[x]?x:find(p[x]);
}
void unin(int x,int y){
  x=find(x);y=find(y);
  if(x!=y) {
     if(x>y) p[x]=y;
     else p[y]=x;
  }
}
vector<int>vec[maxn];
vector<int>in[maxn];
int a[maxn];
int c[maxn];
int h[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int m;
  while(cin>>n>>m){
        for(int i=0;i<=n;i++)
        {vec[i].clear();in[i].clear();}
     init();
      for(int i=1;i<=n;i++)
        cin>>a[i];
      for(int i=1;i<=m;i++){
          int x,b;
          cin>>x>>b;
          unin(x,b);
      }
      int k=0;
      for(int i=1;i<=n;i++){
            int x=find(i);
            if(x==i) h[x]=++k;
            vec[h[x]].pb(a[i]);
            in[h[x]].pb(i);
      }
      for(int i=1;i<=k;i++){

            sort(vec[i].begin(),vec[i].end());
            sort(in[i].begin(),in[i].end());
            int len=vec[i].size()-1;

            for(int j=0;j<=len;j++){
                c[in[i][j]]=vec[i][len-j];

            }
      }

       for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
       cout<<endl;

}
}
