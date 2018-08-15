/*
构造一个n<=2000的01矩阵 使得1的数量大于等于85000, 且没有四个角都为1的子矩阵


证明
偏移量
j1*k1+i1 = j2*k1+i2 mod p
j1*k3+i1 = j2*k3+i2 mod p

j1*(k1-k3) = j2*(k1-k3) mod p
得 j1=j2
  j*k1+i1 = j*k1+i2 mod p
得 i1=i2

即没有两行偏移量同时相同的两个列块
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/

int a[3100][3100];
int main(){
  cout<<2000<<endl;
  int p=47;
  for(int i=0;i<p;i++)//第i块
    for(int j=0;j<p;j++)//的第j行
      for(int k=0;k<p;k++)//第k列块
         a[i*p+j][k*p+(j*k+i)%p]=1;
         //i*p+j行 
         //k*p k块所在位置
         //j*k 第j行每一块偏移k列
         //+i 每一块块首偏移
    for(int i=0;i<2000;i++)
    {
      for(int j=0;j<2000;j++)
         cout<<a[i][j];
         cout<<endl;
    }
 return 0;
  }

