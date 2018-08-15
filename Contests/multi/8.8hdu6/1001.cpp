#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;

int ans[1000];
int main()
{
  //ios_close;
  int t;
  cin>>t;
  while(t--)
  {
    long double a,b;
    cin>>a>>b;
    long double aa =(long double)a*b*pi +(long double)2*b;
    printf("%.8lf\n",(double)aa);
    ll c=(floor)(aa*(ll)1e6);
    cout<<c<<endl;
    int k=0;
    while(c)
    {
        ans[k++]=c%10;
        c/=10;
    }
    for(int i=k-1;i>=6;i--)
     cout<<ans[i];
     cout<<".";
     for(int i=5;i>=0;i--)
      cout<<ans[i];
      cout<<endl;
    //
    //double x=c*1.0/1000000.0;
    //long double x=(long double)c*1.0/1000000.0;
    //printf("%.8lf\n",(double)ans);
    //printf("%.6lf\n",(double)x);
  }
  return 0;
}
