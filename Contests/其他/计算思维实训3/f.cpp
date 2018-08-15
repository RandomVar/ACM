#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
//const int maxn=2147483647;
ll f[50];
void init(){
  f[0]=0;f[1]=1;
  for(int i=2;i<50;i++)
    f[i]=f[i-1]+f[i-2];
}
int Search(ll num,int low,int high) {
  int mid;
  while(low<=high)  {
    mid=(low+high)/2;
	if(num>=f[mid])  low=mid+1;
	else   high=mid-1;
	}
	 return low;
	 }

int main(){
   ll n;
   init();
   while(cin>>n){
    if(n==-1) break;
    int t=Search(n,0,49)-1;
    if(n==1) cout<<1<<endl;
    else if(f[t]==n) cout<<t<<endl;
    else cout<<"Not a Fibonacci number."<<endl;
   }
}

