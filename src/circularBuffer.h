#include "stdbool.h"
#include "stdlib.h"

typedef struct 
{
    int *buffer;
    int capacity;
    int head;
    int tail;
}CircularB;

//Functiion declarations
CircularB initBuffer(int capacity); 
bool isBufferFull(CircularB* buff);
void push(CircularB* buff, int element);
bool isBufferEmpty(CircularB* buff);
int pull(CircularB* buff);