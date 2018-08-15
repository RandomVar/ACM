#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=3*1e5;
int a[maxn+10];
ll vis[maxn+10][2];
struct node{
 int num;int st;
};
int n,m;
ll bfs(int x,int zhong){
   int MAX=m*n;
   queue<node>que;
   node e;
   e.num=x;e.st=a[x];
   que.push(e);
   vis[x][a[x]]=1;
   if(x==zhong) return 1;
   while(!que.empty()){
    node t=que.front();
    que.pop();
   // cout<<t.num<<" "<<t.st<<" "<<vis[t.num][t.st]<<endl;
    int v=t.num%m;
    int u=t.num-t.num%m;
    if(t.st==1){
        ll y=vis[t.num][t.st];
        if(y%2==1){
        if(t.num+1<MAX&&v<m-1&&!vis[t.num+1][1^a[t.num+1]]){
           vis[t.num+1][1^a[t.num+1]]=y+1;
           if(t.num+1==zhong) return y+1;
           e.num=t.num+1;e.st=(1^a[t.num+1]);
           que.push(e);
        }
        if(t.num-1>=0&&v>0&&!vis[t.num-1][1^a[t.num-1]]){
           vis[t.num-1][1^a[t.num-1]]=y+1;
           if(t.num-1==zhong) return y+1;
           e.num=t.num-1;e.st=(1^a[t.num-1]);
           que.push(e);
        }
        }
        else{
           if(t.num+1<MAX&&v<m-1&&!vis[t.num+1][a[t.num+1]]){
           vis[t.num+1][a[t.num+1]]=y+1;
           if(t.num+1==zhong) return y+1;
           e.num=t.num+1;e.st=a[t.num+1];
           que.push(e);
        }
        if(t.num-1>=0&&v>0&&!vis[t.num-1][a[t.num-1]]){
            if(t.num-1==zhong) return y+1;
           vis[t.num-1][a[t.num-1]]=y+1;
           e.num=t.num-1;e.st=a[t.num-1];
           que.push(e);
        }

        }
    }
   else{

        ll y=vis[t.num][t.st];
        if(y%2==1){
          //
        if(t.num+m<MAX&&u<n-1&&!vis[t.num+m][1^a[t.num+m]]){
         //cout<<a[t.num+m]<<(a[t.num+m]^1)<<endl;
                if(t.num+m==zhong) return y+1;
           vis[t.num+m][1^a[t.num+m]]=y+1;
           e.num=t.num+m;e.st=(1^a[t.num+m]);
           que.push(e);
        }
        if(t.num-m>=0&&u>0&&!vis[t.num-m][1^a[t.num-m]]){
            if(t.num-m==zhong) return y+1;
           vis[t.num-m][1^a[t.num-m]]=y+1;
           e.num=t.num-m;e.st=(1^a[t.num-m]);
           que.push(e);
        }
        }
        else{
           if(t.num+m<MAX&&u<n-1&&!vis[t.num+m][a[t.num+m]]){
                if(t.num+m==zhong) return y+1;
           vis[t.num+m][a[t.num+m]]=y+1;
           e.num=t.num+m;e.st=a[t.num+m];
           que.push(e);
        }
        if(t.num-m>=0&&u>0&&!vis[t.num-m][a[t.num-m]]){
             if(t.num-m==zhong) return y+1;
           vis[t.num-m][a[t.num-m]]=y+1;
           e.num=t.num-m;e.st=a[t.num-m];
           que.push(e);
        }

        }
    }


   }
   return 0;
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    memset(vis,0,sizeof(vis));
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          scanf("%d",&a[i*m+j]);
   int a1,a2,b1,b2;
   scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
   a1--;a2--;b1--;b2--;
   printf("%lld\n",bfs(a1*m+a2,b1*m+b2)-1);
  }
return 0;
}
