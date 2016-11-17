
///List implemented by arrays
typedef int Position;
typedef struct Lnode *List;
structure Lnode{
	Elementype Data[MAXSIZE];
	Position Last;
}
List MakeEmpty(){
	List L;
	L=(List)malloc(sizeof(structure Lnode));
	L->Last=-1;
	return L;
}
Position Find(List L,Elementtype X){
	Position i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
	if(i>L->Last) return error;
	else return i;
}

bool Insert(List L,Elementtype X,position P){
if(p<0||P>L->Last+1){
	printf("不合法")；
	return false;
}
if(L->Last==L->MAXSIZE-1){
	printf("表满")；
	return false;
}
for(i=L->last;i>=P;i--){
	L->Data[i+1]=L->Data[i];
}
L->Data[P]=X;
L->Last++;
return true;
}

List implemented by arrays
typedef int Position;
typedef struct Lnode *List;
structure Lnode{
	Elementype Data[MAXSIZE];
	Position Last;
}
List MakeEmpty(){
	List L;
	L=(List)malloc(sizeof(structure Lnode));
	L->Last=-1;
	return L;
}
Position Find(List L,Elementtype X){
	Position i=0;
	while(i<=L->Last&&L->Data[i]!=X)
		i++;
	if(i>L->Last) return error;
	else return i;
}

bool Insert(List L,Elementtype X,position P){
if(p<0||P>L->Last+1){
	printf("不合法")；
	return false;
}
if(L->Last==L->MAXSIZE-1){
	printf("表满")；
	return false;
}
for(i=L->last;i>=P;i--){
	L->Data[i+1]=L->Data[i];
}
L->Data[P]=X;
L->Last++;
return true;
}
//list implemented by links
typedef struct Lnode *List;
struct Lnode{
	Elementtype Data;
	List Next;
}
struct Lnode L;
List PtrL;
}
int Length(List PtrL){
	List p=Ptrl;
	int i;
	for( i=0;P!=NULL;i++);
	return p;
}
List FindKth(int K,List PtrL){
	List p=PtrL;
	int i;
	for(i=1;i<K&&p!=NULL;{i++;p=p->next;)
	if(i==k) return p;
	elae rertun NULL;
}

List FindKth(Elemtype X,List PtrL){
	List p=PtrL;
	while(p&&p->Data!=X)
		p=p->next;
		return p;
}
List Insert(Elementtype X,int i,List PtrL){
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct Lnode);
		s->Data=X;
		s->Next=PtrL;
		return s;
	}
	p=FindKth(i-1,PtrL);
	if(p==NULL)
		return NULL;
	else{
		s=(List)malloc(sizeof(struct Lnode);
		s->Data=X;
		s->Next=p->Next;
		p->Next=s;
		return ptrL;
	}
}
List Delete(int i,List PtrL){
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct Lnode));
		s=PtrL;
		if(ptrL!=NULL) PtrL=s->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);
	s=p->next;
	p->next=s->next;
	free(S);
	retrun PtrL;
}
//Stack implemented by links
typedef struct Snode *Stack;
struct Snode{
	Elementtype Data;
	Stack Next;
}
Stack CreateStack(){
	Stack S;
	S=(Stack)malloc(sizeof(struct Snode));
	S->Next==NULL;
	return S;
}
int IsEmpty(Stack S){
	return (S->next==NULL);
}
void push(Stack S,Elementtype X){
	struct Snode *p;
	p->Data=X;
	p->Next=S->next;
	s->next=p;
}
Elementtype pop(Stack S,Elementtype X){
	struct Snode *p;
	if(isempty(S)) {
		printf("空")；
		return;
	}
	p=S->next;
	S->next=p->next;
	retrun p->Data;
}


