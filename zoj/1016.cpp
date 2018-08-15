#include<stdio.h>
#include<string.h>
int main(){
	int n,t,x,a,k,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k); 
		int s[100];
		int left[100],right[100];
		int i=0;
		int y=k;
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(s,0,sizeof(s));
		while(y--){
			scanf("%d",&s[i++]);
		}
		x=0;a=1;
		for(i=0;i<k;i++){
		for(t=0;t<s[i]-s[i-1];t++)  {left[x++]=1;right[x-1]=0;}
		left[x++]=-1;right[x-1]=a++;
	}
	i=0;
	while(1){
	  for(++i;right[i]==0;i++);
	  if(i>x) break;
	  for(j=i-1;;j--) if(left[j]==1) break;
	  a=0;
	  for(t=j;t<i;t++) if(left[t]==-1) a-=1;
	  printf("%d ",i-j+a);
	  left[j]=0;
	  if(i>=x) break;
	}
	printf("\n");

}
return 0;} 
