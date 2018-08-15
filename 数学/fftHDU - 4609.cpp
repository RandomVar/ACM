#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const double pi = acos(-1.0);
const ll INF= 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
typedef complex<double> cd;//C++ 自带复数类，需要头文件complex
const int maxn=3e5+10;
ll d[maxn],a[maxn],b[maxn];
int rev[maxn];
cd c[maxn];

 void fft(cd *a, int n,int f) {
   for(int i = 0;i < n;i ++)
         if(i < rev[i])
             swap(a[i], a[rev[i]]);
     for(int i = 1;i < n;i <<= 1) {
         cd wn(cos(pi / i), sin(f * pi / i)), x, y;
         for(int j = 0;j < n;j += (i << 1)) {
             cd w(1, 0);
             for(int k = 0;k < i;k ++, w *= wn) {
                 x = a[j + k], y = w * a[i + j + k];
                 a[j + k] = x + y;
                 a[i + j + k] = x - y;
             }
         }
     }
 }
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       ll M=0;
       mem(b,0);
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
           M=max(M,a[i]);
           b[a[i]]++;
       }
       int bit=0;
       ll N;
       for(N = 1;N <= (M + 1) * 2;N <<= 1) bit++;
       for(int i = 0;i < N;i ++)
             rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
       for(int i=0;i<N;i++)
        c[i]=b[i];
       fft(c,N,1);
       for(int i=0;i<N;i++)
        c[i]*=c[i];
       fft(c,N,-1);
       for(int i=0;i<N;i++)
         d[i]=(ll)(c[i].real()/N+0.5);//四舍五入
       for(int i=1;i<=n;i++)
         d[a[i]*2]--;
        for(int i=0;i<N;i++)
         d[i]/=2;
          d[N]=0;
        for(int i=N-1;i>=0;i--)
         d[i]+=d[i+1];
        
         sort(a+1,a+1+n);
         ll ans=0;
         for(int i=1;i<=n;i++)
         {
            ans+=d[a[i]+1];
           // cout<<d[a[i]+1]<<endl;
            ans-=1LL*(n-i)*(n-i-1)/2;
            ans-=1LL*(n-i)*(i-1);
            ans-=n-1;
         }
        printf("%.7f\n", 1.0 * ans / (1LL* n * (n - 1) * (n - 2) / 6));
   }
 return 0;
  }
