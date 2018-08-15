#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<stack>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);

const int maxn=3*1e5;
struct node{
  int val;
  int pre;
}s[maxn+10];
int tou[maxn+10];
int ptr[maxn+10];
int main(){
   // freopen("data.out","w",stdout);
 int t;
 scanf("%d",&t);
 while(t--){
        memset(ptr,0,sizeof(ptr));
    int n,q;int k=0;
   scanf("%d%d",&n,&q);
    for(int i=0;i<q;i++){
        int op,ob;
        scanf("%d%d",&op,&ob);
        if(op==1){
            int va;
            scanf("%d",&va);
                s[++k].pre=ptr[ob];
                if(ptr[ob]==0) tou[ob]=k;
                ptr[ob]=k;
                s[k].val=va;

        }
        if(op==2){
            if(ptr[ob]){
                 //   cout<<ptr[ob]<<endl;
            printf("%d\n",s[ptr[ob]].val);
            ptr[ob]=s[ptr[ob]].pre;
            }
            else printf("EMPTY\n");
        }
        if(op==3){
            int o2;
            scanf("%d",&o2);
           // int t=ptr[o2];
            if(ptr[o2]){
            if(ptr[ob]==0) tou[ob]=tou[o2];
            s[tou[o2]].pre=ptr[ob];
          //  cout<<tou[o2]<<endl;
            ptr[ob]=ptr[o2];
            ptr[o2]=0;
            }}
        }}
 return 0;
}
/*
2
2 15
1 1 2
1 1 3
1 1 4
1 2 5
1 2 6
3 1 2


2
2 15
1 2 2
1 2 3
3 1 2
*/
