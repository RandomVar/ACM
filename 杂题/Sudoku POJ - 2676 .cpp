#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10][10];
char b[10][10];
int row[10][10];
int col[10][10];
int g[10][10];
bool dfs(int x,int y){
  if(x==9) return true;
  int flag=1;
  if(a[x][y]){
     if(y<8) return dfs(x,y+1);
      else return dfs(x+1,0);
  }

  else{
    for(int i=1;i<=9;i++){
        if(!row[x][i]&&!col[y][i]&&!g[x/3*3+y/3][i]){
            row[x][i]=1;col[y][i]=1;g[x/3*3+y/3][i]=1;a[x][y]=0;a[x][y]=i;
           if(y<8) flag=dfs(x,y+1);
           else flag=dfs(x+1,0);
           if(!flag) {
             row[x][i]=0;col[y][i]=0;g[x/3*3+y/3][i]=0;a[x][y]=0;
            }
               else return true;
    }}
  }
  return false;
}

int main(){
 int t;
 cin>>t;
 while(t--){

        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(g,0,sizeof(g));
    for(int i=0;i<9;i++){
    getchar();
    for(int j=0;j<9;j++){
        cin>>b[i][j];
        a[i][j]=b[i][j]-'0';
        row[i][a[i][j]]=1;
        col[j][a[i][j]]=1;
        g[i/3*3+j/3][a[i][j]]=1;
    }
    }
    dfs(0,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
              cout<<a[i][j];
            cout<<endl;}
   // else cout<<"wuwu"<<endl;
 }
}
