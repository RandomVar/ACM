#include<bits/stdc++.h>
using namespace std;
struct node{
  int x,y;
};
set<int>st[6][6];
queue<node>que;
char s[6][6];
int flag[6];

void check(int u,int v){
  for(int j=0;j<4;j++)
     if(s[u][j]!='*') st[u][v].insert(s[u][j]-'0');
  for(int i=0;i<4;i++)
     if(s[i][v]!='*') st[u][v].insert(s[i][v]-'0');
  for(int i=u/2*2;i<=u/2*2+1;i++)
    for(int j=v/2*2;j<=v/2*2+1;j++)
       if(s[i][j]!='*')  st[u][v].insert(s[i][j]-'0');
}

void update(int u,int v){

     for(int j=0;j<4;j++)
       if(s[u][j]=='*') {
            st[u][j].insert(s[u][v]-'0');
            if(st[u][j].size()==3) que.push(node{u,j});
            }

  for(int i=0;i<4;i++)
     if(s[i][v]=='*') {
            st[i][v].insert(s[u][v]-'0');
            if(st[i][v].size()==3) que.push(node{i,v});
            }

  for(int i=u/2*2;i<=u/2*2+1;i++)
    for(int j=v/2*2;j<=v/2*2+1;j++)
       if(s[i][j]=='*') {
            st[i][j].insert(s[u][v]-'0');
            if(st[i][j].size()==3) que.push(node{i,j});
            }

}

void init(){
 while(!que.empty())
    que.pop();
 for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
     st[i][j].clear();

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;int cas=0;
  while(t--){
    init();
     for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
           cin>>s[i][j];
     for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
          char x=s[i][j];
          if(x=='*') {
            check(i,j);
       }}}

      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
      {
          if(s[i][j]=='*'&&st[i][j].size()==3)
          que.push(node{i,j});
      }

       while(!que.empty()){
              node e=que.front();
              que.pop();
              int i=e.x;int j=e.y;
              set<int>::iterator it;
             memset(flag,0,sizeof(flag));
             for(it=st[i][j].begin();it!=st[i][j].end();it++)
                flag[*it]=1;
             for(int k=1;k<=4;k++)
               if(!flag[k]) {s[i][j]=char('0'+k); break;}
            update(i,j);

          }

          cout<<"Case #"<<++cas<<":"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<s[i][j];
        cout<<endl;
    }

  }
return 0;
}
