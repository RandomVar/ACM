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
const int maxn=2000+100;

    int n;
    vector<int> g[maxn*2];
    bool mark[maxn*2];
    int s[maxn*2],c;
    bool dfs(int x){
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        s[c++]=x;
        for(int i=0;i<(int)g[x].size();i++)
            if(!dfs(g[x][i])) return false;
        return true;
    }
    void init(int n){

        for(int i=0;i<n*2;i++) g[i].clear();
        memset(mark,0,sizeof(mark));
    }
    void add_clause(int x,int y){//这个函数随题意变化
        g[x].push_back(y);//选了x就必须选y^1

    }
    bool solve(){
        for(int i=0;i<n*2;i+=2)
            if(!mark[i]&&!mark[i+1]){
                c=0;
                if(!dfs(i)){
                    while(c>0) mark[s[--c]]=false;
                    if(!dfs(i+1)) return false;
                }
            }
        return true;
    }


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int m;
   while(cin>>n>>m){

     init(n);
      for(int i=0;i<m;i++){
          int a,b,c,d;
          cin>>a>>b>>c>>d;
          add_clause(2*a+c,2*b+(d^1));
          add_clause(2*b+d,2*a+(c^1));
          //G[2*a+c].pb(2*b+(d^1));
          //G[2*b+d].pb(2*a+(c^1));
          //G[2*a+c].pb(2*b+(d^1));
      }
     if(solve()) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;


   }
}
