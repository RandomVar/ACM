#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int vis[15];
int check(){
    memset(vis,0,sizeof(vis));
  for(int i=0;i<5;i++){
    if(vis[a[i]]) return 0;
    else vis[a[i]]=1;
    if(vis[b[i]]) return 0;
    else vis[b[i]]=1;
  }
  return 1;
}
int main(){
  int n;int m=0;
   while(cin>>n&&n){
        if(m>0) cout<<endl;
         m++;
        int f=0;
    for(int i=1234;i<=98765;i++){

            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            int x=i;
            int y=i*n;
            if(y>98765) break;
            int k=4;
            do{
             a[k--]=x%10;
             x=x/10;
             //cout<<a[k+1]<<endl;
           }while(x);
           k=4;
           do{
            b[k--]=y%10;
            y=y/10;
           }while(y);

          // for(int i=0;i<5;i++)
            //cout<<a[i];
        if(check()){
                f=1;
           for(int j=0;j<5;j++)
            cout<<b[j];
           cout<<" / ";
           for(int j=0;j<5;j++)
             cout<<a[j];
            cout<<" = ";
            cout<<n<<endl;
            }
    }

    if(f==0) cout<<"There are no solutions for "<<n<<"."<<endl;
       // cout<<endl;
    }

}
