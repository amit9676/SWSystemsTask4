#include "node.c"


typedef struct Graph{
    int amountOfNodes;
    int amountOfEdges;
    int highestNodeID;
    Node *nodes;
    Edge *edges;
    //int *test;
    //int edges[][3];
}Graph;

