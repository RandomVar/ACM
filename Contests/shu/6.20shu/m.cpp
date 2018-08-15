#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll gcd(ll a,ll b){
         if(a < b){
                   swap(a,b);
         }
         while(a % b){
             ll r = a % b;
                   a = b;
                   b = r;
         }
         return b;
}
ll lcm(ll a,ll b){
 return a/gcd(a,b)*b;

}
ll a[20];

int main(){
   ll n;int m;
   while(cin>>n>>m){
      for(int i=0;i<m;i++)
        cin>>a[i];
        ll num=0;
     for(int i=1;i<(1<<m);i++){
         ll ans=1;int ant=0;
         for(int j=0;j<m;j++){
            if(i&(1<<j)){
                ans=lcm(ans,a[j]);
                ant++;
            }
         }
            if((ant-1)%2) num-=(n/ans);
           else num+=(n/ans);

     }
     cout<<n-num<<endl;
   }


return 0;
}
