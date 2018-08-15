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
const int maxn=1e6+100;
int que[maxn],b[maxn],a[maxn];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k){
    for(int i=1;i<=n;i++)
         cin>>a[i];
         int top=-1;
    for(int i=1;i<=k;i++)
        {
            if(top==-1||a[i]>=que[top])
                que[++top]=a[i];
           else{
             while(top>=0&&que[top]>a[i]){
                 top--;
             }
             que[++top]=a[i];
           }
           b[0]=que[0];
        }
        int s=0;
    for(int i=k+1;i<=n;i++)
    {
        if(que[s]==a[i-k]) s++;
        if(top<s||a[i]>=que[top])
            que[++top]=a[i];
        else{
             while(top>=s&&que[top]>a[i]){
                 top--;
             }
             que[++top]=a[i];
        }
        b[i-k]=que[s];
    }
     for(int i=0;i<=n-k;i++)
        cout<<b[i]<<" ";
     cout<<endl;
    top=-1;
    for(int i=1;i<=k;i++)
        {
            if(top==-1||a[i]<=que[top])
                que[++top]=a[i];
           else{
             while(top>=0&&que[top]<a[i]){
                 top--;
             }
             que[++top]=a[i];
           }
           b[0]=que[0];
        }
        s=0;
    for(int i=k+1;i<=n;i++)
    {
        if(que[s]==a[i-k]) s++;
        if(top<s||a[i]<=que[top])
            que[++top]=a[i];
        else{
             while(top>=s&&que[top]<a[i]){
                 top--;
             }
             que[++top]=a[i];
        }
        b[i-k]=que[s];
    }
     for(int i=0;i<=n-k;i++)
        cout<<b[i]<<" ";
     cout<<endl;
  }


}
