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
const int maxn=1e5+100;
vector<int>edge[maxn];
int de[maxn];
int cnt[maxn];
int main(){
  int n;
  while(cin>>n){
        for(int i=0;i<=n;i++)
        edge[i].clear();
  memset(de,0,sizeof(de));
  memset(cnt,0,sizeof(cnt));
    for(int i=1;i<n;i++)
    {

      int u,v;
      cin>>u>>v;
      edge[u].push_back(v);
      edge[v].push_back(u);
      de[u]++;
      de[v]++;
    }
    if(n%2) cout<<-1<<endl;
    else if(n==2) cout<<0<<endl;
    else{
        /*int ans=n/2;
        for(int i=1;i<=n;i++){
            if(de[i]==1){
                cnt[edge[i][0]]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]>1){
              ans-=cnt[i]/2;
            }
        }
        cout<<ans-1<<endl;*/
        queue<int>que;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(de[i]==1){
                que.push(i);
            }
        }
        while(!que.empty()){
            int e=que.front();
            que.pop();
            int flag=0;
            for(int i=0;i<edge[e].size();i++){
                int t=edge[e][i];
                if(de[t]==2){
                    flag=1;
                    de[i]=0;
                    de[t]=0;
                    ans++;
                    for(int j=0;j<edge[t].size();j++){
                        int x=edge[t][j];
                        if(de[x]){de[x]--;break;}
                    }
                    //que.pop();
                    break;
                }
                else if(de[t]==1){
                    de[i]=0;
                    de[t]=0;
                    ans++;
                    flag=1;
                    break;
                }
            }
            if(!flag) que.push(e);
        }
        cout<<ans<<endl;
    }
  }
return 0;

}
