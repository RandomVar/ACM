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
ll dp[1010];
int main()
{
    int t;
    cin>>t;
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=1000;i++)
      dp[i]=dp[i-1]+dp[i-2];
    while(t--){
        int n;cin>>n;
        cout<<dp[n]<<endl;
    }

}
