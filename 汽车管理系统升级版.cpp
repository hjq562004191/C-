#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h> 
#include <windows.h>
/*
��������ϵͳ
1.��������ĵ�¼
2.������Ϣ¼��
3.������Ϣ����
4.������Ϣɾ�� 
5.������Ϣ��ѯ
6.������Ϣ�޸� 
7.������������
8.�����ۼ����� 

*/



typedef struct sever{//����Ա 
	char sever_name[50];
	char sever_pass[50];
}seve;

typedef struct car_data{
	char name[50];//����Ʒ�� 
	int number;//�������� 
	double pailiang;//�������� 
	int zdd;//�Ƿ��Զ��� 
	double in_money;//���۸� 
	double out_money;//���۸� 
}DATA;

typedef struct car{
	DATA data;
	struct car *next;//ָ����һ���ڵ��ָ�� 
}*node;

node lianbiao = (node)malloc(sizeof(struct car));
node last;

int save_wt(node phead);//���� 

int q = 0;//��¼������¼���� 

int input(){// ¼����Ϣ 
	node pnew,temp = lianbiao;
	int i,k;
	printf("\n\n\t\t������¼����������:");
	scanf("%d",&k);
	for(i = 1;i <= k;i++)
	{
		pnew = (node)malloc(sizeof(struct car));//�����½ڵ�
		printf("�������%d������:\n",i);
		printf("����Ʒ��:");
		scanf("%s",pnew->data.name);
		printf("��������:");
		scanf("%d",&pnew->data.number);
		printf("��������:");
		scanf("%lf",&pnew->data.pailiang);
		printf("�����Ƿ��Զ���(1-��/0-��):");
		scanf("%d",&pnew->data.zdd);
		printf("���������۸�:");
		scanf("%lf",&pnew->data.in_money);
		printf("���������۸�:");
		scanf("%lf",&pnew->data.out_money);
		pnew->next = NULL;
		last->next = pnew;
		last = pnew; 
	}
	save_wt(lianbiao); 
}

int print(node phead)//��ӡ���� 
{
	node temp = NULL;
	temp = phead->next;	
	if(q == 0)
	printf("\n\t\t\t\t============== ���޴˳����ݣ�===============");
	else{ 
	printf("\n\n--------------------------------------------------------------------");
	printf("------------------------------------------------\n");
	printf("|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|%-19s|\n","����Ʒ��","��������","��������",
	"�Ƿ��Զ���","��������","�����ۼ�","����");
	while(temp != NULL){ 
	printf("--------------------------------------------------------------------");
	printf("------------------------------------------------\n");
	printf("|%-15s",temp->data.name);
	printf("|%-15d",temp->data.number);
	printf("|%-15.2lf",temp->data.pailiang);
	if(temp->data.zdd == 1)
	printf("|%-15s","�Զ���");
	else
	printf("|%-15s","�ֶ���");
	printf("|%-15.2lf",temp->data.in_money);
	printf("|%-15.2lf",temp->data.out_money);
	printf("|%-15.2lf��Ԫ|\n",(temp->data.out_money - temp->data.in_money)*temp->data.number); 
	temp=temp->next;
	}
	printf("--------------------------------------------------------------------");
	printf("------------------------------------------------\n");
	} 
	system("pause");
	system("cls");
}

int welcome(){
	printf("\n\n\n");
	printf("  \t\t\t              -------------------------------                   \n");
	printf("  \t\t\t              |   ��ӭʹ�ñ���������ϵͳ    |                   \n");
	printf("  \t\t\t              -------------------------------                   \n");

	Sleep(1000);
	system("cls"); 
} 

int menu_1()
{
	char choice[100];
	while(strcmp(choice,"1") != 0 && strcmp(choice,"2") != 0&& strcmp(choice,"0") != 0){ 
	system("cls"); 
	printf("\n\n");
	printf(" \t\t\t               -------------------------------                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     1.����Ա��¼            |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     2.����Աע��            |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     0.�˳�                  |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               -------------------------------                    \n");
	printf(" \t\t\t                                                                  \n");
	scanf("%s",choice); 
	}
	int k;
	if(strcmp(choice,"1")==0)
		k = 1;
	else if(strcmp(choice,"2")==0)
		k = 2;
	else if(strcmp(choice,"0")==0)
		k = 0;
		return k;
}

