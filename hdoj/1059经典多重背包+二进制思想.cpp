#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#define N 122000
using namespace std;  
int d[N],m,s[7];  
void completepack(int c,int w)//c是价值，w也是价值 
{  
    for(int i=c;i<=m;i++)  //m为总价值 
        if(d[i-c]+w>d[i])   d[i]=d[i-c]+w;  
}  
void zeroonepack(int c,int w )//  同 
{  
    for(int i=m;i>=c;i--)  
        if(d[i-c]+w>d[i])   d[i]=d[i-c]+w;  
}  
/*二进制表示的思想 
把每n[i] 中的每个物品都当成一个独立的物品，
而这 n[i] 个物品能够表示的重量其实用 log n[i]个组合后的物品就能表示。*/ 
void multiplepack(int c,int w,int t)  
{  
    if(t*w>=m)  completepack(c,w);  //t为数量 
    else  
    {  
        int k=1;  
        while(k<t)    
        {  
            zeroonepack(c*k,w*k);  
            t-=k;   
            k<<=1;  
        }   
        zeroonepack(c*t,w*t);  //组合后的余数t 
    }  
}  
  
int main()  
{  
    int kase=0;  
    while(1)  
    {  
        m=0;  
        for(int i=1;i<=6;i++)  
        {  
            scanf("%d",&s[i]);  
            m+=s[i]*i;  
        };  
        if(!m)   break;  
        printf("Collection #%d:\n",++kase);  
        if(m&1)  
        {  
            printf("Can't be divided.\n\n");  
            continue;  
        }  
        m/=2;  
        memset(d,0,sizeof(d));  
        for(int i=1;i<=6;i++)  
            multiplepack(i,i,s[i]);  
        if(d[m]==m) printf("Can be divided.\n\n");  
            else printf("Can't be divided.\n\n");  
    }  
    return 0;
}  
