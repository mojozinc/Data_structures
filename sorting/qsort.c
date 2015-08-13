#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int I;
void swap(int *v,int i,int j){
    int tmp=v[i];
    v[i]=v[j];
    v[j]=tmp;
    }
void quickSort(int *v,int left,int right){
    int i,j,split,c=left;
    if(left>=right)
         return;

   // srand(rand());
    split=left+(rand()%(right-left));
    swap(v,split,right);
    for(i=left;i<=right-1;i++)
        if(v[i]<v[right])
             swap(v,i,c++);
     swap(v,c,right);
     split=c;
 //    printf("\n%d--split--%d\n",++I,split);
     quickSort(v,left,split-1);
     quickSort(v,split+1,right);

    }
void print_array(int v[],int n){
    int i;
    printf("\n-----------------------------------\n");
    for(i=0;i<n;i++)
       printf("%d ",v[i]);
    printf("\n-----------------------------------\n");

}

int main(){
    printf("QuickSort  | ");
    struct timeval start,stop;
    int n,elem;
    char order_of_inp;
    scanf("%c",&order_of_inp);
    scanf("%d",&n);
    int *arr=(int *) malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++){
       scanf("%d",arr+i);
      } 
    gettimeofday(&start,NULL);
    
    quickSort(arr,0,n-1);     

    gettimeofday(&stop,NULL);
    switch(order_of_inp){
        case 'A':    
              printf("Ascending  | %-6d |",n);break;
        case 'D':
              printf("Descending | %-6d |",n);break;
        case 'U':
              printf("Unsorted   | %-6d |",n);
        }
   printf("%-10lums\n",(stop.tv_sec*1000000-start.tv_sec*1000000+stop.tv_usec-start.tv_usec));
  // print_array(arr,n);

}
