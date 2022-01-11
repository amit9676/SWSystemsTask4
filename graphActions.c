#include "NodeLinkedList.c"
#include "EdgeLinkedList.c"
#include "declerations.h"

void insertEdgeToGraph(Edge edgeToAdd, Graph *g){
    Edge **address = &(g->edges);
    int a = nodeEXISTS(edgeToAdd.src,g->nodes);
    int b = nodeEXISTS(edgeToAdd.dest,g->nodes);
    //check if for the edge we inserting - the src and dest
    //nodes actually exist on graph
    if(a == 0 || b == 0){ 
        return;
    }
    insertEdge(edgeToAdd,address);
    g->amountOfEdges++;
}

void insertEdgeParametersToGraph(int src, int dest, int weight, Graph *g){
    Edge e;
    e.src = src;
    e.dest = dest;
    e.weight = weight;
    e.next = NULL;
    insertEdgeToGraph(e, g);
}



void insertNodeLastOnGraph(Node nodeToAdd, Graph *g){
    Node **address = &(g->nodes);
    int nodeAlreadyExists = nodeEXISTS(nodeToAdd.id,*address);
    if(nodeAlreadyExists == 1){
        deleteAllGoingNode(nodeToAdd.id, -1, &(g->edges), g);
        return;
    }
    insertNodeLast(nodeToAdd, address);
    
    g->amountOfNodes++;
    if(nodeToAdd.id > g->highestNodeID){
        g->highestNodeID = nodeToAdd.id;
    }
}

void insertNodeLastWithIDOnGraph(int id, Graph *g){
    Node t;
    t.id = id;
    t.next = NULL;
    insertNodeLastOnGraph(t,g);
}

void insertNodeByIndexOnGraph(int index, Node nodeToAdd, Graph* g){
    Node **address = &(g->nodes);
    insertNodeByIndex(index, nodeToAdd, address);
    g->amountOfNodes++;
    if(nodeToAdd.id > g->highestNodeID){
        g->highestNodeID = nodeToAdd.id;
    }
}

void deleteAllGoingNode(int nodeId, int flag, Edge** address, Graph* g){//dont use from outside this page
    
    Edge **prev = address;
    Edge *current = *address;
    while(current!= NULL){
        if(current->src == nodeId || (flag != -1 && current->dest == nodeId)){
            *prev = current->next;
            free(current);
            current = *prev;
            g->amountOfEdges--;
        }
        else{
            prev = &(current)->next;
            current = current->next;
        }
    }
}

void deleteFirstEdgeOnGraph(Graph *g)
{ 
    Edge **h = &(g->edges);
    deleteFirstEdge(h);
    g->amountOfEdges--;
}

void deleteFirstNodeOnGraph(Graph *g)
{ 
    Node **h = &(g->nodes);
    Node *p = getNodeByIndex(0,*h);
    deleteAllGoingNode(p->id, 0, &(g->edges), g);
    deleteFirstNode(h);
    g->amountOfNodes--;
}

void deleteNodeByIDOnGraph(int id, Graph *g){
    Node **address = &(g->nodes);
    int isDeleted = 0;
    isDeleted = deleteNodeByID(id,address);
    if(isDeleted == 1){
        if(g->highestNodeID == id){
            g->highestNodeID = nodeWithHighestID(*address);
        }
        deleteAllGoingNode(id, 0, &(g->edges), g);
        g->amountOfNodes--;
    }
}

void deleteNodeByIndexOnGraph(int index, Graph *g){
    Node **address = &(g->nodes);
    int isDeleted = 0;
    isDeleted = deleteNodeByIndex(index,address);
    if(isDeleted == 1){
        g->highestNodeID = nodeWithHighestID(*address);
        deleteAllGoingNode(index, 0, &(g->edges), g);
        g->amountOfNodes--;
    }
}


void deleteEdgeBySrcAndDestOnGraph(int src, int dest, Graph *g){
    Edge **address = &(g->edges);
    int isDeleted = 0;
    isDeleted = deleteEdgeBySrcAndDest(src,dest,address);
    if(isDeleted == 1){
        g->amountOfEdges--;
    }
}

void deleteEdgeByIndexOnGraph(int index, Graph *g){
    Edge **address = &(g->edges);
    int isDeleted = 0;
    isDeleted = deleteEdgeByIndex(index,address);
    if(isDeleted == 1){
        g->amountOfEdges--;
    }
}

Node* getNodeByIDONGraph(int id, Graph *g){
    Node *address = g->nodes;
    return getNodeByID(id,address);
}

Node* getNodeByIndexOnGraph(int index, Graph *g){
    Node* address = g->nodes;
    return getNodeByIndex(index,address);
}

Edge* getEdgeBySrcAndDestOnGraph(int src, int dest, Graph *g){

    Edge *address = g->edges;
    return getEdgeBySrcAndDest(src,dest,address);
}

Edge* getEdgeByIndexOnGraph(int index, Graph *g){

    Edge *address = g->edges;
    return getEdgeByIndex(index,address);
}

int nodeEXISTSOnGraph(int id, Graph *g){
    Node* address = g->nodes;
    return nodeEXISTS(id,address);
}

Graph* eraseGraph(Graph *g){
    if(g == NULL){
        return NULL;
    }
    int edgeCount = g->amountOfEdges;
    int nodeCount = g->amountOfNodes;
    for(int i = 0; i < edgeCount;i++){
        deleteFirstEdgeOnGraph(g);
    }
    for(int i = 0; i < nodeCount;i++){
        deleteFirstNodeOnGraph(g);
    }
    free(g);
    return NULL;
}

Graph* buildGraph(){
    Graph *g;
    g = malloc(sizeof(Graph));
    
    g->amountOfNodes = 0;
    g->amountOfEdges = 0;
    g->nodes = NULL;
    g->edges = NULL;
    g->highestNodeID = -1;
    return g;
}