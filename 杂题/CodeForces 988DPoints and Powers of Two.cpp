#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[5];
int main(){
   int n;

   while(cin>>n){
          map<ll,int>mp;
     for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        mp[t]++;
     }
     int flag=1;
    map<ll,int>::iterator it;
    it=mp.begin();
    ans[0]=it->first;
    for(it=mp.begin();it!=mp.end();it++){

        for(int j=0;j<=31;j++){
            ll t=it->first+(1<<j);
            if(mp.find(t)!=mp.end()){
                 ans[0]=it->first;
                ans[1]=t;
                flag=2;
                ll x=it->first+(1<<(j+1));
                if(mp.find(x)!=mp.end())
                   {
                       ans[2]=x;
                       flag=3;break;
                   }

            }
        }
        if(flag==3) break;
    }
     cout<<flag<<endl;
     for(int i=0;i<flag;i++)
        cout<<ans[i]<<" ";
     cout<<endl;
     }
return 0;

   }

