#include<bits/stdc++.h>
using namespace std;
int s[200][200];
int  check(int x,int y,int key){
  if(x==0){
    if(y==0) return 1;
    else {
        if(s[x][y-1]==key) return 0;
        else return 1;
    }

  }
  else{
    if(y==0){
        if(s[x-1][y]==key) return 0;
        else return 1;
    }
    else{
        if(s[x-1][y]==key) return 0;
        if(s[x][y-1]==key) return 0;
        return 1;
    }
  }
}
int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        int m=50,n=0;
        int xa=a,xb=b,xc=c,xd=d;
        int flag=0;int index=0;
        int f=0;
        while(1){
        for(int i=0;i<m;i++){
            if(xa>1&&check(n,i,1)){
                s[n][i]=1;
                xa--;
            }
            else if(xb&&check(n,i,2)){
                s[n][i]=2;
                xb--;
            }
            else if(xc&&check(n,i,3)){
                s[n][i]=3;
                xc--;
            }
             else if(xd&&check(n,i,4)){
                s[n][i]=4;
                xd--;
            }
            else {
                s[n][i]=1;
                if(n&&s[n-1][i]==1){
                    s[n+1][i]=-1;
                }
                else s[n+1][i]=1;
                f=1;
            }
            if(xa<=1&&xb<1&&xc<1&&xd<1)
            {flag=1;index=i;break;}
        }
        if(flag) break;
        n++;
        }
        if(index<(m-1)){
            if(n==0){
               for(int i=index+1;i<m;i++){
                s[n][i]=s[n][index];
            }
            }
            else{
            for(int i=index+1;i<m;i++){
                s[n][i]=s[n-1][i];
            }
            }
        }
            n++;
        if(f){
            for(int i=0;i<m;i++){
                if(i&&s[n][i]=-1) s[n][i]=s[n][i-1];
                else if(s[n][i]=-1) {s[n][i]=1;  s[n][i+1]=-1;}
               else s[n][i]=1;
            }}
        else{
            for(int i=0;i<m;i++){
                if(f==0) {
                    if(check(n,i,1)) {
                    s[n][i]=1;
                    f=1;
                }
                else{
                    s[n][i]=1;
                }
            }
              else if()
        }}
  cout<<n+1<<" "<<m<<endl;
    for(int i=0;i<=n;i++){
    for(int j=0;j<m;j++){
        if(s[i][j]==1) cout<<'A';
        if(s[i][j]==2) cout<<'B';
        if(s[i][j]==3) cout<<'C';
        if(s[i][j]==4) cout<<'D';
    }
    cout<<endl;
    }
    }

return 0;
}
