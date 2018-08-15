#include<bits/stdc++.h>
using namespace std;
char mp[110][110];
int a[110][110];
int dx[]={0,0,-1,-1,-1,1,1,1};
int dy[]={1,-1,0,1,-1,0,1,-1};
int main(){
  int n,m;
  while(cin>>n>>m){
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
         if(mp[i][j]=='*'){
                a[i][j]=-1;
             for(int k=0;k<8;k++){
                int xx=i+dx[k];
                int yy=j+dy[k];
                if(xx>=0&&xx<n&&yy>=0&&yy<m)
                     if(a[xx][yy]!=-1) a[xx][yy]++;
             }

         }
    }
    int flag=1;
     for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
          if(a[i][j]==0) {
              if(mp[i][j]!='.') {flag=0;break;}
          }
         else if(a[i][j]!=-1) {
            if(a[i][j]!=mp[i][j]-'0') {flag=0;break;}
         }
      }
      if(flag) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }

}
