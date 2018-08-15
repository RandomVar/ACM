#include<bits/stdc++.h>
using namespace std;
int a[5],b[5];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
   int cas=0;
   while(t--){
     for(int i=1;i<=4;i++)
        cin>>a[i];
     for(int i=1;i<=4;i++)
        cin>>b[i];
        int flag=0;
        int f=1;
      for(int i=1;i<=4;i++){
        if(a[i]!=b[i]) {f=0;break;}
     }
    if(f) flag=1;
    if(!flag){
            f=1;
        if(b[1]!=a[3]) f=0;
        if(b[2]!=a[1]) f=0;
        if(b[3]!=a[4]) f=0;
        if(b[4]!=a[2]) f=0;
           if(f) flag=1;
    }

    if(!flag){
        f=1;
        if(b[1]!=a[4]) f=0;
        if(b[2]!=a[3]) f=0;
        if(b[3]!=a[2]) f=0;
        if(b[4]!=a[1]) f=0;
       if(f) flag=1;
    }
    if(!flag){
        f=1;
        if(b[1]!=a[2]) f=0;
        if(b[2]!=a[4]) f=0;
        if(b[3]!=a[1]) f=0;
        if(b[4]!=a[3]) f=0;
       if(f) flag=1;
    }
     cout<<"Case #"<<++cas<<": ";
     if(flag) cout<<"POSSIBLE"<<endl;
     else cout<<"IMPOSSIBLE"<<endl;

       }
    /* */


   }


