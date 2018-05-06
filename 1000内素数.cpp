#include <stdio.h>
#include <math.h>
int main(){ 
	int m,i,f;
	for(m=2;m<=1000;m++){
		f=1;
		for(i=2;i<m;i++)
		if(m%i==0){
			f=0;
			break;
		}
		if(f==1)
		printf("%d ",m);
	} 
}
