#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN],f[MAXN];
//用二分查找的方法找到一个位置，使得num>b[i-1] 并且num<b[i],并用num代替b[i]
int Search(int num,int low,int high) {
  int mid;
  while(low<=high)  {
    mid=(low+high)/2;
	if(num>b[mid])  low=mid+1;
	else   high=mid-1;
	}
	 return low;
	 }
int DP(int n) {
    int i,len,pos;
    b[1]=a[1];
    c[1]=1;
    len=1;
    for(i=2;i<=n;i++) {
        if(a[i]>b[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
		 {
        len=len+1; b[len]=a[i];
        c[i]=len;
          }
        else if(a[i]==b[len]){
            c[i]=len;
         }
        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        { pos=Search(a[i],1,len);
        b[pos]=a[i];
        c[i]=pos;
			   }}
    return len; }

int Search2(int num,int low,int high) {
  int mid;
  while(low<=high)  {
    mid=(low+high)/2;
	if(num>d[mid])  low=mid+1;
	else   high=mid-1;
	}
	 return low;
	 }
int DP2(int n) {
    int i,len,pos;
    d[1]=f[1];
    e[1]=1;
    len=1;
    for(i=2;i<=n;i++) {
        if(f[i]>d[len])//如果a[i]比b[]数组中最大还大直接插入到后面即可
		 {
        len=len+1; d[len]=f[i];
        e[i]=len;
         }
         else if(f[i]==d[len]){
            e[i]=len;
         }
        else//用二分的方法在b[]数组中找出第一个比a[i]大的位置并且让a[i]替代这个位置
        { pos=Search2(f[i],1,len);
        d[pos]=f[i];
         e[i]=pos;
			   }}
    return len; }

int main(){
  int n;
  while(cin>>n){
      memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  memset(d,0,sizeof(d));
  memset(e,0,sizeof(e));
  memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        cin>>a[i];
  DP(n);

   for(int i=1;i<=n;i++){
    f[i]=a[n-i+1];
   }
   DP2(n);

    int ans=0;
    for(int i=1;i<=n;i++){
        int t=min(c[i],e[n-i+1])*2-1;
        ans=max(ans,t);
    }
   cout<<ans<<endl;
  }
}
