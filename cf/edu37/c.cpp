#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int a[200010];
int M[200010],m[200010];
int main(){
  int n;
  while(cin>>n){
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) M[0]=a[i];
        else M[i]=max(a[i],M[i-1]);}
    string s;
    cin>>s;
    for(int i=n-1;i>=0;i--){
       if(i==n-1) m[n-1]=a[i];
       else m[i]=min(a[i],m[i+1]);
    }
    int flag=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='0'){
           if(M[i]>m[i+1]) {flag=1;break;}
        }
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
return 0;
}
