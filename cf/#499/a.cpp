#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
char s[100];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,m;
   while(cin>>n>>m)
   {
       cin>>s;
       sort(s,s+n);
       ll ans=0;
       char pre=s[0];
       ans+=s[0]-'a'+1;
       int cnt=1;
       for(int i=1;i<n;i++)
       {
        if(s[i]>pre+1)
          ans+=s[i]-'a'+1,cnt++,pre=s[i];
         if(cnt>=m) break;
       }
       if(cnt<m) cout<<-1<<endl;
       else cout<<ans<<endl;
   }

 return 0;
  }

