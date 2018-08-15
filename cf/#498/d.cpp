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
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n)
   {
       string a,b;
       cin>>a >>b;
       int ans=0;
       int len=a.size();
       for(int i=0;i<len/2;i++)
         {
             if(a[i]==b[i]) continue;
             if(b[i]==a[len-i-1]){
                swap(a[i],a[len-i-1]);
                continue;
             }
             if(a[i]==b[len-i-1])
             {
                 swap(b[i],b[len-i-1]);
                 continue;
             }
             if(b[i]==b[len-i-1]){
                 swap(a[i],b[len-i-1]);
                 continue;
             }
             /*if(a[i]==a[len-i-1]&&b[i]==b[len-i-1]){
                swap(a[len-i-1],b[i]);
                continue;
             }*/
             ans++;
         }

        for(int i=len/2;i<len;i++)
        {
            if(a[i]!=b[i])
             ans++;
        }
        cout<<ans<<endl;
   }


 return 0;
  }

