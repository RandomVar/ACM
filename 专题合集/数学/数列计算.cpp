
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
typedef vector<ll> vec;
typedef vector<vec> mat;
const int MOD=100000007;
//计算A*B
mat mul(mat &A,mat &B){
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++)
	  for(int k=0;k<B.size();k++)
	    for(int j=0;j<B[0].size();j++)
	      C[i][j]=(C[i][j]%MOD+(((A[i][k]%MOD)*(B[k][j]%MOD))%MOD))%MOD;
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
//输入
ll n;
int main(){
    ll n;
    while(cin>>n){
	mat A(4,vec(4));//行数，列数
	A[0][0]=3;A[0][1]=2;A[0][2]=3;A[0][3]=3;
	A[1][0]=1;A[1][1]=0;A[1][2]=0;A[1][3]=0;
	A[2][0]=0;A[2][1]=0;A[2][2]=3;A[2][3]=0;
	A[3][0]=0;A[3][1]=0;A[3][2]=3;A[3][3]=3;
	A=pow(A,n-1);
	mat B(4,vec(1));
	B[0][0]=2;B[1][0]=1;B[2][0]=3;B[3][0]=3;
	B=mul(A,B);
	if(n!=0) cout<<B[0][0]<<endl;
	else cout<<1<<endl;
	//cout<<B[2][0]<<endl;
}
return 0;
}
