#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+100;

int vis[maxn];
queue<int>que[maxn];
void init(int n){
  for(int i=0;i<=n;i++)
     while(!que[i].empty()) que[i].pop();
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
        init(n);
        memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        que[t].push(i);
    }
    int flag=0;int num=0;
    for(int i=0;i<n;i++){
      if(!que[i].empty()&&i<=num+1){
        int t=que[i].front();
        que[i].pop();
        vis[i]=t;
        num++;
      // cout<<t<<endl;
      }
      else{
        int x=min(i,(num-1)/3*3+i%3+3);
        while(x>=0&&(que[x].empty()||x>num+1))
           x-=3;
         if(!que[x].empty()&&x<=num+1)
         {
             int t=que[x].front();
             que[x].pop();
             vis[i]=t;
             num=x;
            //   cout<<t<<endl;
         }
         else {flag=1;break;}

      }

    }

    if(flag) cout<<"Impossible"<<endl;
    else{
            cout<<"Possible"<<endl;
      for(int i=0;i<n;i++)
        cout<<vis[i]<<" ";
        cout<<endl;
    }
  }


}
