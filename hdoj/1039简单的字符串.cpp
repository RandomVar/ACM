#include<cstdio> 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s[1000005];
int main(){
	  while(scanf("%s",s),strcmp(s,"end")){      
    int len=strlen(s);  
    bool flag1=0,flag=0;        
    int a=0,b=0;          
for(int i=0;i<len;i++){  
      if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u'){  
        flag1 = 1;  
        a++;  
        b=0;  
      }else b++,a=0;  
      if(a==3 || b==3){  
        flag = 1;  
        break;  
      }  
      if(i!=0 && s[i]!='e'&&s[i]!='o' && s[i]==s[i-1]){  
        flag = 1;  
        break;  
      }  
    }  
    if(flag || !flag1){  
        printf("<%s> is not acceptable.\n",s);  
    }else printf("<%s> is acceptable.\n",s);  
  }  
	return 0;
}
