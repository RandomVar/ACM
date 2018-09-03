#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int door[20];
int main(){
  string ch;
  while(cin>>ch){
    if(ch=="ENDOFINPUT") break;
    else if(ch=="START"){
        memset(door,0,sizeof(door));
        int s,n;
        cin>>s>>n;
        getchar();
        int doors=0;
    for(int i=0;i<n;i++){
        while(1){
        char x;
        x=getchar();
        if(x=='\n') break;
        doors++;
        door[i]++;
        door[x-'0']++;
        char a=getchar();
        if(a=='\n') break;
        }
    }
    //for(int i=0;i<n;i++)
    //    cout<<door[i]<<endl;
     cin>>ch;
     getchar();int cnt1=-1,cnt2=-1,flag=0;
     for(int i=0;i<n;i++){
        if(cnt1==-1&&cnt2==-1&&door[i]%2) cnt1=i;
        else if(cnt1!=-1&&cnt2==-1&&door[i]%2) cnt2=i;
        else if(cnt1!=-1&&cnt2!=-1&&door[i]%2) {
            flag=1; break;
        }
     }
    if((cnt1==-1||cnt2==-1)&&(!(cnt1==-1&&cnt2==-1&&s==0))) flag=1;
    else if(cnt1==-1&&cnt2==-1&&s==0) flag=0;
    else if((cnt1!=s||cnt2!=0)&&(cnt2!=s||cnt1!=0)) flag=1;
     if(flag) cout<<"NO"<<endl;
     else cout<<"YES "<<doors<<endl;
  }
}}
