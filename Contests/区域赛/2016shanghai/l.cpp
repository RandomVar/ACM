#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=100000;
int casenum,t;
int a,b,c,d;
int cnt;
int data1[maxn][5];
int getdata[5];
void dfs(int k,int res,int t1,int t2,int t3,int t4)///将要处理第k场
{
    if(k<=3){
        if(res==0)
        {
            //data1[cnt][k+1]+=3;
            if(k==1) t2+=3;
            else if(k==2) t3+=3;
            else t4+=3;
        }
        else if(res==1) t1+=3;
        else if(res==2) {
            t1+=1;
            if(k==1) t2+=1;
            else if(k==2) t3+=1;
            else t4+=1;
        }
    }
    else if(k>3&&k<=5)
    {
        if(res==0) {
                //data1[cnt][k-1]+=3;
            if(k==4) t3+=3;
            else if(k==5) t4+=3;
        }
        else if(res==1) t2+=3;
        else if(res==2) {
            t2+=1;
            //data1[cnt][k-1]+=1;
            if(k==4) t3+=3;
            else if(k==5) t4+=3;
        }
    }
    else if(k==6){
        if(res==0) t4+=3;
        else if(res==1) t3+=3;
        else if(res==2) {
            t4+=1;
            t3+=1;
        }
    }
    if(k==6)
    {
        data1[cnt][1]=t1;
        data1[cnt][2]=t2;
        data1[cnt][3]=t3;
        data1[cnt][4]=t4;
////     for(int i=1;i<=4;i++)
//        printf("%d ",data1[cnt][i]);
//        printf("\n");
        ++cnt;
        return ;
    }
    else {
        dfs(k+1,0,t1,t2,t3,t4);
        dfs(k+1,1,t1,t2,t3,t4);
        dfs(k+1,2,t1,t2,t3,t4);
    }
    return ;
}
void init()
{
    cnt=1;
    casenum=0;
    memset(data1,0,sizeof(data1));
    memset(getdata,0,sizeof(getdata));
    dfs(1,0,0,0,0,0);
    dfs(1,1,0,0,0,0);
    dfs(1,2,0,0,0,0);
}
int main()
{
    scanf("%d",&t);
    init();
    while(t--)
    {
        scanf("%d %d %d %d",&getdata[1],&getdata[2],&getdata[3],&getdata[4]);
        bool cz=false;
        bool cf=false;
        for(int i=1;i<=cnt-1;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(getdata[j]!=data1[i][j])
                {
                    break;
                }
                if(j==4)
                {
                    if(cz==false) cz=true;
                    else cf=true;
                }
            }
        }
        if(cf) printf("Case #%d: No\n",++casenum);
        else if(cz) printf("Case #%d: Yes\n",++casenum);
        else printf("Case #%d: Wrong Scoreboard\n",++casenum);
    }
}
