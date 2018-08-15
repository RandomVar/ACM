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
const int maxn=100000;
int a[maxn+10];
int cnt[2*maxn+10];
int main(){
   int n;
   while(cin>>n){
        memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=(n+1)/2;i++){
        a[i]-=i;
    }
    for(int i=(n+1)/2+1;i<=n;i++){
        a[i]-=n-i+1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        a[i]+=n;
    cnt[a[i]]++;
    ans=max(ans,cnt[a[i]]);
    }
    cout<<n-ans<<endl;
   }

}
