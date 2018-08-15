#include<bits/stdc++.h>
using namespace std;
void dfs1(){
 int tot=1;
  que.push(1);
  st[1]=1;
  int cnt=1;
  while(!que.empty()){
     int t=que.front();
     edge[t].pb(++tot);
     st[tot]=st[t]+1;
     if(st[tot])

  }


}
int main(){
   int n;
   while(cin>>n){
     if(n<=5)
     { cout<<-1<<endl;
       dfs2();
       continue;
     }
     else{
        dfs1();
        dfs2();

     }

   }


}
