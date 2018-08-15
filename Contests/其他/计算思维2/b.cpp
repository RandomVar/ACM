#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
double a[40],c[40],j[40];
int main(){
  int n;
  scanf("%d",&n);int k=0;
  memset(j,0,sizeof(j));
  while(k<n){
    k++;
    getchar();
    char s[200];
    scanf("%s",s);
    scanf("%lf%lf",&c[k],&a[k]);
    //cin>>c[k]>>a[k];
    if(a[k]>=90) j[k]=4.0;
    else if(a[k]>=85) j[k]=3.7;
    else if(a[k]>=82) j[k]=3.3;
    else if(a[k]>=78) j[k]=3.0;
    else if(a[k]>=75) j[k]=2.7;
    else if(a[k]>=72) j[k]=2.3;
    else if(a[k]>=68) j[k]=2.0;
    else if(a[k]>=66) j[k]=1.7;
    else if(a[k]>=64) j[k]=1.5;
    else if(a[k]>=60) j[k]=1.0;
    else j[k]=0;
    //cout<<j[k]<<endl;
  }
  double sum=0,cum=0;
  for(int i=1;i<=n;i++){
    sum+=j[i]*c[i];
    cum+=c[i];
  }
  //cout<<sum<<endl;
  sum/=cum;
  printf("%.4lf\n",sum);
  return 0;
}
