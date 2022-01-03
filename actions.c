#include <math.h>

Edge* newEdge(int src, int dest, int weight, Edge* next){//dont use from outside this page
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->src = src;
    e-> dest = dest;
    e-> weight = weight;
    e->next = next;
    return e;
}
void insertEdge(Edge edgeToAdd, Graph *g){
    int nodeEXISTS(int,Graph*);
    Edge **address = &(g->edges);
    int a = nodeEXISTS(edgeToAdd.src,g);
    int b = nodeEXISTS(edgeToAdd.dest,g);
    //check if for the edge we inserting - the src and dest
    //nodes actually exist on graph
    if(a == 0 || b == 0){ 
        return;
    }
    while(*address != NULL){
        if((*address)->src == edgeToAdd.src && (*address)->dest == edgeToAdd.dest){
            (*address)->weight = edgeToAdd.weight;
            return;
        }
        address = &((*address)->next);
    }
    *address = newEdge(edgeToAdd.src, edgeToAdd.dest, edgeToAdd.weight, NULL);
    g->amountOfEdges++;
}

Node* newNode(int id, int tag, Node *next){//dont use from outside this page
    Node *v = (Node*)malloc(sizeof(Node));
    v->id = id;
    v->tag = tag;
    v->next = next;
    return v;
}
void insertNodeLast(Node nodeToAdd, Graph *g){
    Node **address = &(g->nodes);
    void deleteAllGoingNode(int, int, Graph*);
    while(*address != NULL){
        if(nodeToAdd.id == (*address)->id){
            deleteAllGoingNode(nodeToAdd.id, -1, g);
            return;
        }
        address = &((*address)->next);
    }
    
    *address = newNode(nodeToAdd.id, nodeToAdd.tag, NULL);
    g->amountOfNodes++;
    if(nodeToAdd.id > g->highestNodeID){
        g->highestNodeID = nodeToAdd.id;
    }
}

void insertNodeByIndex(int index, Node nodeToAdd, Graph *g){
    Node **address = &(g->nodes);
    void deleteAllGoingNode(int, int, Graph*);
    int counter = 0;
    while(*address != NULL){
        if(counter == index){
            *address = newNode(nodeToAdd.id, nodeToAdd.tag, *address);
        }
        address = &((*address)->next);
        counter++;
    }
    
    *address = newNode(nodeToAdd.id, nodeToAdd.tag, NULL);
    g->amountOfNodes++;
    if(nodeToAdd.id > g->highestNodeID){
        g->highestNodeID = nodeToAdd.id;
    }
}

void deleteAllGoingNode(int nodeId, int flag, Graph *g){//dont use from outside this page
    
    Edge** address = &(g->edges);
    
    Edge **prev = address;
    Edge *current = *address;
    while(current!= NULL){
        if(current->src == nodeId || (flag != -1 && current->dest == nodeId)){
            *prev = current->next;
            free(current);
            current = current->next;
            g->amountOfEdges--;
        }
        else{
            prev = &(current)->next;
            current = current->next;
        }
        
    }
}

void deleteFirstEdge(Graph *g)
{ 
    Edge **h = &(g->edges);
    if(!*h) return;
    Edge *p = *h;
    *h = p->next;
    free(p);
    g->amountOfEdges--;
}

void deleteFirstNode(Graph *g)
{ 
    Node **h = &(g->nodes);
    if(!*h) return;
    Node *p = *h;
    deleteAllGoingNode(p->id, 0, g);
    *h = p->next;
    free(p);
    g->amountOfNodes--;
}

void deleteNodeByID(int id, Graph *g){
    int nodeWithHighestID(Graph*);
    Node **head = &(g->nodes);
    Node **prev = head;
    Node *current = *head;
    while(current != NULL){
        if(current->id == id){
            if(g->highestNodeID == current->id){
                g->highestNodeID = nodeWithHighestID(g);
            }
            deleteAllGoingNode(id, 0, g);
            *prev = current->next;
            free(current);
            current = NULL;
            g->amountOfNodes--;
            return;
        }
        prev = &(current)->next;
        current = current->next;
    }
}

void deleteNodeByIndex(int index, Graph *g){
    int nodeWithHighestID(Graph*);
    Node **head = &(g->nodes);
    Node **prev = head;
    Node *current = *head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            if(g->highestNodeID == current->id){
                g->highestNodeID = nodeWithHighestID(g);
            }
            deleteAllGoingNode(index, 0, g);
            *prev = current->next;
            free(current);
            current = NULL;
            g->amountOfNodes--;
            
            return;
        }
        prev = &(current)->next;
        current = current->next;
        counter++;
    }
}

void deleteEdgeBySrcAndDest(int src, int dest, Graph *g){
    Edge **head = &(g->edges);
    Edge **prev = head;
    Edge *current = *head;
    while(current != NULL){
        if(current->src == src && current->dest == dest){
            *prev = current->next;
            free(current);
            g->amountOfEdges--;
            return;
        }
        prev = &(current)->next;
        current = current->next;
    }
}

void deleteEdgeByIndex(int index, Graph *g){
    Edge **head = &(g->edges);
    Edge **prev = head;
    Edge *current = *head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            *prev = current->next;
            free(current);
            g->amountOfEdges--;
            return;
        }
        prev = &(current)->next;
        current = current->next;
        counter++;
    }
}

Node* getNodeByID(int id, Graph *g){
    Node* head = g->nodes;
    Node *current = head;
    while(current != NULL){
        if(current->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* getNodeByIndex(int index, Graph *g){
    Node* head = g->nodes;
    Node *current = head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            return current;
        }
        current = current->next;
        counter++;
    }
    return NULL;
}

Edge* getEdgeBySrcAndDest(int src, int dest, Graph *g){

    Edge *head = g->edges;
    Edge *current = head;

    while(current != NULL){
        if(current->src == src && current->dest == dest){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Edge* getEdgeByIndex(int index, Graph *g){

    Edge *head = g->edges;
    Edge *current = head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            return current;
        }
        current = current->next;
        counter++;
    }
    return NULL;
}

int nodeEXISTS(int id, Graph *g){
    Node* head = g->nodes;
    Node *current = head;
    while(current != NULL){
        if(current->id == id){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int nodeWithHighestID(Graph* g){
    int currentMaxID = -1;
    Node* head = g->nodes;
    Node *current = head;
    while(current != NULL){
        if(current->id > currentMaxID){
            currentMaxID = current->id;
        }
        current = current->next;
    }
    return currentMaxID;
}

Graph* eraseGraph(Graph *g){
    if(g == NULL){
        return NULL;
    }
    int edgeCount = g->amountOfEdges;
    int nodeCount = g->amountOfNodes;
    for(int i = 0; i < edgeCount;i++){
        deleteFirstEdge(g);
    }
    for(int i = 0; i < nodeCount;i++){
        deleteFirstNode(g);
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
}



//distance calculation
int distanceInit(int src,int dest, Graph* g){
    double allDists[g->highestNodeID];
    double infi = INFINITY;
    for(int i = 0; i < g->amountOfNodes; i++){
        Node *n = getNodeByIndex(i,g);
        n->tag = 1;
        allDists[n->id] = infi;
    }
    allDists[src] = 0;
    
    return 1;
}

int shortestDestAid(int src, int dest, double dist3, double allDists[]){
    Node *nodeList = NULL;
    
}