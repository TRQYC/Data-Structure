/*设计函数分别求两个一元多项式的乘积与和。

输入格式:

输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:

输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0*/

#include<stdio.h>
#include<stdlib.h>
struct PolyNode{
	int coef;
	int expon;
	struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;
int Compare(int i,int j){
	if(i>j)
		return 1;
	else if(i==j)
		return 0;
	else return -1;
}
void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->link=NULL;
	(*pRear)->link=P;
	*pRear =P;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2){
	Polynomial front,rear,temp;
	int sum;
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	front =rear;
	while(P1&&P2){
		switch(Compare(P1->expon,P2->expon)){
			case 1:
			 Attach(P1->coef,P1->expon,&rear);
			 P1=P1->link;
			 break;
			 case -1:
			 Attach(P2->coef,P2->expon,&rear);
			 P2=P2->link;
			 break;
			 case 0:
			 sum=P1->coef+P2->coef;
			 if(sum) Attach(sum,P1->expon,&rear);
			 P1=P1->link;
			 P2=P2->link;
			 break;
		}
	}
		for(;P1;P1=P1->link) {
		Attach(P1->coef,P1->expon,&rear);}
		for(;P2;P2=P2->link) Attach(P2->coef,P2->expon,&rear);
		rear->link=NULL;
		temp=front;
		front=front->link;
		free(temp);
		return front;	
}

Polynomial PolyMult(Polynomial P1,Polynomial P2){
	Polynomial front,rear,t1,t2,t;
	int c,e;
	if(!P1||!P2) return NULL;
	rear=(Polynomial)malloc(sizeof(struct PolyNode));
	rear->link=NULL;
	front=rear;	
	t1=P1;
	t2=P2;
	while(t2){
		c=t1->coef*t2->coef;
		Attach(c,t1->expon+t2->expon,&rear);
		t2=t2->link;
	}
	t1=t1->link;
	for(;t1;t1=t1->link){
		rear=front;
		for(t2=P2;t2;t2=t2->link){
		
			c=t1->coef*t2->coef;
			e=t1->expon+t2->expon;
			while(rear->link&&e<rear->link->expon)
				rear=rear->link;
			if(rear->link&&e==rear->link->expon){
				if(c+rear->link->coef)
					rear->link->coef+=c;
				else{
					t=rear->link;
					rear->link=t->link;
					free(t);
				}
			}
			else{
				t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef= c;
				t->expon=e;
				t->link=rear->link;
				rear->link=t;
				rear=t;
			}
		}
	}
	t2=front;
	front=front->link;
	free(t2);
	return front;
}

void PrintPoly(Polynomial P){
	int flag=0;
	if(!P){
		printf("0 0\n");
		return;
	}
	while(P){
		if(!flag)
			flag=1;
		else 
			printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->link;
	}
	printf("\n");
}

Polynomial ReadPoly(){
	Polynomial P,rear,t;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	rear=P;
	int c,e,N;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&c,&e);
		Attach(c,e,&rear);
	}
	t=P;
	P=P->link;
	free(t);
	return P;
}
int main(){
	Polynomial P1,P2,PP,PS;

	P1=ReadPoly();
	P2=ReadPoly();
	PP=PolyMult(P1,P2);
	PS=PolyAdd(P1,P2);

	PrintPoly(PP);
	PrintPoly(PS);
	return 0;
}
	
