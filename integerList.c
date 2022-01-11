#include <stdlib.h>

typedef struct Integer{
    int value;
    struct Integer *next;
}Integer;


Integer* newInteger(int value, Integer* next){
    Integer *i = (Integer*)malloc(sizeof(Integer));
    i->value = value;
    i->next = next;
    return i;
}

void insertNonDuplicateInteger(int value, Integer **address){

    while(*address != NULL){
        if(value == (*address)->value){
            return;
        }
        address = &((*address)->next);
    }
    *address = newInteger(value, NULL);
}

void deleteFirstInteger(Integer **address){
    if(!*address){
        return;
    }
    Integer *deleteThis = *address;
    *address = deleteThis->next;
    free(deleteThis);

}

int getIntegerListSize(Integer *address){
    int counter = 0;
    while(address != NULL){
        counter++;
        address = address->next;
    }
    return counter;
}

void eraseIntegerList(Integer *address){
    int size = getIntegerListSize(address);
    for(int i = 0; i < size; i++){
        deleteFirstInteger(&address);
    }
}

