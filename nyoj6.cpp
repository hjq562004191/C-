#include <stdio.h>
int main(){
	int n,i,j,k,t,max,min,x1,x2;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&i,&j);
		for(k=i;k>=1;k--)
		if(i%k==0&&j%k==0)
		{x1=k;break;}
		x2=i*j/x1; 
		printf("%d %d\n",x1,x2);
	}
} 
