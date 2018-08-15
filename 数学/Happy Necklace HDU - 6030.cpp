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
const ll MOD=1e9+7;
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
    mat B(3,vec(3));
    B[0][0]=0;B[0][1]=1;B[0][2]=0;
    B[1][0]=0;B[1][1]=0;B[1][2]=1;
    B[2][0]=1;B[2][1]=0;B[2][2]=1;
	B=pow(B,n-2);
    mat A(3,vec(1));//行数，列数
	A[0][0]=1;A[1][0]=1;A[2][0]=1;
	B=mul(B,A);
	printf("%lld\n",(B[0][0]+B[1][0]+B[2][0])%MOD);
    //cout<<(B[0][0]+B[1][0]+B[2][0])%MOD<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  ll n;
  int t;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%lld",&n);
      if(n>2)
         solve(n);
        if(n==2) printf("2\n");
  
  }


 return 0;
  }

