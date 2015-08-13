#include<stdio.h>
#include<stdlib.h>
#define ASC 1
#define DESC 2
int *getListOfInts(int n,char **list){
    char c;
    int j,i,x,*ints;
    ints=(int *) malloc(sizeof(int)*n);
   
    for(i=0;i<n;i++){
        x=0;
        j=0;
        c=list[i][j];
        while(c!='\0'){
            x=(x<<3)+(x<<1)+c-'0';
            c=list[i][++j];  
      
         }

        ints[i]=x; 

        }
    
    return ints;
}
void bubble_sort(int,int,int *);

int main(int argc,char **argv){
    int *num,n,i,order=ASC; 
	char **vector;   
    switch(argc){  
	    case 2:   
				if(argv[1][0]>='0'&&argv[1][0]<='9'){	   
					n=argc-1;
					num=getListOfInts(n,argv+1);
					break;
				      }
				else if(argv[1][0]=='-')
					if(argv[1][1]=='a'||argv[1][1]=='A')
				        order=ASC;
				    else if(argv[1][1]=='d'||argv[1][1]=='D')
				        order=DESC;
	    case 1: 
			   printf("Enter number of Elements: ");
			   scanf("%d",&n);
			   printf("Enter Elemnts\n");
			   num=(int *) malloc(sizeof(int)*n);
			   for(i=0;i<n;i++)
				   scanf("%d",num+i);  
			   break; 
	     default:
				vector=argv+1;
				n=argc-1;
				if(argv[1][0]=='-'){
					if(argv[1][1]=='a'||argv[1][1]=='A')
				        order=ASC;
				    else if(argv[1][1]=='d'||argv[1][1]=='D')
				        order=DESC;
					vector=argv+2;
					n=argc-2;	
					}     
				num=getListOfInts(n,vector);
	     }

    bubble_sort(order,n,num);
   
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
     
    printf("\n");

	return 0;

}

void bubble_sort(int order,int n,int *num){
    int i,j,tmp;
    
	for(i=n;i>0;i--)
        for(j=0;j<i-1;j++)
            if((num[j+1]<num[j]&&order==ASC) ||
               (num[j+1]>num[j]&&order==DESC))
               {
                 tmp=num[j];
                 num[j]=num[j+1];
                 num[j+1]=tmp;
               }
     
}
