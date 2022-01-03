#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"
#include "actions.c"

int main(){
    /*Graph *g;
    g = buildGraph();
    //printf("%d", g->amountOfEdges);

    
    for(int i = 0; i < 10; i++){
        Node current;
        current.id = i;
        //printf("%d\n", g->amountOfNodes);
        insertNodeLast(current, g);
        //printf("%d\n", g->amountOfNodes);
        
    }
    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10;j++){
            Edge e;
            e.src = i;
            e.dest = j;
            e.weight = i+j;
            insertEdge(e, g);
        }
        
    }
    //int p = nodeEXISTS(17,g);
    printf("%d\n",g->highestNodeID);
    distanceInit(2,3,g);
    eraseGraph(g);
    //printf("%d\n",g->amountOfNodes);*/


    /*printf("%d\n", g->amountOfEdges);
    deleteFirstNode(g);
    printf("%d\n", g->amountOfEdges);*/
    //deleteNode(6,g);
    //printf("%d\n", g->amountOfEdges);
    Node *list = NULL;
    





    /*Node *n;
    n = NULL;
    printf("%p\n", n);
    n = getNode(&(g->nodes),5);
    printf("%p\n", n);
    printf("%d\n",n->id);
    printf("-----------------------\n");
    deleteNode(&(g->nodes),5);
    printf("%p\n", n);
    printf("%d\n", n->id);*/
    
}