#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int a[300];
double quickmod(double a,ll b){
	double res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

int main(){
  int n;
  while(cin>>n){
     double k=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k+=a[i]*(1.0/n);
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
    }
    int xx=200;
    if(k==0) printf("0.00\n");
    else if(m==n) printf("inf\n");
    else if(m==0) printf("%.2lf\n",k);
    else{
    double q=(m*1.0)/n;
    double ans=k*(1-quickmod(q,xx));
    ans=ans/(1-q);
    printf("%.2lf\n",ans);
  }}
return 0;
}

