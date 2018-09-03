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
const int maxn=2*1e6+100;
int dp[maxn][40][2];
void ST(int n) {

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
               dp[i][j][0] = max(dp[i][j - 1][0], dp[i + (1 << (j - 1))][j - 1][0]);
               dp[i][j][1] = min(dp[i][j - 1][1], dp[i + (1 << (j - 1))][j - 1][1]);

        }
    }
}
int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;

    return max(dp[l][k][0], dp[r - (1 << k) + 1][k][0])-min(dp[l][k][1], dp[r - (1 << k) + 1][k][1]);
}
int main(){
   int n,q;
   while(cin>>n>>q){
    for(int i=1;i<=n;i++){
        cin>>dp[i][0][0];
        dp[i][0][1]=dp[i][0][0];
    }
    ST(n);
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<RMQ(x,y)<<endl;

    }
   }
return 0;
}
