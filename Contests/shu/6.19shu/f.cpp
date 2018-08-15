#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e4+100;
char s[maxn][40];
int dp[maxn][15];
int in[maxn][15];
int c[40][40];
const int seed=31;
ull h[40];
ull str_hash(string ss){
  h[0]=0;
  int len=ss.size();
  for(int j=0;j<len;j++){
           h[j+1]=h[j]*seed+ss[j]-'a'+1;
        }
return h[len];
}
int nump(string s){
    int len=s.size();
    int sum=0;
    memset(c,0,sizeof(c));
  for(int i=len-1;i>=0;i--)
        {
            c[i][i]=true;
            sum++;
            for(int j=i+1;j<len;j++)
            {
                if(s[i]==s[j])
                {
                    if(i+1==j||c[i+1][j-1])
                    {
                        c[i][j]=true;
                        sum++;
                    }
                }
                else c[i][j]=false;
            }
        }
        return sum;
}
void ST(int n) {

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if(dp[i][j - 1]>= dp[i + (1 << (j - 1))][j - 1]) {
                dp[i][j]=dp[i][j - 1];
                in[i][j]=in[i][j-1];
            }
            else{
                dp[i][j]=dp[i + (1 << (j - 1))][j - 1];
                in[i][j]=in[i + (1 << (j - 1))][j - 1];
            }

        }
    }
}
int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    if(dp[l][k]>=dp[r - (1 << k) + 1][k])
        return in[l][k];
    else return in[r - (1 << k) + 1][k];

}
int main(){
  int t;
  scanf("%d",&t);
  //cin>>t;
  while(t--){
    int n,q;
    scanf("%d%d",&n,&q);
    //cin>>n>>q;
    map<ull,int>mp;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        mp[str_hash(s[i])]=i;
        dp[i][0]=nump(s[i]);
        //cout<<dp[i][0]<<endl;
       in[i][0]=i;
    }
    ST(n);
    for(int i=1;i<=q;i++){
        char a[40],b[40];
        scanf("%s",a);
        scanf("%s",b);
        //cin>>a;cin>>b;
        int t1=mp[str_hash(a)];
        int t2=mp[str_hash(b)];
        if(t1>t2) swap(t1,t2);
        printf("%d\n",RMQ(t1,t2));
        //cout<<RMQ(t1,t2)<<endl;

    }
  }

return 0;
}
