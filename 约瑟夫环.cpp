#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

struct node{
	int data;
	int pwd;
	struct node *next;
	struct node *pre;
};
typedef struct node *Node;

int size = 1;

Node zidong_creat(){
	Node phead,pnew,pend;
	phead = (Node)malloc(sizeof(struct node));
	printf("请输入人数:");
	int count;
	scanf("%d",&count); 
	phead->next = NULL;
	phead->pre = NULL;
	pend = phead;
	for(int i = 0;i< count;i++){
		pnew = (Node)malloc(sizeof(struct node));
		pnew->pwd = rand()%19 + 1;
		pnew->data = size++;
		pend->next = pnew;
		if(pend != phead)
		pnew->pre = pend;
		pend = pnew;
		pnew->next = NULL;
	} 
	size = count;
	pnew->next = phead->next;
    phead->next->pre = pnew;
	return phead;
}

Node shoudong_creat(){
	Node phead,pnew,pend;
	int m;
	phead = (Node)malloc(sizeof(struct node));
	printf("请输入第%d个人的密码(-1退出):",size);
	phead->next = NULL;
	phead->pre = NULL;
	pend = phead;
	int k;
	scanf("%d",&k);
	while(k!=-1){
		pnew = (Node)malloc(sizeof(struct node));
		pnew->pwd = k;
		pnew->data = size;
		pend->next = pnew;
		if(pend != phead)
		pnew->pre = pend;
		pend = pnew;
		pnew->next = NULL;
		size++;
		printf("请输入第%d个人的密码(-1退出):",size);
		scanf("%d",&k);
	} 
	size--;
	pnew->next = phead->next;
    phead->next->pre = pnew;
	return phead;
}

void shun_print(Node phead){
	printf("一共%d个人\n",size);
	Node temp;
	temp = phead->next;
	
	for(int i = 0;i<size;i++){
		printf("第%d个人的密码为%d\n",temp->data,temp->pwd);
		temp=temp->next;
	}
}

void ni_print(Node phead){
	printf("一共%d个人\n",size);
	Node temp;
	temp = phead->next;
	
	for(int i = 0;i<size;i++){
		printf("第%d个人的密码为%d\n",temp->data,temp->pwd);
		temp=temp->pre;
	}
}



void shun_del(Node temp,Node phead);
void ni_del(Node temp,Node phead);
void shun_yuesef(Node phead){
	int p = rand()%size;
	printf("第一个报数的人是%d号\n",p+1);
	int m;
	Node temp = phead->next;
	for(int i = 0;i < p;i++)
	temp = temp->next;
	int k = temp->pwd;
	for(int i = 0;i < size-1;i++){
		m = k;
		for(int j = 1;j < m;j++){
			temp = temp->next;
		}
		printf("%d号出列，密码为%d\n",temp->data,temp->pwd);
		Node t = temp;
		k = temp->pwd;
		temp = temp->next;
		shun_del(t,phead);
	}
	printf("最后一个人为%d号",temp->data);
}

void ni_yuesef(Node phead){
	int p = rand()%size;
	printf("第一个报数的人是%d号\n",p+1);
	int m;
	Node temp = phead->next;
	for(int i = 0;i < p;i++)
	temp = temp->pre;
	for(int i = 0;i < size-1;i++){
		m = temp->pwd;
		for(int j = 1;j < m;j++){
			temp = temp->pre;
		}
		printf("%d号出列，密码为%d\n",temp->data,temp->pwd);
		Node t = temp;
		temp = temp->pre;
		ni_del(t,phead);
	}
	printf("最后一个人为%d号",temp->data);
}

void shun_del(Node temp,Node phead){
	if(temp == phead->next)
	phead->next = temp->next;
	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
	free(temp);
}
void ni_del(Node temp,Node phead){
	if(temp == phead->next)
	phead->next = temp->pre;
	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
	free(temp);
}

void shou(){
	printf("\t\t\t1.顺时针\n");
	printf("\t\t\t2.逆时针\n");
	int f;
	scanf("%d",&f);
	if(f == 1){
	Node phead;
	phead = shoudong_creat();
	shun_print(phead);
	printf("-----------------顺时针-------------------\n");
	shun_yuesef(phead);
	}
	if(f == 2){
		Node phead;
	phead = shoudong_creat();
	ni_print(phead);
	printf("-----------------逆时针-------------------\n");
	ni_yuesef(phead); 
	}
}

void zidong(){
	printf("\t\t\t1.顺时针\n");
	printf("\t\t\t2.逆时针\n");
	int f;
	scanf("%d",&f);
	if(f == 1){
	Node phead;
	phead = zidong_creat();
	shun_print(phead);
	printf("-----------------顺时针-------------------\n");
	shun_yuesef(phead);
	}
	if(f == 2){
		Node phead;
	phead = zidong_creat();
	ni_print(phead);
	printf("-----------------逆时针-------------------\n");
	ni_yuesef(phead); 
	}
}


int main(){
	srand(time(NULL));
	printf("\t\t\t1.手动输入密码\n");
	printf("\t\t\t2.自动输入密码\n");
	printf("请选择:\n");
	int f;
	scanf("%d",&f);
	if(f == 1)
	shou();
	if(f == 2)
	zidong();
	return 0;
}
