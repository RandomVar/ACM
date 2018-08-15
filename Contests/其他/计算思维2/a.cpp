#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int a[110];
int main(){
  int n;cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
    int sum=0;
  for(int i=0;i<n;i++)
    sum+=a[i];
  cout<<sum/n<<endl;
}
