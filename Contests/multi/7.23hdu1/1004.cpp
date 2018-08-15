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
const int maxn=1e5+100;
struct node{
  int l,r;
bool operator<(const node &b)const{
if(l==b.l) return r<b.r;
return l<b.l;
}
}a[maxn];
int ans[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(ans,0);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
              scanf("%d%d",&a[i].l,&a[i].r);

        }
        sort(a+1,a+1+m);
        priority_queue<int,vector<int>,greater<int> >que;
        for(int i=1;i<=n;i++)
            que.push(i);
        int pre=a[1].l;
        int las=a[1].r+1;
        for(int i=1;i<=m;i++)
        {
           // for(int j=pre;j<a[i].l;j++)
            //  ans[j]=1;
            for(int j=max(pre,a[i].l);j<=a[i].r;j++)
            {
                int t=que.top();
                que.pop();
                ans[j]=t;
            }
            las=max(las,a[i].r+1);
            if(i!=m){
            for(int j=a[i].l;j<min(a[i+1].l,las);j++)
            {
                que.push(ans[j]);
            }
            }
            pre=max(pre,a[i].r+1);
        }
        for(int i=1;i<n;i++)
        if(ans[i]==0)
            printf("1 ");
        else printf("%d ",ans[i]);
        if(ans[n]==0)
           printf("1");
        else   printf("%d",ans[n]);
        printf("\n");
         //printf("%d\n",ans[n]);
    }
  
 return 0;
  }
