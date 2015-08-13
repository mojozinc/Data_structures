#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *st;
    int n;
    int top;
}stack;
void view_stack_state(stack *s){
    printf("TopElem=%d\nSize=%d\nMaxSize=%d\n",s->st[s->top],s->top,s->n);    
    }
void init_stack(stack *s){
    s->st=(int *)malloc(sizeof(int));
    s->n=1;
    s->top=-1;
}
void push(stack *s,void * x){
     if(s->top==s->n-1){
         s->st=realloc(s->st,sizeof(int)*(s->n*2));
         s->n=2*(s->n);
         }
     s->top++;
     s->st[s->top]=*((int*)x);     
}
void pop(stack *s,void *x){
     *(int *)x=s->st[s->top];
     s->top-=1;
     if(s->top==s->n/4){
         s->st=(int *)realloc(s->st,sizeof(int)*(s->n/2));
         s->n=(s->n)/2;
         }

}
int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    init_stack(s);
    int i,x;
    printf("Pushing\n");
    for(i=0;i<17;i++){
       x=rand()%100;
       printf("%d\n",x);
       push(s,(void *)&x);
      }
    printf("Popping\n");
    for(i=0;i<17;i++){
       pop(s,(void *)&x);
       printf("%d\n",x);
      }
}
