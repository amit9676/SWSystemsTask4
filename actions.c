#include <math.h>
#include "graphActions.c"
#include "integerList.c"


//distance calculation
int distanceInit(int src,int dest, Graph* g){
    if(nodeEXISTSOnGraph(src,g) == 0 || nodeEXISTSOnGraph(dest,g) == 0 ){
        return -1;
    }

    double allDists[(g->highestNodeID) + 1];
    double infi = INFINITY;
    
    for(int i = 0; i < g->amountOfNodes; i++){
        Node *n = getNodeByIndexOnGraph(i,g);
        n->tag = 1;
        allDists[n->id] = infi;
    }
    allDists[src] = 0;
    return (int)shortestDestAid(src, dest, 0, allDists, g, infi);
   
}

double shortestDestAid(int src, int dest, double dist3, double allDists[], Graph* g, double infi){

    
    Node *nodeList = NULL;
    Node* currentNode;
    Edge* currentEdge;

    Node* destNode;

    while(src != dest){
        currentNode = getNodeByIDONGraph(src, g);
        currentNode->tag = 2;
        
        int edgeCount = g->amountOfEdges;
        for(int i = 0 ; i < edgeCount; i++){
            currentEdge = getEdgeByIndexOnGraph(i,g);
            
            if(currentEdge->src != src){
                continue;
            }
            destNode = getNodeByIDONGraph(currentEdge->dest, g);
            
            double instantDist = currentEdge->weight;
            
            if(instantDist + dist3 < allDists[currentEdge->dest] && destNode->tag == 1){
                allDists[currentEdge->dest] = instantDist + dist3;
                insertNodeBasedOnExternalValue(*destNode, &(nodeList), allDists);
            }
        }
        int k = -1;
        if(nodeList != NULL && amountOfNodesInLinkedList(nodeList) > 0){

            
            Node *ExtractedNode = getNodeByIndex(0,nodeList);
            int ExtractedNodeID = ExtractedNode->id;
            if(allDists[ExtractedNodeID] < infi){
                while(nodeList != NULL && amountOfNodesInLinkedList(nodeList) > 0 && getNodeByIDONGraph(ExtractedNodeID,g)->tag == 2){
                    deleteFirstNode(&(nodeList));
                    if(nodeList != NULL && amountOfNodesInLinkedList(nodeList) > 0 ){
                        ExtractedNode = getNodeByIndex(0,nodeList);
                        ExtractedNodeID = ExtractedNode->id;
                    }
                    
                }
                if(nodeList != NULL && amountOfNodesInLinkedList(nodeList) > 0){
                    k = getNodeByIndex(0,nodeList)->id;
                    dist3 = allDists[k];
                }
            }
        }
        if(k == -1){
            eraseNodeList(nodeList);
            return -1;
        }
        src = k;
    }
    eraseNodeList(nodeList);
    return dist3;
}





/* -------- tsp section ----------*/

int tspItself(int cities[], int citiesSize, Graph *g){
    int dist = 0;
    int tempDist;
    for(int i = 0; i < citiesSize - 1; i++){
        tempDist = distanceInit(cities[i], cities[i+1], g);
        if(tempDist == -1){
            return -1;
        }
        dist += tempDist;
    }
    return dist;
}

int rotateRight(int arr[], int start, int size, int currentLowest, Graph *g){
    if(start == size-1){
        return currentLowest;
    }
    int first;
    for(int k = start; k < size; k++){
        

        currentLowest = rotateRight(arr,start+1,size, currentLowest, g);
        
        first = arr[start];
        for(int i = start; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        arr[size-1] = first;
        
        if(k < size - 1 || start == 0){
            int result = tspItself(arr,size, g);
            if((currentLowest == -1 || result < currentLowest) && result != -1){
                currentLowest = result;
            }
        }
    }
    return currentLowest;
}

int tspInitilize(Integer *address, Graph *g){
    int size = getIntegerListSize(address);
    int output[size];
    int counter = 0;
    while(address != NULL){
        if(nodeEXISTSOnGraph(address->value,g) == 0){
            return -1;
        }
        output[counter++] = address->value;
        address = address->next; 
    }
    int result = rotateRight(output,0,size,-1,g);
    return result;
}

