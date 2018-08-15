#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[15],b[15],c[15],d[15],id[15],vis[15];
int dfs(int x){
  int cnt=0;
  vis[x]=1;
  cnt++;
  if(!vis[id[x]]) cnt+=dfs(id[x]);
return cnt;
}

int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      for(int i=0;i<n;i++)
        cin>>a[i];
      for(int i=0;i<n;i++)
        cin>>b[i];
      for(int i=0;i<n;i++)
        id[i]=i;
      int ans=INF;
      do{
        int cnt=0;
        memset(vis,0,sizeof(vis));
          for(int i=0;i<n;i++){
             if(!vis[i]) cnt+=dfs(i)-1;
          }
          for(int i=0;i<n;i++){
                int tm=id[i];
          int x=a[i],y=b[tm];
              if(x<y) swap(x,y);
              if(x==y) continue;

                if(x%2==1) {x--;cnt++;}
                while(x/2>=y){
                    x/=2;cnt++;
                    if(x%2&&x!=y) {x--;cnt++;}
                }
                cnt+=x-y;
          }
             ans=min(ans,cnt);
      }while(next_permutation(id,id+n));
      cout<<ans<<endl;
   }
return 0;
}
