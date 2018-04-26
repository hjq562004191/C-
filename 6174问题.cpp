#include <stdio.h>
int main(){
	int n,x,y,z=0;
	int p,a[5];
	int i,j,t;
	scanf("%d",&n);
	while(n--){
		int count=0;
	scanf("%d",&p);	
	while(z!=p){
	z=p;
	a[0]=p/1000;
	a[1]=(p/100)%10;
	a[2]=(p/10)%10;
	a[3]=p%10;
	for(i=0;i<3;i++)
		for(j=i+1;j<4;j++){
			if(a[i]>a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;	
			}	
		}
			x=a[3]*1000+a[2]*100+a[1]*10+a[0];
			y=a[0]*1000+a[1]*100+a[2]*10+a[3];
			p=x-y;
			count++;
	}
	printf("%d\n",count);
}
}
