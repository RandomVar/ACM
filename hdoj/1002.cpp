#include<stdio.h>
#include<string.h>
int main() {
	int n,i,j,k,x,y;
	char s[3000];
	char a[2000],b[2000];
	int c[2000];
	int lena,lenb;
	scanf("%d",&n);
	getchar();
	int t=n;
	while(t--){
	  int z=0;
	  gets(s);
	  for(y=0;y<strlen(s);y++) {
	  	a[y]=s[y];
	  if(s[y]==' ') break;}
	  lena=y;
	  for(++y;y<strlen(s);y++)
	  	b[z++]=s[y];
	  lenb=z;k=1;
	  c[0]=a[lena-1]-'0'+b[lenb-1]-'0';
	  for(i=lena-2,j=lenb-2;i>=0&&j>=0;i--,j--){
	    if(c[k-1]<10) c[k++]=a[i]-'0'+b[j]-'0';
	    else {
		  c[k++]=a[i]-'0'+b[j]-'0'+1;
		  c[k-2]=c[k-2]-10;
	     }
       }
       if(i>=0) {
       	for(x=i;x>=0;x--){
		   if(c[k-1]>=10) {c[k-1]-=10; c[k++]=1+a[x]-'0';}
		   else c[k++]=a[x]-'0';}}
       else if(j>=0){
         for(x=j;x>=0;x--) {
		   if(c[k-1]>=10) {c[k-1]-=10; c[k++]=1+b[x]-'0';}
		   else c[k++]=b[x]-'0';}}
       printf("Case %d:\n",n-t);
      for(i=0;i<lena;i++) printf("%c",a[i]); 
      printf(" + ");
	  for(j=0;j<lenb;j++) printf("%c",b[j]);
	  printf(" = ");
	  for(j=k-1;j>=0;j--) printf("%d",c[j]);
	  printf("\n");
	  if(t!=0) printf("\n");
        }
	  return 0;
}

