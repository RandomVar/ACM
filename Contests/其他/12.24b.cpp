#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct line{
  int s,t;
}l[20000];
line xl[20000];
int cmp(line a,line b){
return a.s<b.s;
}
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++)
        cin>>l[i].s>>l[i].t;
    sort(l,l+n,cmp);
    int ans=0;
    xl[0].s=l[0].s;
    xl[0].t=l[0].t;
    for(int i=1;i<n;i++){
        if(l[i].s<=xl[ans].t){
                xl[ans].t=max(l[i].t,xl[ans].t);
        }
        else{
            ans++;
            xl[ans].s=l[i].s;
            xl[ans].t=l[i].t;
            //xt=l[i].t;
        }
    }
    cout<<ans+1<<endl;
    for(int i=0;i<=ans;i++)
        cout<<xl[i].s<<" "<<xl[i].t<<endl;
  }
}
