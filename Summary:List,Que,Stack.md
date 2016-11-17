# 讨论2.1 链式存储中FindKth函数的另一种实现？ 
如果将链式存储中FindKth的函数实现（如下）做个修改：把函数最后的if语句判断条件改为判断p是否为NULL，即：
```C
if (p==NULL) return NULL;
else return p;
```

或者说直接简化为：return p;
对于这样的修改，程序还正确吗？为什么？
```
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

