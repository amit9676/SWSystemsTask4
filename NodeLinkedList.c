Node* newNode(int id, int tag, Node *next){//dont use from outside this page
    Node *v = (Node*)malloc(sizeof(Node));
    v->id = id;
    v->tag = tag;
    v->next = next;
    return v;
}

void insertNodeLast(Node nodeToAdd, Node **address){
    while(*address != NULL){
        address = &((*address)->next);
    }
    
    *address = newNode(nodeToAdd.id, nodeToAdd.tag, NULL);
}

void insertNodeByIndex(int index, Node nodeToAdd, Node **address){
    int counter = 0;
    while(*address != NULL){
        if(counter == index){
            *address = newNode(nodeToAdd.id, nodeToAdd.tag, *address);
            return;
        }
        address = &((*address)->next);
        counter++;
    }
    
    *address = newNode(nodeToAdd.id, nodeToAdd.tag, NULL);
}

void deleteFirstNode(Node **h)
{ 
    if(!*h) return;
    Node *p = *h;
    *h = p->next;
    free(p);
}

int deleteNodeByID(int id, Node **head){
    Node **prev = head;
    Node *current = *head;
    while(current != NULL){
        if(current->id == id){
            *prev = current->next;
            free(current);
            current = NULL;
            return 1;
        }
        prev = &(current)->next;
        current = current->next;
    }
    return 0;
}

int deleteNodeByIndex(int index, Node **head){
    Node **prev = head;
    Node *current = *head;
    int counter = 0;
    while(current != NULL){
        if(counter == index){
            *prev = current->next;
            free(current);
            current = NULL;
            
            return 1;
        }
        prev = &(current)->next;
        current = current->next;
        counter++;
    }
    return 0;
}

Node* getNodeByID(int id, Node* head){
    Node *current = head;
    while(current != NULL){
        if(current->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* getNodeByIndex(int index, Node* head){
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

int nodeEXISTS(int id, Node* head){
    Node *current = head;
    while(current != NULL){
        if(current->id == id){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int nodeWithHighestID(Node* head){
    int currentMaxID = -1;
    Node *current = head;
    while(current != NULL){
        if(current->id > currentMaxID){
            currentMaxID = current->id;
        }
        current = current->next;
    }
    return currentMaxID;
}

int amountOfNodesInLinkedList(Node* head){
    int amount = 0;
    Node *current = head;
    while(current != NULL){
        current = current->next;
        amount++;
    }
    return amount;
}

void insertNodeBasedOnExternalValue(Node nodeToAdd, Node **address, double allDist[]){
    while(*address != NULL){
        if(allDist[nodeToAdd.id] < allDist[(*address)->id]){
            *address = newNode(nodeToAdd.id, nodeToAdd.tag, *address);
            return;
        }
        address = &((*address)->next);
    }
    
    *address = newNode(nodeToAdd.id, nodeToAdd.tag, NULL);
}

void eraseNodeList(Node *address){
    int amount = amountOfNodesInLinkedList(address);
    for(int i = 0; i < amount; i++){
        deleteFirstNode(&address);
    }
}

