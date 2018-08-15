#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f; 
const int maxn=100010;
int a[maxn];
int cnt[maxn];
int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		a[0]=0;a[n+1]=INF;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			int x=i-1;
			if(!cnt[i]&&a[i]>a[i+1]){
				cnt[i]=1;cnt[i+1]=1;
			}
			int MAX=cnt[x]; 
		  while(!cnt[i]){
			if(a[i]<a[x]) {
				if(cnt[x]==0)
				cnt[i]=cnt[x]=MAX+1;
			    else {cnt[i]=cnt[x]+1;}
			}
			if(cnt[x]==0||cnt[i]) break;
			if(cnt[x]>0){
				int j;
				for(j=i-1;cnt[j]<=cnt[x]&&cnt[j]!=0;j--);
				x=j;MAX=max(MAX,cnt[x]);
			}	  
		}
		}
	  int ans=0;	
	  for(int i=1;i<=n;i++) if(cnt[i]==0) ans++;
	  cout<<ans<<endl;
	  for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
	  cout<<endl;
	   for(int i=1;i<=n;i++)
	     if(cnt[i]==0) cout<<a[i]<<" ";
	cout<<endl;
	}
}
/*
5
11
1 4 2 7 3 4 5 9 3 2 3
*/
