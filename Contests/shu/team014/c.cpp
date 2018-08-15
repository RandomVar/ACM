#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int main(){
 int t;scanf("%d",&t);
 int k=0;
 while(k<t){
    k++;
    int n,m;ll e;
    scanf("%d%d%lld",&n,&m,&e);
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    ll cnt=0;
    ll t1=0,t2=0;
    if(n<m) printf("Case #%d: 0\n",k);
    else{for(int i=0;i<m;i++)
        t1=t1+(ll)a[i];
    if(t1>=e) cnt++;
   for(int i=m;i<n;i++){
        t2=t1-a[i-m]+a[i];
        if(t2>=e) cnt++;
        t1=t2;
   }
   printf("Case #%d: %lld\n",k,cnt);
   // cout<<"Case #"<<k<<": "<<cnt<<endl;
 }}
}
