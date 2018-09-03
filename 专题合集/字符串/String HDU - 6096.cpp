#include<bits/stdc++.h>
using namespace std;
void init()
{
  base[0]=1;
  for(int i=1;i<maxn;i++)
    base[i]=base[i-1]*seed;
}
ull str_hash(int l,int r){
  return h[r]-h[l-1]*base[r-l+1];
}
void Hhah(char *s,int flag)
{
    int len=strlen(s);
    if(flag==0)
    {
      ull pre=0;
      for(int i=0;i<len;i++)
        pre=pre*seed+s[i]-'a'+1;
     preh==pre;
    }
    else{
        ull pre=0;
        for(int i=len-1;i>=0;i--)
          pre=pre*seed+s[i]-'a'+1;
        endh=pre;
    }
}
void Hash(char *s,int id)
 {
     int len=strlen(s);
     ull pre=0;
   for(int i=0;i<len;i++)
      pre=pre*seed+s[i]-'a'+1; 
    has1[id]=pre;v.push_back(has1[id]);
   pre=0;
   for(int i=len-1;i>=0;i--)
     pre=pre*seed+s[i]-'a'+1;
    has2[id]=pre;v2.push_back(has2[id]);
}
int getid1(ull x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int getid2(ull x)
{
    return lower_bound(v2.begin(),v2.end(),x)-v2.begin()+1;
}
void solve()
{
    int p1=getid(preh);//>=preh
    // int p2=upper;//>preh
    

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        v.clear();v2.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&buf);
            Hash(buf,i);
        }
        sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
        sort(v2.begin(),v2.end()),v2.erase(unique(v2.begin(),v2.end()),v2.end());
       for(int i=1;i<=n;i++)
       {
           p[i].x=getid1(has1[i]);
           p[i].y=getid2(has2[i]);
       }
        for(int i=1;i<=q;i++)
        {
            scanf("%d",buf);
            Hhash(buf,0);
            scanf("%s",buf2);
            Hhash(buf2,1);
            solve();
        }

     }
}