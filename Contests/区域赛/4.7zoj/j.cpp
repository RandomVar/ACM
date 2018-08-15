#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
char a[40],b[40],c[80];
int main(){
 int t;
 cin>>t;
 while(t--){
    cin>>a;cin>>b;
    int i;
    for(i=0;i<strlen(b);i++)
        c[i]=b[i];
    for(int j=0;j<strlen(a);j++)
        c[i++]=a[j];
    c[i]='\0';
    c[0]=c[0]+'A'-'a';
    cout<<c<<endl;
 }
 return 0;
}
