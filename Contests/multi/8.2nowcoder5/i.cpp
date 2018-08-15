#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll mod=998244353;
ll ans;
int N;
int bit[maxn];
struct node
{
    int x;
    int y;
    int id;
}point[maxn];
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp2(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x>b.x;
}
bool cmp3(node a,node b)
{
    return a.id<b.id;
}
void add(int x)
{
    for(int i=x;i<maxn;i+=i&-i)
        bit[i]++;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=i&-i)
        res+=bit[i];
    return res;
}
vector<int> all;
int getid(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int le[maxn],ri[maxn];
int main()
{
    while(scanf("%d",&N)==1)
    {
        ans=N;
        ans=(ans+1LL*N*(N-1)/2)%mod;
        memset(bit,0,sizeof(bit));
        all.clear();
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&point[i].y,&point[i].x);
            all.push_back(point[i].y);
            point[i].id=i;
        }
        sort(point,point+N,cmp);
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        for(int i=0;i<N;i++)
        {
            int p=getid(point[i].y);
            le[point[i].id]=i-query(p+1);
            add(p+1);
        }
        int cnt=1;
        for(int i=1;i<N;i++)
        {
            if(point[i].x==point[i-1].x)
                cnt++;
            else
            {
                ans=(ans+2*mod-1LL*cnt*(cnt-1)/2)%mod;
                cnt=1;
            }
        }
        ans=(ans+2*mod-1LL*cnt*(cnt-1)/2)%mod;
        memset(bit,0,sizeof(bit));
        sort(point,point+N,cmp2);
        for(int i=0;i<N;i++)
        {
            int p=getid(point[i].y);
            ri[point[i].id]=i-query(p+1);
            //cout<<i<<" "<<query(p+1)<<"  111"<<endl;
            add(p+1);
        }
        sort(point,point+N,cmp3);
        for(int i=0;i<N;i++)
        {
           //cout<<le[i]<<" "<<ri[i]<<endl;
            ans=(ans+1LL*le[i]*ri[i])%mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
/*
5
1 5
2 4
3 2
4 4
5 6
*/