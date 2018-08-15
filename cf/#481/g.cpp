#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
 int s,d,c,id;
 bool operator<(const node &b)const{
 return d<b.d;
 }

}a[150];
int c[150];
int main(){
  int n,m;
  while(cin>>n>>m){
        memset(c,0,sizeof(c));
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].s>>a[i].d>>a[i].c;
        a[i].id=i;
        c[a[i].d]=m+1;
    }
    sort(a+1,a+1+m);
  int flag=1;
    for(int i=1;i<=m;i++){
            int cnt=0;
          //cout<<a[i].s<<endl;
        for(int j=a[i].s;j<a[i].d;j++){
               // cout<<c[j]<<endl;
            if(c[j]==0){
                cnt++;c[j]=a[i].id;
               // cout<<c[j]<<endl;
            }
            if(cnt==a[i].c) break;
        }
        if(cnt<a[i].c) {flag=0;break;}
    }
    if(flag==0) cout<<-1<<endl;
    else{
        for(int i=1;i<n;i++)
            cout<<c[i]<<" ";
            cout<<c[n]<<endl;
    }
  }
return 0;

}
