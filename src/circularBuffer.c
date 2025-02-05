#include "../src/circularBuffer.h"

//Function to initialise buffer
CircularB initBuffer(int capacity){
    CircularB b;
    b.capacity = capacity;
    b.buffer = (int*)malloc(sizeof(int)*capacity); //Allocating memory to the buffer upon initialization
    b.head = 0;
    b.tail = 0;  
    return b;

}

//Function to check if buffer is full
bool isBufferFull(CircularB* buff){
    return ((buff->tail+1) % buff->capacity == buff->head);
}

//Function to push elements to buffer
void push(CircularB* buff, int element){
    //Check if buffer is full
    if(isBufferFull(buff) == true){
        buff->buffer[buff->head] = element;
        //Increment pointers
        buff->head = (buff->head + 1) % buff->capacity;
        buff->tail = (buff->tail + 1) % buff->capacity;

    }
    //Buffer is not yet full
    buff->buffer[buff->tail] = element;
    //Increment pointers
    buff->tail = (buff->tail + 1) % buff->capacity;
}

//Function to check if buffer is empty
bool isBufferEmpty(CircularB* buff){
    return ((buff->head == buff->tail));
}

int pull(CircularB* buff){
    if(isBufferEmpty(buff)){
        return -1;
    }
    else{
        int pulled = buff->buffer[buff->head];
        buff->head = (buff->head+1) % buff->capacity;
        return pulled; 
    }

    
}
