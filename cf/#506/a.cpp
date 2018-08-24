#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    while(cin>>n>>k)
    {
        string s;
        cin>>s;
        int pos=0;
        for(int i=0;i<n;i++)
        {
            int flag=1;
            int p=0;
            for(int j=i+1;j<n&&p-1<n;j++)
            {
                if(s[p++]!=s[j])
                  {flag=0;break;}
            }
            if(flag)
            {
                pos=p;break;
            }
        }
         cout<<s;
        // cout<<pos<<endl;
        for(int i=1;i<k;i++)
        {
            for(int j=pos;j<n;j++)
             cout<<s[j];
        }
        cout<<endl;
    }
 return 0;
  }
