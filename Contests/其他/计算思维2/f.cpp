#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=10000;
struct mat{
  int x[2][2];
  mat operator =(const int t[2][2]){
      for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
          x[i][j]=t[i][j];
  return *this;
  }
};
mat mul(mat &a,mat &b)
{
    mat c;
   memset(c.x,0,sizeof(c.x));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                c.x[i][j]=(a.x[i][k]*b.x[k][j])%mod;
                c.x[i][j]%=mod;
            }
        }
    }
    return c;
}
mat pow(mat a,ll n)
{
    mat res;
     memset(res.x,0,sizeof(res.x));
    for(int i=0; i<2; i++)
        res.x[i][i]=1;//µ¥Î»¾ØÕó£»
    while(n)
    {
        if(n&1) res=mul(res,a);
        a=mul(a,a);
        n/=2;
    }
    return res;
}
void display(mat a){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++)
        cout<<a.x[i][j]<<" ";
    cout<<endl;}
}
int main(){
    ll n;
    while(cin>>n){
    mat a;
    int t[2][2]={1,0,0,0};
    a=t;
    mat b;
    int t2[2][2]={1,1,1,1};
    b=t2;
    display(b);
    mat ans=pow(b,n-1);
    display(ans);
    ans=mul(ans,a);

    cout<<ans.x[0][0]<<endl;
    }
}
