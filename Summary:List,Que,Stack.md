### 讨论2.1 链式存储中FindKth函数的另一种实现？ 
如果将链式存储中FindKth的函数实现（如下）做个修改：把函数最后的if语句判断条件改为判断p是否为NULL，即：
```C
if (p==NULL) return NULL;
else return p;
```

或者说直接简化为：return p;
对于这样的修改，程序还正确吗？为什么？
```c
List FindKth( int K, List PtrL )
{     List  p = PtrL;
       int  i = 1;
       while (p !=NULL && i < K ){
              p = p->Next;
              i++;  
       }
       if(i == K) return p;    /*找到第K个，返回指针*/
       else  return NULL;    /* 否则返回空 */
}
```
solution：wrong ,when K<0,the function will return PtrL. the right return value is NULL 
### 讨论2.2 堆栈顺序存储的另一种实现？老师参与
有人给出了堆栈用数组实现的另一种方式，即直接在函数参数中传递数组和top变量（而不是两者组成的结构指针），其中Push操作函数设计如下。这个Push函数正确吗？为什么？
```c
#define MaxSize 100
ElementType S[MaxSize];
int top;
void Push(ElementType *S, int top, ElementType item)
{   if (top==MaxSize-1) {
          printf(“堆栈满”);  return;
    }else {
          S[++top] = item;
         return;
    }
}
```
solution:wrong since the head of stack doesn‘t change
