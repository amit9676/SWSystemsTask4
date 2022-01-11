#include "Node.c"
#include "Edge.c"


typedef struct Graph{
    int amountOfNodes;
    int amountOfEdges;
    int highestNodeID;
    Node *nodes;
    Edge *edges;
}Graph;

