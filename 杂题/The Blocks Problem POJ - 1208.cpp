/*
理解题意
善用函数
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int st[30][30];
int belong[30];
int top[30];
void movetop(int b){
                int x=belong[b];
                int k;
                 for(k=0;k<top[x];k++){
                    int t=st[x][k];
                    if(t==b) break;
                 }
                 int flag=0;
              for(int i=k+1;i<top[x];i++){
                  int t=st[x][i];
                  belong[t]=t;
                  st[t][top[t]++]=t;
              }
              top[x]=k+1;
}
void movepip(int a,int b){
  int x=belong[a];
  int k;
  for(k=0;k<top[x];k++){
     int t=st[x][k];
     if(t==a) break;
   }
   //cout<<x<<" "<<k<<endl;
   int y=belong[b];
   int flag=0;
  for(int i=k;i<top[x];i++){
     int t=st[x][i];
     st[y][top[y]++]=t;
     belong[t]=y;
     //cout<<"*"<<t<<endl;
  }
  top[x]=k;
}

int main(){
  int n;
  while(scanf("%d",&n)==1){
        mem(top);
        getchar();
     string s;
     for(int i=0;i<n;i++){
        belong[i]=i;
        st[i][top[i]++]=i;
        }
     while(getline(cin,s)){
        if(s=="quit") break;
        stringstream ss(s);
        string s1,s2;
        ss>>s1;
        int a,b;
        ss>>a;ss>>s2;ss>>b;
       // cout<<s1<<s2;
     if(belong[a]!=belong[b]){
        if(s1=="move"){
           if(s2=="onto"){
                movetop(b);
                movetop(a);
                st[belong[b]][top[belong[b]]++]=a;
                top[belong[a]]--;
               belong[a]=belong[b];
           }
           else if(s2=="over"){
             movetop(a);
             st[belong[b]][top[belong[b]]++]=a;
             top[belong[a]]--;
             belong[a]=belong[b];
           }
        }
        else if(s1=="pile"){
            if(s2=="onto"){
                movetop(b);
                movepip(a,b);
            }
            if(s2=="over"){
                movepip(a,b);
            }
        }}
        /*for(int i=0;i<n;i++){
         cout<<i<<":";
         for(int j=0;j<top[i];j++)
            cout<<" "<<st[i][j];
         cout<<endl;
     }*/}
       for(int i=0;i<n;i++){
         cout<<i<<":";
         for(int j=0;j<top[i];j++)
            cout<<" "<<st[i][j];
         cout<<endl;
       }
  }

}
