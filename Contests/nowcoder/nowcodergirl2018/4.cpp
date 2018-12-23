#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll a[maxn],ans[maxn];
const int maxm=1e6+100;
int cnt[maxm];
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++)
         scanf("%lld",&a[i]);
       for(int i=1;i<=n;i++)
       printf("%lld ",ans[i]);
    }
}