int sever_zhuce()
{
	char sever_name[50];
	char password[20],pass[20];
	printf("\n\n\t\t\t���������Ա�˺�:");
	scanf("%s",sever_name);
	while(1){ 
	printf("\n\t\t\t����������:");
	scanf("%s",password);
	printf("\n\t\t\t�ٴ���������:");
	scanf("%s",pass);
	if(strcmp(password,pass) == 0)
	break;
	else{ 
	system("cls"); 
	printf("\n\n\n\t\t\t�����������벻ͬ�����ٴ����룡\n");
	} 
	} 
	FILE *fp;
	fp = fopen("d:\\sever1.txt","at+");
	fprintf(fp,"%s %s\n",sever_name,password);
	fclose(fp);
}
char severnum2[50];
int sever_showpass(){//����Ա��½ 
	char pass[50];
	char c;
	int i = 0,f = 0;
	seve severnum1;
	FILE *fp;
	fp = fopen("d://sever1.txt","rt");
	while(fscanf(fp,"%s%s",severnum1.sever_name,severnum1.sever_pass) == 2){ 
	if(strcmp(severnum2,severnum1.sever_name) == 0)
	{
	f = 1; 
	break;
	}
	}
	if(f == 0){ 
	printf("\n\n\t\t\t\t�޴��˺ţ�\n");
	}
	else{
	do{
		i = 0;
		system("cls");
		printf("\n\n\n\n\n\t\t\t�˺�:%s\n",severnum1.sever_name);
			printf("\n\n");
		printf("\t\t\t����: ");
		while((c = getch())!= '\r')
		{
			if(i<50&&isprint(c)){
			pass[i] = c;
			putchar('*');
		    i++;
			}
			else if(i>0&&c == '\b'){
				i--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
		} 
		pass[i] = '\0';
		printf("\n");
	}while(strcmp(severnum1.sever_pass,pass));
	system("cls");
	}
}

int save_wt(node phead){
	node temp;
	temp = phead->next;
	FILE *fp;
	fp = fopen("d:\\car.txt","wt+");
	while(temp!=NULL){
		fprintf(fp,"%s %d %lf %d %lf %lf\n",temp->data.name,temp->data.number,
		temp->data.pailiang,temp->data.zdd,temp->data.in_money,temp->data.out_money);
		temp = temp->next;
	}
	fclose(fp);
	//printf("\n�ļ�������d:\\car.txtĿ¼��\n");
} 

int read(){
	FILE *fp;
	int  count = 0;
	fp = fopen("d:\\car.txt","rt+");
	if(fp == NULL)
	{
		printf("�޳�����Ϣ��\n");
	}
	else{
	node pend,pnew;
	lianbiao->next = NULL;
	pend = lianbiao;
	DATA temp;
	while(fscanf(fp,"%s %d %lf %d %lf %lf",temp.name,&temp.number,
		&temp.pailiang,&temp.zdd,&temp.in_money,&temp.out_money) == 6)
	{
		pnew = (node)malloc(sizeof(struct car));
		pnew->data = temp;
		pnew->next = NULL;
		pend->next = pnew;
		pend = pnew;
		count++;
	}
	last = pend;
	}
	q = count;
}

int insert(node phead){//�������� 
	node temp = phead->next;
	node pnew,t = phead;
	int k,i;
	if(temp == NULL)
	{
		printf("�޳�����Ϣ!\n");
	}
	else
	{
		printf("������Ҫ���뵽�ڼ���:");
		scanf("%d",&k);
		pnew = (node)malloc(sizeof(struct car));
		printf("����Ʒ��:");
		scanf("%s",pnew->data.name);
		printf("��������:");
		scanf("%d",&pnew->data.number);
		printf("��������:");
		scanf("%lf",&pnew->data.pailiang);
		printf("�����Ƿ��Զ���(1-��/0-��):");
		scanf("%d",&pnew->data.zdd);
		printf("���������۸�:");
		scanf("%lf",&pnew->data.in_money);
		printf("���������۸�:");
		scanf("%lf",&pnew->data.out_money);
		if(k == 1)
		{
			pnew->next = phead->next;
			phead->next = pnew;
		}
		else{ 
		for(i = 1;i < k;i++){
			t = t->next;
			temp = temp->next;
		}
		pnew->next = t->next;
		t->next = pnew;
		} 
	}
	save_wt(phead);
}

int delet(){
	int j;
	int k;
	printf("Ҫɾ���ڼ�����");
	scanf("%d",&k);
	if(k > q||k < 1)
	printf("�޴˳�����Ϣ!");
	else{ 
	node temp = lianbiao->next;
	node t = lianbiao;
	for(j = 1;j < k;j++){
		t = t->next;
		temp = temp->next;
	}
	t->next = temp->next;
	free(temp);
	save_wt(lianbiao);
	} 
} 

int find(){
	char name[50];
	printf("������Ҫ���ҵ�����Ʒ��:");
	scanf("%s",name);
	node temp = lianbiao->next;
	int f = 0;
	while(temp!=NULL){
		if(strcmp(temp->data.name,name) == 0)
		{
			f = 1;
			break;
		}
		temp = temp->next;
	}
	if(f == 1)
	{
	printf("\n\n------------------------------------------------");
	printf("------------------------------------------------\n");
	printf("|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|\n","����Ʒ��","��������","��������",
	"�Ƿ��Զ���","��������","�����ۼ�"); 
	printf("------------------------------------------------");
	printf("------------------------------------------------\n");
	printf("|%-15s",temp->data.name);
	printf("|%-15d",temp->data.number);
	printf("|%-15.2lf",temp->data.pailiang);
	if(temp->data.zdd == 1)
	printf("|%-15s","�Զ���");
	else
	printf("|%-15s","�ֶ���");
	printf("|%-15.2lf",temp->data.in_money);
	printf("|%-15.2lf|\n",temp->data.out_money);
	printf("------------------------------------------------");
	printf("------------------------------------------------\n");
	getchar();
	printf("�Ƿ��޸����ݣ�(y/n)");
	char t;
	scanf("%c",&t);
	if(t == 'y'||t == 'Y')
	{
		printf("����Ʒ��:");
		scanf("%s",temp->data.name);
		printf("��������:");
		scanf("%d",&temp->data.number);
		printf("��������:");
		scanf("%lf",&temp->data.pailiang);
		printf("�����Ƿ��Զ���(1-��/0-��):");
		scanf("%d",&temp->data.zdd);
		printf("���������۸�:");
		scanf("%lf",&temp->data.in_money);
		printf("���������۸�:");
		scanf("%lf",&temp->data.out_money);
	}
	save_wt(lianbiao);
	}
	else
	printf("\n\t\t\t\t============== ���޴˳����ݣ�===============");
}


int sort(){
	DATA t;
	node temp1 = lianbiao;
	node temp2;
	int i,j;
	for(i = 0;i < q-1;i++)
	{
		temp1 = temp1->next;
		for(j = i+1;j < q;j++)
		{
			temp2 = temp1->next;
			if(temp1->data.out_money > temp2->data.out_money)
			{
				t = temp1->data;
				temp1->data = temp2->data;
				temp2->data = t;
			}
		}
	}
	print(lianbiao);
	save_wt(lianbiao);
}

int main1();
int menu_1_1(){
	int flag;
	printf("\n\n");
	printf(" \t\t\t               -------------------------------                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     1.������Ϣ¼��          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     2.�鿴��¼��Ϣ          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     3.����������Ϣ          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     4.ɾ��������Ϣ          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     5.����������Ϣ          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     6.�����ۼ�����          |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               |     0.�˳�                  |                    \n");
	printf(" \t\t\t               |                             |                    \n");
	printf(" \t\t\t               -------------------------------                    \n");
	printf(" \t\t\t                                                                  \n");
	char flag1[1000];
	scanf("%s", flag1);

		if (strcmp(flag1, "1") == 0) flag = 1;

		else if (strcmp(flag1, "2") == 0) flag = 2;

		else if (strcmp(flag1, "3") == 0) flag = 3;

		else if (strcmp(flag1, "4") == 0) flag = 4;

		else if (strcmp(flag1, "5") == 0) flag = 5;
		
		else if (strcmp(flag1, "6") == 0) flag = 6;

		else if (strcmp(flag1, "0") == 0) flag = 0;
		
		else main1();
 
	return flag;
}

int main1(){
	int choice = 1;
	read();
	while(choice){
		choice = menu_1_1();
		switch(choice)
		{
			case 1:
				system("cls");
				input(); 
				break;
			case 2:
			    system("cls");
			    print(lianbiao);
				break;
			case 3:
			    system("cls");
			    insert(lianbiao);
				break;
			case 4:
				system("cls");
			    print(lianbiao);
				delet();
				break;
			case 5:
				system("cls");
				find(); 
				break;
			case 6:
				system("cls");	
				sort();
				break;
			case 0:
			    break; 
		}
}
}

int main()
	{
	welcome(); //��ӭ���� 

	int choice = 1;
	while(choice){
		choice = menu_1();
		switch(choice)
		{
			case 1:
				printf("\n\n\t\t\t���������Ա�˺�:");
				scanf("%s",severnum2);
				sever_showpass();//����Ա��½
				main1(); 
				break;
			case 2:
				sever_zhuce();//severע��
				break;
			case 0:
				break;
		}
	}	
}

