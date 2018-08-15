#include<iostream>
#include<cstdio>
#include <math.h>
using namespace std;
int a[100001],b[100001];
int main()
{
	int n,m,T,u,v,w,mm;
	int sum;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		mm=0;
		scanf("%d%d",&n,&m);
//		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		for(int i=0;i<m;i++)
		{
		    scanf("%d",&u);
//			cin>>u;
			if(u==1)
			{
			    scanf("%d%d",&v,&w);
//				cin>>v>>w;
				a[v-1]=w;
				//for(int i=0;i<n;i++)(i==n)?cout<<a[i]<<endl:cout<<a[i]<<" ";
			}
			else if(u==2)
			{
			    scanf("%d%d",&v,&w);
//				cin>>v>>w;
				b[v-1]=w;
			}
			else
			{
			    scanf("%d",&v);
//				cin>>v;
				for(int i=1;;i++)
				{
					for(int j=0;j<n;j++)
					sum+=floor((double(i)-double(b[j]))/double(a[j]));
					if(v<=sum)
					{
					    printf("%d\n",i);
//						cout<<i<<endl;
						sum=0;
						break;
					}
					else
					{
						sum=0;
					}
				}
			}
		}
	}

}
