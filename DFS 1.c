#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top,size;
    int *arr;
}stack;

int isFull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

void push(stack *s,int val){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void DFS(stack *s,int *adj[],int *visited,int size){
    int i,k,start;
    printf("Enter the start node : ");
    scanf("%d",&start);
    push(s,start);
    visited[start] = 1;

    while(!isEmpty(s)){
        start = pop(s);
        printf("%d\t",start);
        for(i = 0;i < size;i++){
            if(adj[start][i] && visited[i] == 0){
                push(s,i);
                visited[i] = 1;
                break;
            }
        }
    }
}

int main()
{
    int nodes,edges,start,i;
    printf("Enter number of nodes and edges --> ");
    scanf("%d%d",&nodes,&edges);
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc((s->size)*sizeof(int));

    int *visited = (int *)calloc(nodes,sizeof(int));

    printf("Enter the node connections --> \n");
    int *adj[nodes];
    for(i =0;i< nodes;i++){
        adj[i] = (int *)calloc(nodes,sizeof(int));
    }

    for(i = 0;i < edges;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        adj[v1][v2] = 1;
    }
    DFS(s,adj,visited,nodes);

    free(s);
    free(visited);
    return 0;
}
