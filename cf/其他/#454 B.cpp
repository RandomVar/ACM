#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
 char s[10][10];
int main(){
 while(cin>>s[1][1]){
        int flag=0;
 for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++)
      if(!(i==1&&j==1)) cin>>s[i][j];
    getchar();
    if(i%3==0&&i!=9) getchar();
    }
    //cout<<1<<endl;
    int x,y;
   cin>>x>>y;
   int x1=x%3;
   int y1=y%3;
   if(x1==0) x1=3;
   if(y1==0) y1=3;
 //  cout<<x1<<y1<<endl;
   for(int i=1;i<=9;i++){
     for(int j=1;j<=9;j++){
       if(i>=3*(x1-1)+1&&i<=3*x1&&j>=3*(y1-1)+1&&j<=3*y1&&s[i][j]=='.'){
            //cout<<i<<j<<endl;
         flag=1;break;
         }}
         if(flag) break;
         }
 //cout<<flag<<endl;
    if(!flag){
        for(int i=1;i<=9;i++){
          for(int j=1;j<=9;j++){
       if(s[i][j]=='.'){
         cout<<'!';}
        else cout<<s[i][j];
        if(j%3==0&&j!=9) cout<<" ";
        if(j==9) cout<<endl;
   }
   if(i%3==0&&i!=9) cout<<endl;}
   }

    else{
   for(int i=1;i<=9;i++){
     for(int j=1;j<=9;j++){
       if(i>=3*(x1-1)+1&&i<=3*x1&&j>=3*(y1-1)+1&&j<=3*y1&&s[i][j]=='.'){
         cout<<'!';}
        else cout<<s[i][j];
        if(j%3==0&&j!=9) cout<<" ";
        if(j==9) cout<<endl;
   }
   if(i%3==0&&i!=9) cout<<endl;}
 }}
}
