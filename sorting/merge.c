#include<stdio.h>
#include<stdlib.h>
int *A;
int N;
void printArr(int *a,int n){
    int i;
    printf("\n---------------------------------------\n");
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
    printf("\n---------------------------------------\n");
}
void merge(int *left,int *right,int l,int r){
     int i,j,k,small,big;
     small=l<r?l:r;
     big=l>r?l:r;
     int *merged=(int *)malloc(sizeof(int)*(l+r));
     for(i=0,j=0,k=0;i<small&&j<big;k++)
         if(left[i]<right[j])
             merged[k]=left[i++];
         else
             merged[k]=right[j++];   
      if(i==small||j==big)
         if(i==small)
            for(;j<big;j++,k++)
               merged[k]=right[j];
         else
            for(;i<small;i++,k++)
               merged[k]=left[i];
   for(i=0;i<l+r;i++)
       left[i]=merged[i];         
}
void merge_sort(int *a,int n){
     if(n==1)
        return;
     int *left,*right,l,r;
     left=a;
     l=n/2;
     right=a+l; 
     r=n-l;
     merge_sort(left,l);
     merge_sort(right,r);
     merge(left,right,l,r);
   
}
int main(){
    printf("MergeSort  | ");
   
    struct timeval start,stop,afterScan;
    int n,elem,*arr;
    char order_of_inp;
   
    scanf("%c",&order_of_inp);
    scanf("%d",&n);
    arr=(int *) malloc(sizeof(int)*n);
    A=arr;
    N=n;
    int i;
    gettimeofday(&start,NULL);
    for(i=0;i<n;i++){
       scanf("%d",arr+i);
       }
    gettimeofday(&afterScan,NULL);
    merge_sort(arr,n);
    gettimeofday(&stop,NULL);
    switch(order_of_inp){
        case 'A':
              printf("Ascending  | %-6d |",n);break;
        case 'D':
              printf("Descending | %-6d |",n);break;
        case 'U':
              printf("Unsorted   | %-6d |",n);
        }

    printf("%-10lums\n",(stop.tv_sec*1000000-afterScan.tv_sec*1000000+stop.tv_usec-afterScan.tv_usec));
 //   printArr(arr,n);
    return 0;
}
