typedef struct  singleEdge{
    int src;
    int dest;
    int weight;
    struct singleEdge *next;
}Edge;