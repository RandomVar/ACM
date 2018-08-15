#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll a[maxn];
int be[maxn];
ll c[maxn];
int main(){
   int n,m,k;
   while(cin>>n>>k>>m){
     //if(n%2) cout<<"Ehab"<<endl;
     //else cout<<"Mahmoud"<<endl;
     string s;
     memset(c,0x3f,sizeof(c));
     map<string,int>mp;
     for(int i=1;i<=n;i++){
        cin>>s;
        mp[s]=i;
     }
      for(int i=1;i<=n;i++)
        cin>>a[i];
        ll cnt=0;
      for(int i=1;i<=k;i++){
         int x;
         cin>>x;
         //ll ans=0;
         for(int j=1;j<=x;j++)
         {
             int t;
             cin>>t;
             be[t]=i;
             c[i]=min(c[i],a[t]);
         }

       // cnt+=ans;
      }
      for(int i=1;i<=m;i++){
         cin>>s;
         int t=mp[s];
         cnt+=c[be[t]];
      }
      cout<<cnt<<endl;
   }


}
