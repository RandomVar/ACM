#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int a[100010];
ll c[100010];
int main(){
  int t;scanf("%d",&t);int k=0;
  while(k<t){
    k++;
    int n,s;
    scanf("%d%d",&n,&s);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int low=1;int high=n;
    int mid;
    ll cost=0;
    while(low<=high){
        mid=(low+high)/2;
        for(int i=1;i<=n;i++)
            c[i]=a[i]+i*mid;
        sort(c+1,c+n+1);
        cost=0;int flag=0;
        for(int i=1;i<=mid;i++){
            cost+=c[i];
        if(cost>s) {high=mid-1;flag=1;break;}}
        if(flag==0) low=mid+1;
    }
    int ans=low-1;
    if(ans<=0)
        printf("Case #%d: 0 0\n",k);
       // cout<<"Case #"<<k<<": "<<0<<" "<<0<<endl;
    else{
    for(int i=1;i<=n;i++)
            c[i]=a[i]+i*ans;
        sort(c+1,c+n+1);
        cost=0;
        for(int i=1;i<=ans;i++)
            cost+=c[i];
     printf("Case #%d: %d %lld\n",k,ans,cost);
    //cout<<"Case #"<<k<<": "<<ans<<" "<<cost<<endl;
    }}
    return 0;
    }
