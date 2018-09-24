#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int p;
	int n;
	struct node *next;
	struct node *pre;
};
typedef struct node * Node;

Node creat(){
	Node phead,pnew,pend;
	phead = (Node)malloc(sizeof(struct node));
	pend = phead;
	phead->pre = NULL;
	phead->next = NULL;
	int p,n;
	printf("请输入项数和幂次:\n");
	scanf("%d",&p);
	while(p!=0){
		pnew = (Node)malloc(sizeof(struct node));
		pnew->p = p;
		scanf("%d",&pnew->n);
		pnew->pre = pend;
		pend->next = pnew;
		pnew->next = NULL;
		pend = pnew;
		scanf("%d",&p);
	}
	return phead;
}

void print(Node phead);
Node hebing(Node phead){
	Node temp = phead->next;
	Node t;
	while(temp->next != NULL){
		 t =  temp->next;
		while(t!=NULL){
			if(t->n == temp->n){
				temp->p += t->p;
				t->n = 0;
				t->p = 0;
				t = t->next;
			}
			else
			t = t->next;
		}
		if(temp->next!=NULL)
		temp = temp->next;
	}
	return phead;
}

void print(Node phead){
	Node temp;
	temp = phead->next;
	while(temp!=NULL){
		if(temp->n == 0 && temp->p!=0){
			if(temp == phead->next)
			printf("%d",temp->p);
			else if(temp->p >0)
			printf("+%d",temp->p);
			else
			printf("%d",temp->p);
		}
		else if(temp->p>0&&temp == phead->next){
			if(temp->p == 1)
			printf("x");
			else
			printf("%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}
		else if(temp->p>0&&temp != phead->next){
			if(temp->p == 1)
			printf("+x");
			else
			printf("+%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}else if(temp->p < 0){
			if(temp->p == -1)
			printf("-x");
			else
			printf("%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}else if(temp->p == 0&&temp == phead->next)
		printf("0");
		temp= temp->next;
	}
}
void print_dao(Node phead){
	Node temp = phead->next;
	while(temp!=NULL){
		if(temp->n == 0){
			if(temp == phead->next &&temp->next == NULL)
			printf("0");
			if(temp == phead->next &&temp->next !=NULL)
			{
			}
		}
		else if(temp->p>0&&temp == phead->next){
			if(temp->p == 1)
			printf("x");
			else
			printf("%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}
		else if(temp->p>0&&temp != phead->next){
			if(temp->p == 1)
			printf("+x");
			else
			printf("+%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}else if(temp->p < 0){
			if(temp->p == -1)
			printf("-x");
			else
			printf("%dx",temp->p);
			if(temp->n != 1)
			printf("^%d",temp->n);
		}
		temp= temp->next;
	}
}

void SUM(Node phead,int x){
	int sum = 0;
	Node temp = phead->next;
	while(temp){
		sum += temp->p * pow(x,temp->n);
		temp = temp->next;
	}
	printf("%d",sum);
}

void sum(){
	Node phead = creat();
	printf("请输入x并求值:x=");
	int x;
	scanf("%d",&x);
	printf("F(%d)=",x);
	phead = hebing(phead);
	print(phead);
	printf("\n    =");
	SUM(phead,x);
}

void cheng(Node phead1,Node phead2){
	Node temp1 = phead1->next;
	Node temp2 = phead2->next;
	while(temp1){
		while(temp2){
		temp1->p *=temp2->p;
		temp1->n +=temp2->n;
		temp2 = temp2->next; 
		}
		temp1 = temp1->next;
		temp2 = phead2->next;
	}
}

void xiangcheng(){
	printf("请输入F1(x)的各项值:\n");
	Node phead1 = creat();
	printf("请输入F2(x)的各项值:\n");
	Node phead2 = creat();
	printf("F1(x)=");
	print(phead1);
	printf("\n");
	printf("F2(x)=");
	print(phead2);
	printf("\n");
	cheng(phead1,phead2);
	printf(" F(x)=");
	print(phead1);
	printf("\n");
}

void DAO(Node phead){
	Node temp = phead->next;
	while(temp){
		temp->p *=temp->n;
		if(temp->n != 0)
		temp->n--;
		temp = temp->next;
	}
	print_dao(phead);
}

void dao(){
	Node phead = creat();
	printf(" F(x)=");
	print(phead);
	printf("\nF'(x)=");
	DAO(phead);
}

void jia(Node phead1,Node phead2){
	Node ta = phead1->next;
	while(ta->next!=NULL){
		ta= ta->next;
	}
	
	if(phead2->next!=NULL){
	ta->next = phead2->next;
	phead2->next->pre = ta;
	}
	phead1 = hebing(phead1);
	print(phead1);
}

void jian(Node phead1,Node phead2){
	Node t = phead2->next;
	while(t!=NULL){
		t->p *=-1;
		t= t->next;
	}
	jia(phead1,phead2);
}

void jiajian(){
	printf("请输入F1(x)的各项值:\n");
	Node phead1 = creat();
	printf("请输入F2(x)的各项值:\n");
	Node phead2 = creat();
	
	printf("--------------1.多项式相  加-------------\n");
	printf("--------------2.多项式相  减-------------\n");
	int chance;
	scanf("%d",&chance);
	printf("\nF(x)=");
	if(chance == 1)
		jia(phead1,phead2);
	if(chance == 2){
		jian(phead1,phead2);
	} 
}

int main(){
	printf("--------------1.多项式求  值-------------\n");
	printf("--------------2.多项式加  减-------------\n");
	printf("--------------3.多项式相  乘-------------\n");
	printf("--------------4.多项式求  导-------------\n");
	int chance;
	scanf("%d",&chance);
	switch(chance){
		case 1:
			sum();
		break;
		case 2:
			jiajian();
		break;
		case 3:
			xiangcheng();
		break;
		case 4:
			dao();
		break;
		default :break; 
	} 
	
}
