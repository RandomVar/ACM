#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
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
const int maxn=3*1e5;
typedef pair<int,int>p;
priority_queue<p,vector<p>,greater<p> >ren;
struct node{
 int l,r,id;
 bool operator<(const node &b)const{
 if(l==b.l) return r>b.r;
 return l<b.l;
 }
}a[maxn+10];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
    while(!ren.empty())
      ren.pop();
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        ren.push(p{a[i].r,i});
    }
    sort(a,a+n);
    int ii=-1,jj=-1;
    /*for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].r>=a[j].r) {ii=a[i].id;jj=a[j].id;break;}
            if(a[i].r<a[j].l) break;
        }
        if(ii!=-1) break;
    }*/
    for(int i=0;i<n;i++){
        p t=ren.top();
        ren.pop();
        if(t.fir==a[i].r){
            if(ren.empty()) break;
             t=ren.top();
            if(t.fir>a[i].r){continue;}
        }
      ii=a[i].id;jj=t.sec;break;
    }
    if(ii!=-1) cout<<jj+1<<" "<<ii+1<<endl;
    else cout<<"-1 -1"<<endl;
  }
}
