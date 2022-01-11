Edge* newEdge(int src, int dest, int weight, Edge* next){
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->src = src;
    e-> dest = dest;
    e-> weight = weight;
    e->next = next;
    return e;
}

void insertEdge(Edge edgeToAdd, Edge **address){
    while(*address != NULL){
        if((*address)->src == edgeToAdd.src && (*address)->dest == edgeToAdd.dest){
            (*address)->weight = edgeToAdd.weight;
            return;
        }
        address = &((*address)->next);
    }
    *address = newEdge(edgeToAdd.src, edgeToAdd.dest, edgeToAdd.weight, NULL);
}

void insertEdgeParameters(int src, int dest, int weight, Edge **address){
    Edge e;
    e.src = src;
    e.dest = dest;
    e.weight = weight;
    insertEdge(e, address);
}

void deleteFirstEdge(Edge **h)
{ 
    if(!*h) return;
    Edge *p = *h;
    *h = p->next;
    free(p);
}

int deleteEdgeBySrcAndDest(int src, int dest, Edge **head){
    Edge **prev = head;
    Edge *current = *head;
    while(current != NULL){
        if(current->src == src && current->dest == dest){
            *prev = current->next;
            free(current);
            return 1;
        }
        prev = &(current)->next;
        current = current->next;
    }
    return 0;
}

int deleteEdgeByIndex(int index, Edge **head){
    Edge **prev = head;
    Edge *current = *head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            *prev = current->next;
            free(current);
            return 1;
        }
        prev = &(current)->next;
        current = current->next;
        counter++;
    }
    return 0;
}

Edge* getEdgeBySrcAndDest(int src, int dest, Edge *head){

    Edge *current = head;

    while(current != NULL){
        if(current->src == src && current->dest == dest){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Edge* getEdgeByIndex(int index, Edge *head){

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