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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll MOD=10000;
ll f[50];
//A*B
mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	  for(int k=0;k<B.size();k++)
	    for(int j=0;j<B[0].size();j++)
	      C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	return C;
}
//A^n
mat pow(mat A,ll n){
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++)
	  B[i][i]=1;
	while(n>0){
		if(n&1) B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}

void solve(ll n){
	mat A(2,vec(2));//行数，列数
	A[0][0]=1;A[0][1]=1;
	A[1][0]=1;A[1][1]=0;
	A=pow(A,n-2);
    mat B(2,vec(1));
    B[0][0]=1;B[1][0]=1;
    A=mul(A,B);
    //ll x=A[0][0]%MOD;
    //int len=log10(x)+1;
   // for(int i=4;i>len;i--)
   //  printf("0");
	printf("%04d\n",(int)A[0][0]%MOD);
}
void init()
{
    f[0]=0;f[1]=1;
    for(int i=2;i<=40;i++)
      f[i]=f[i-1]+f[i-2];
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll n;
   init();
   while(scanf("%lld",&n)==1)
   {
    //   solve(n);
       if(n<=39)
       {
           printf("%lld\n",f[n]);
       }
      else
         {
            double ans=-0.5*log10(5.0)+n*1.0*log10((1+sqrt(5.0))/2.0);
            ans=ans-(ll)ans;
            double a=pow(10.0,ans);
            a=1000*a;
            printf("%lld...",(ll)a);
             solve(n);
         }
   }
 return 0;
  }

