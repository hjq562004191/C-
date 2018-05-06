#include <stdio.h>
#include <math.h>
int main(){
	int f1,f2,N,M,t1,t2,A,B,A1,A2,B1,B2,i1,i2;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&M);
if(M==1)
		{A=2;B=1;
		}
else{
	for(i1=M;;i1--){
		f1=1;
		t1=sqrt(i1);
		for(int j=2;j<=t1;j++)
		if(i1%j==0)
		{	f1=0;break;
		}
		if(f1==1){
		B1=M-i1;break;
		}
		}
	for(i2=M;;i2++){
		f2=1;
		t2=sqrt(i2);
		for(int j=2;j<=t2;j++)
		if(i2%j==0&&i2!=1)
		{	f2=0;break;
		}
		if(f2==1){
			B2=i2-M;break;
		}}
		if(B1<=B2){
		A=i1;B=B1;
		}
		else{
		A=i2;B=B2;
		}}
		printf("%d %d\n",A,B);
	}
}

