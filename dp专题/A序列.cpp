#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN],f[MAXN];
//�ö��ֲ��ҵķ����ҵ�һ��λ�ã�ʹ��num>b[i-1] ����num<b[i],����num����b[i]
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
        if(a[i]>b[len])//���a[i]��b[]��������󻹴�ֱ�Ӳ��뵽���漴��
		 {
        len=len+1; b[len]=a[i];
        c[i]=len;
          }
        else if(a[i]==b[len]){
            c[i]=len;
         }
        else//�ö��ֵķ�����b[]�������ҳ���һ����a[i]���λ�ò�����a[i]������λ��
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
        if(f[i]>d[len])//���a[i]��b[]��������󻹴�ֱ�Ӳ��뵽���漴��
		 {
        len=len+1; d[len]=f[i];
        e[i]=len;
         }
         else if(f[i]==d[len]){
            e[i]=len;
         }
        else//�ö��ֵķ�����b[]�������ҳ���һ����a[i]���λ�ò�����a[i]������λ��
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
