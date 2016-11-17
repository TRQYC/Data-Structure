
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
