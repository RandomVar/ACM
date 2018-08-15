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
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dp[1<<17][17][17];
int vis[1<<17][17][17];
char s[10][10];
int n,m;
struct node{
    int cost;int st;int csl;int one;
   bool operator<(const node &b)const{
       return cost>b.cost;
   }
};
int ans;
int dij(int st){
	dp[(1<<st)][st][st]=0;
    mem(vis,0);
	priority_queue< node >que;
	que.push(node{0,(1<<st),st,st});
	while(!que.empty()){
       node a=que.top();que.pop();
       if(a.st==ans) return  dp[a.st][a.csl][a.one];
       if(vis[a.st][a.csl][a.one])
         continue;
        vis[a.st][a.csl][a.one]=1;
       int x1=a.csl/m;
       int y1=a.csl%m; 
       int x2=a.one/m;
       int y2=a.one%m;
     //  if(dp[a.st][a.csl][a.one]<a.cost) continue; //optimize in cf 938d
         for(int k=0;k<4;k++)
         {
              int xx1=x1+dx[k];
              int yy1=y1+dy[k];
             if(xx1<0||xx1>=n||yy1<0||yy1>=m) continue;
             if(s[xx1][yy1]=='X') continue;
            for(int e=0;e<4;e++)
           {
              int xx=x2+dx[e];
              int yy=y2+dy[e];
             if(xx<0||xx>=n||yy<0||yy>=m) continue;
             if(s[xx][yy]=='X') continue;
            // cout<<xx1<<" "<<yy1<<" "<<xx<<" "<<yy<<endl;
	     	if(!vis[a.st|(1<<(xx1*m+yy1))|(1<<xx*m+yy)][xx1*m+yy1][xx*m+yy]&&dp[a.st|(1<<(xx1*m+yy1))|(1<<xx*m+yy)][xx1*m+yy1][xx*m+yy]>dp[a.st][a.csl][a.one]+1)
              {
		     dp[a.st|(1<<(xx1*m+yy1))|(1<<xx*m+yy)][xx1*m+yy1][xx*m+yy]=dp[a.st][a.csl][a.one]+1;
               que.push(node{dp[a.st|(1<<(xx1*m+yy1))|(1<<xx*m+yy)][xx1*m+yy1][xx*m+yy],a.st|(1<<(xx1*m+yy1))|(1<<xx*m+yy),xx1*m+yy1,xx*m+yy});
	        }
            /*if(dp[a.st|(1<<(xx1*m+yy1))][xx1*m+yy1][a.one]>dp[a.st][a.csl][a.one]+1)
              {
		     dp[a.st|(1<<(xx1*m+yy1))][xx1*m+yy1][a.one]=dp[a.st][a.csl][a.one]+1;
               que.push(node{dp[a.st|(1<<(xx1*m+yy1))][xx1*m+yy1][a.one],a.st|(1<<(xx1*m+yy1)),xx1*m+yy1,a.one});
	        }
            if(dp[a.st|(1<<xx*m+yy)][a.csl][xx*m+yy]>dp[a.st][a.csl][a.one]+1)
              {
		     dp[a.st|(1<<(xx*m+yy))][a.csl][xx*m+yy]=dp[a.st][a.csl][a.one]+1;
               que.push(node{dp[a.st|(1<<(xx*m+yy))][a.csl][xx*m+yy],a.st|(1<<xx*m+yy),a.csl,xx*m+yy});
	        }*/
   
} }}
return -1;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  //int n,m;
  while(cin>>n>>m)
  {
      mem(dp,0x3f);
      
      for(int i=0;i<n;i++)
       cin>>s[i];
       //dp[]
       int s1=-1;
       for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
            {
          if(s[i][j]=='S')
             s1=i*m+j;
           }
           //dp[1<<s1]=0;
     
          ans=0;
          for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
             if(s[i][j]!='X') ans|=(1<<(i*m+j));
                 cout<<dij(s1)<<endl;
       /* int cnt=inf;
        for(int i=0;i<n*m;i++)
          for(int j=0;j<n*m;j++)
            cnt=min(cnt,dp[ans][i][j]);
       cout<<cnt<<endl;
         */      

  }

 return 0;
  }

