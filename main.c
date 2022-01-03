#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"
#include "actions.c"

int main(){
    /*Edge t;
    t.src = 2;
    t.dest=3;
    t.weight=1;
    t.next = NULL;

    Node n;
    n.edges = NULL;
    printf("before: %p\n", n.edges);
    void insertEdge(Edge,Edge**);
    insertEdge(t,&(n.edges));
    printf("after: %p\n", n.edges);*/
   void inputHandler();
   inputHandler();
    return 0;
}

void inputHandler(){
    int createNewGraph();
    char t;
    int mode = 0;
    int counter = 0;
    int input = 0;
    input = scanf("%c", &t);
    do{
        printf("??\n");
        if(t == 65){
            
            t = createNewGraph();
        }
        else if(t == 66){
            printf("hi");
            mode = 2;
        }
        else if(t == 68){
            mode = 3;
        }
        else if(t == 83){
            printf("%d", counter);
            counter++;
            mode = 4;
        }
        else if(t == 84){
            mode = 5;
        }
        else if(t == 10){
            break;
        }
        //printf("%c, ",t);
    }
    while(t != 10 && input == 1);
}

int createNewGraph(){
    void insertEdge(Edge,Edge**); //decleration
    int n;
    scanf("%d", &n);
    printf("\n%d\n", n);
    Graph *g = malloc(sizeof(Graph));
    g->amountOfNodes = n;

    //Node no;
    g->nodes = (Node*)malloc(sizeof(Node) * n);
    for(int i = 0; i < n; i++){
        g->nodes[i].id = i;
        g->nodes[i].edges = NULL;
    }
    char t;
    int input;
    do{
        do{
            input = scanf("%c", &t);
        }
        while(t == 32);
        if(t == 110){//if input is 'n'
            int id;
            scanf("%d", &id);
            t=id;
            int dest;
            int w;
            do{
                if(scanf("%d", &dest)==0){
                    dest = -1;
                };
                if(scanf("%d", &w)){
                    w = -1;
                }
                
                //t=w;
                Edge e;
                e.src = id;
                e.dest = dest;
                e.weight = w;
                e.next = NULL;

                insertEdge(e,&(g->nodes[id].edges));
                printf("sucsess");
            }while(w != -1 && dest != -1);
        }
        //printf("%d, ", t);
    }
    while(t != 66 && t != 68 && t!= 83 && t != 84 && t != 10 && input == 1);
    return t;
}