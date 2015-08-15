#include<stdio.h>
#include<stdlib.h>
typedef struct graph graph;
typedef struct vertex vertex;
typedef struct neighbour neighbour;

struct Queue{
    typedef struct node{
	int key;
        struct node *next;
	node(int k){
             key=k;
             next=NULL;
             }
        }node;
    node *head;
    node *tail;
    Queue(){
        head=tail=NULL;
	}
    void enqueue(int x){
        if(head==NULL)
		head=tail=new node(x);
	else{
                node *N=new node(x);
                tail->next=N;
                tail=N;
           }
    }
    int front(){
        return head->key;
      }
    void dequeue(){
        if(head==NULL)
           return;
        struct node *x=head;
        head=head->next;
        free(x);
      }
};

struct neighbour{
    int v;
    int weight;
    neighbour *next;
    neighbour(int v,int w){
        this->v=v;
        this->weight=w;
	}
};

struct vertex{
    int visited;
    neighbour *list;
    vertex(){
        visited=0;
        list=NULL;
    }
    void add_edge(int u,int w){
         neighbour *x=new neighbour(u,w);
         x->next=list;
         list=x;
    }
};
struct graph{
    int n;
    vertex *V;
    graph(int n){
        this->n=n;
	this->V=(vertex *)malloc(sizeof(vertex)*n);
	}
    void add_edge(int u,int v,int w){
        V[u].add_edge(v,w);
    }
   int *BFS(int u){
       Queue q;
       int *path=(int *)malloc(sizeof(int)*n);
       int i,v;
       for(i=0;i<n;i++)
           path[i]=-1;
       i=0;
       q.enqueue(u);
       while(q.head!=NULL){
             v=q.front();
             V[v].visited=1;
             path[i++]=v;
             neighbour *t=V[v].list;
             while(t!=NULL){
                 q.enqueue(t->v);
                 t=t->next; 
             }    
             q.dequeue();
	}       
	return path;
       }
};
int main(){
    graph G(6);
    G.add_edge(0,1,4);
    G.add_edge(1,2,1);
    G.add_edge(2,3,5);
    int *path=G.BFS(0);
    int i;
    for(i=0;path[i]!=-1&&i<G.n;i++){
	printf("%d ",path[i]);
	}
    printf("\n");

}
