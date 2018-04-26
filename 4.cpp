#include <stdio.h>
int main(){
	int a[4],b[4],i;
	int m=1,n=1,t,m1,n1;
	do{
		t=0; 
		scanf("%d%d",&m,&n);
		m1=m;n1=n;
		for(i=0;i<3;i++){ 
		a[i]=m1%10;
		m1=m1/10;
		}
		for(i=0;i<3;i++){ 
		b[i]=n1%10;
		n1=n1/10;
		} 
		for(i=0;i<3;i++)
		if(a[i]+b[i]>=10)
		{
		a[i+1]++;
		t++;
		} 
		if(m==0&&n==0)
		break;
		else
		printf("%d\n",t);
	}while(m||n);
}
