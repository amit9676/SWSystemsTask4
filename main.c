#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.c"
#include "actions.c"

int main(){
    int amountOfNodes = 0;

    char c;

    Graph *g = NULL;
	g = buildGraph();
    scanf("%c", &c);
	while (c != '\n')
    {
        if (c == ' ')
        {
            scanf("%c", &c);
        }
        if (c == 'A')
        {
            if (g != NULL){
              	eraseGraph(g);
            }
            g = buildGraph();
            scanf("%d", &amountOfNodes);
            for(int i = 0; i < amountOfNodes; i++){
                insertNodeLastWithIDOnGraph(i, g);
            }
			scanf("%c", &c);
			if(c == ' '){
				scanf("%c", &c);
			}
			while (c == 'n') {
				int srcy;
				scanf("%c", &c);
				scanf("%d", &srcy);
				int d;
				int a;
				int b;
				scanf("%c", &c);
				d = scanf("%d", &a);
				if(d == 0){
					break;
				}
				scanf("%c", &c);
				d = scanf("%d", &b);
				if(d == 0){
					break;
				}
				insertEdgeParametersToGraph(srcy,a,b,g);
				scanf("%c", &c);
				
				while(c == ' '){
					d = scanf("%d", &a);
					if(d == 0){
						break;
					}
					scanf("%c", &c);
					d = scanf("%d", &b);
					if(d == 0){
						break;
					}
					insertEdgeParametersToGraph(srcy,a,b,g);
					scanf("%c", &c);
				}
				scanf("%c", &c);
			}

        }
        if (c == 'E')
        {
            break;
		}
        if (c == 'B')
        {
            int srcy;
			scanf("%d", &srcy);
			if(g != NULL){
				insertNodeLastWithIDOnGraph(srcy, g);
			}
			
			int a;
			int b;
			scanf("%c", &c);
			scanf("%d", &a);
			scanf("%c", &c);
			scanf("%d", &b);
			if(g != NULL){
				insertEdgeParametersToGraph(srcy,a,b,g);
			}
			
			scanf("%c", &c);
			int d;
			while(c == ' '){
				
				d = scanf("%d", &a);
				if(d == 0){
					break;
				}
				scanf("%c", &c);
				d = scanf("%d", &b);
				if(d == 0){
					break;
				}
				if(g != NULL){
					insertEdgeParametersToGraph(srcy,a,b,g);
				}
				
				scanf("%c", &c);
			}
			scanf("%c", &c);
        }
        if (c == 'D')
        {
            int nodeToDelete;
			scanf("%d", &nodeToDelete);
			deleteNodeByIDOnGraph(nodeToDelete,g);
			scanf("%c", &c);
			continue;
        }
        if (c == 'S')
        {
            int src, dst;
            scanf("%c", &c);
			scanf("%d", &src);
			scanf("%c", &c);
			scanf("%d", &dst);
			int result;
            result = distanceInit(src, dst,g);
			printf("Dijsktra shortest path: %d \n", result);
        }
        if (c == 'T')
        {
			Integer* intList = NULL;
            int city;
			scanf("%c", &c);
			scanf("%c", &c);
			scanf("%c", &c);
            while(scanf("%d", &city) == 1){
				insertNonDuplicateInteger(city,&(intList));
				scanf("%c", &c);
				if(c != 32){
					break;
				}
			}
			int result;
            result = tspInitilize(intList, g);
			printf("TSP shortest path: %d \n", result);
			eraseIntegerList(intList);
			continue;
        }
		if(c == '\n'){
			break;
		}
    }
	eraseGraph(g);
    
}