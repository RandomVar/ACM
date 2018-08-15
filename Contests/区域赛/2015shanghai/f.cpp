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
//
int cnt[50];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;int cas=0;
   cin>>t;
   while(t--){
    string s;
    cin>>s;
    int ans=1e4;
    mem(cnt,0);
    for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        if(cnt[x]){
            ans=min(ans,i+1-cnt[x]);
            cnt[x]=i+1;
        }
        else cnt[x]=i+1;

    }
   cout<<"Case #"<<++cas<<": ";
   if(ans==1e4) cout<<-1<<endl;
        else cout<<ans<<endl;

   }
}
