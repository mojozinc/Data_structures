#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#define MIN 0
#define MAX 1
#define ASC 1
#define DESC 2
#define US 3
int RANGE;
int SIZE;
int printArr(int v[],int l,int r){
    int i;
    for(i=l;i<=r;i++)
       printf("%d ",v[i]);
    printf("\n");
}
void swap(int *v,int x,int y){
    int t=v[x];
        v[x]=v[y];
        v[y]=t;
}
void selection_sort(int,int,int *);
void quickSort(int *v,int left,int right,int order){
     if(order==US)
        return;
     if(left>=right)
        return;
     int i,split;
     split=left+(rand()%(right-left));
     swap(v,left,split);
     for(i=left+1,split=left;i<=right;i++)
         switch(order){
             case ASC:if(v[i]<v[left]){
                          swap(v,i,++split);
                         }
                       break;
             case DESC:if(v[i]>v[left]){
                          swap(v,i,++split);
                         }
                       break;
          }
     swap(v,left,split);
     quickSort(v,left,split-1,order);
     quickSort(v,split+1,right,order);
}
int getN(char *s){
    int n=0;
    while(*s>='0'&&*s<='9')
        n=(n<<3)+(n<<1)+*(s++)-'0';
    return n;
}
int *getListOfInts(int n){
    char c;
    int j,i,x,*ints;
    ints=(int *) malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        ints[i]=rand()%RANGE;
    return ints;
}

int main(int argc,char **argv){
    RANGE=10000;
    if(argc==4)
         RANGE=getN(argv[3]);
    int  *num,size,n,i,j,order=ASC;
    char **vector=argv+2;
   
    size=getN(argv[2]);
    num=getListOfInts(size);
    SIZE=size;    
    switch(argv[1][0]){
        case 'a':
                 order=ASC;break;        
        case 'd':
                 order=DESC;break;
        case 'u':
                 order=US;
        }
        printf("%c\n",argv[1][0]-'a'+'A');
        printf("%d\n",size);
       if(order!=US)
                quickSort(num,0,size-1,order);
        //	selection_sort(order,size,num);
        for(j=0;j<size;j++)
            printf("%d\n",num[j]);
	return 0;

}

