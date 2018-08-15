#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
 int n,m;
  while(cin>>n>>m){
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edge[x][y]=0;
        edge[y][x]=0;
    }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++){
        if(edge[i][j]) unin(i,j);
    }
    for(int i=1;i<=n;i++){
        if(find)

  }
}
