#include <stdio.h>
#include <stdlib.h> 
struct node{
	int data;
	struct node *next;
};

typedef struct node *Node;

Node creat(){
	Node phead,pnew,pend;
	phead = (Node )malloc(sizeof(struct node));
	pend = phead;
	int k;
	scanf("%d",&k);
	while(k != 0){
		pnew = (Node )malloc(sizeof(struct node));
		pnew->data = k;
		pnew->next = NULL;
		pend->next = pnew;
		pend=pnew;
		scanf("%d",&k);
	}
	return phead;
}

//Node fun(Node a,Node b){
//	Node tempa = a->next;
//	Node tempb = b->next;
//	Node ta = tempa->next,tb = tempb->next;	
//	while(ta->next!=NULL){
//		tempa->next = tempb;
//		tempb->next = ta;
//		tempa = ta;
//		tempb = tb;
//		ta = ta->next;
//		tb = tb->next;
//	}
//	printf("1");
//	if(tb!=NULL){
//		printf("1");
//		Node k = a;
//		while(k->next!=NULL)
//		k = k->next;
//		k->next = tb;
//	}
//	return a;
//}

void print(Node phead){
	Node temp;
	temp = phead->next;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	} 
	printf("\n");
}

Node fun(Node a,Node b,int m,int n){
	Node c,pnew,pend;
		pend = c = (Node )malloc(sizeof(struct node));
	Node tempa = a->next;
	Node tempb = b->next;
	for(int k = 0;k<n;k++){
		if(tempa!=NULL){
	
		pnew = (Node )malloc(sizeof(struct node));
		pnew->data = tempa->data;
		pend->next = pnew;
		pnew->next = NULL;
		pend = pnew;
		tempa= tempa->next;
	}
	if(tempb!=NULL){
		pnew = (Node )malloc(sizeof(struct node));
		pnew->data = tempb->data;
		pend->next = pnew;
		pnew->next = NULL;
		pend = pnew;
		tempb= tempb->next;}
	
}
return c;
}

int main(){
	int m=0,n=0;
	printf("请输入a的数据，按0结束:");
	Node a = creat();
	printf("请输入b的数据，按0结束:");
	Node b = creat();
	Node temp1 = a->next;
	Node temp2 = b->next;
	while(temp1!=NULL)
	{
		m++;
		temp1 = temp1->next;
	}
	while(temp2!=NULL)
	{
		n++;
		temp2 = temp2->next;
	}
	Node sum;
	if(m<=n)
	sum = fun(a,b,m,n);
	else
	sum = fun(b,a,n,m);
	printf("\n");
	printf("整合后的链表为:") ;
	print(sum);
} 
