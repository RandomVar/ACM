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
typedef vector<ll> vec;
typedef vector<vec> mat;
const int mod=1e9+7;
//º∆À„A*B
mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	  for(int k=0;k<B.size();k++)
	    for(int j=0;j<B[0].size();j++)
	      C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
	return C;
}
//º∆À„ A^n
mat powmat(mat A,ll n){
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
// ‰»Î
ll n;

int main(){
  int t;
  cin>>t;
  while(t--){
      ll n,m;
      cin>>m>>n;
      ll len=pow(2,m);
      mat mt(len,vec(len));
      for(int j=0;j<len;j++){
        for(int k=0;k<len;k++){
            if((j|k)==(len-1)&&(j&k)!=len-1)
                  mt[j][k]=1;
        }
      }
     ll ans=0;
     mt=powmat(mt,n-1);
     for(int j=0;j<len;j++)
       for(int i=0;i<len;i++){
           ans=(ans+mt[i][j])%mod;
  }
    cout<<ans<<endl;

}
return 0;
}
