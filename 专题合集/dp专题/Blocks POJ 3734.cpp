/*ai为到第i个格子为止红绿均为偶数的情况个数 bi为红绿有一个为偶数 ci为均为奇数
ai+1=2*ai + bi;
bi+1=2*ai + 2*bi + 2*ci;
ai+1=       bi + 2*ci;
初始 a0=1;b0=0;c0=0; 
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
typedef vector<int> vec;
typedef vector<vec> mat;
const int MOD=10007;
//计算A*B
mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	  for(int k=0;k<B.size();k++)
	    for(int j=0;j<B[0].size();j++)
	      C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
	return C;
} 
//计算 A^n
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
	mat A(3,vec(3));
	A[0][0]=2;A[0][1]=1;A[0][2]=0;
	A[1][0]=2;A[1][1]=2;A[1][2]=2;
	A[2][0]=0;A[2][1]=1;A[2][2]=2;
	A=pow(A,n);
	mat B(3,vec(1));
	B[0][0]=1;B[1][0]=0;B[2][0]=0;
	A=mul(A,B);
	cout<<A[0][0]<<endl;
}
int main(){
	int t;cin>>t;
	while(t--){
		ll n;
		cin>>n;
		solve(n);
	}
}
