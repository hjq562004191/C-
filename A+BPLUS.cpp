#include <stdio.h>
int fun(int t){
	int x=0;
	while(t){
		x=x*10+t%10;
		t=t/10;
	}
	return x;
}
int main(){
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
		break;
		printf("%d\n",fun(a)+fun(b));
	}
}
