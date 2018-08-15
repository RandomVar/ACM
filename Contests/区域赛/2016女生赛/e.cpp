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
int cnt1,cnt2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string s[1010];
char a[]={'g','i','r','l'};
char b[]={'c','a','t'};
int n,m;
void dfs1(int u,int v,int cur){
  if(cur==3){cnt1++; return;}
  for(int i=0;i<4;i++){
     int xx=u+dx[i];
     int yy=v+dy[i];
    if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]==a[cur+1]) dfs1(xx,yy,cur+1);
  }
}
void dfs2(int u,int v,int cur){
  if(cur==2) {cnt2++;return;}
  for(int i=0;i<4;i++){
     int xx=u+dx[i];
     int yy=v+dy[i];
    if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]==b[cur+1]) dfs2(xx,yy,cur+1);
  }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--){
    //int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
        cnt1=0;
        cnt2=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          if(s[i][j]=='g')
            dfs1(i,j,0);
            //st1.push_back(node{i,j});
           else if(s[i][j]=='c')
             dfs2(i,j,0);
    cout<<cnt1<<" "<<cnt2<<endl;
   }
   return 0;
   }


