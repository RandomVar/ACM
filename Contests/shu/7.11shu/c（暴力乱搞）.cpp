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
char ran[]={'T','J','Q','K','A'};
char sui[]={'s','h','d','c'};
struct node{
   int s,r;
}a[60];
int b[8];
int lcs[60],id[60];
int d[8][20];
int Search(int num,int low,int high) {
  int mid;
  while(low<=high)  {
    mid=(low+high)/2;
	if(num>=lcs[mid])  low=mid+1;
	else   high=mid-1;
	}
	 return low;
	 }
int DP(int n) {
    int i,len,pos;
    lcs[1]=id[1];
    len=1;
    for(i=2;i<=n;i++) {
        if(id[i]>=lcs[len])
		 {
        len=len+1;lcs[len]=id[i];  }
        else
        { pos=Search(id[i],1,len);
        lcs[pos]=id[i];
			   }}
    return len;
     }

int dfs(int x){
   int k=0;
  for(int j=0;j<4;j++){
       
    if(x&(1<<j)){
        for(int i=1;i<=13;i++)
           {
               if(d[b[j]][i])
                    {
                        id[d[b[j]][i]]=++k;
                      // cout<<d[b[j]][i]<<endl;
                    }
           }
    }
    else{
          for(int i=13;i>0;i--)
           {
               if(d[b[j]][i]){
                    id[d[b[j]][i]]=++k;
             // cout<<d[b[j]][i]<<endl;
           }
           }
    }
  }
  /*for(int i=1;i<=k;i++)
   cout<<id[i]<<" ";
   cout<<endl;
   */int ans=DP(k);
   //cout<<k<<endl;
   //cout<<ans<<endl;
 return ans;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
    mem(d,0);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        
         for(int j=0;j<4;j++)
       {
           if(s[1]==sui[j])
             a[i].s=j;
       }
        if(s[0]>='2'&&s[0]<='9')
           a[i].r=s[0]-'1';
        //if(s[0]=='T') a[i].r 
       for(int j=0;j<5;j++)
       {
           if(s[0]==ran[j])
             a[i].r=9+j;
       }
       d[a[i].s][a[i].r]=i;
      //cout<<a[i].s<<" "<<a[i].r<<" "<<i<<endl;
    }
     for(int i=0;i<4;i++)
        b[i]=i;
    int ans=inf;
     dfs(0);
     do{
    
        
         for(int i=0;i<(1<<4);i++){
          ans=min(ans,n-dfs(i));
         }
    }while(next_permutation(b,b+4));
   
     cout<<ans<<endl;   

  }


  }

