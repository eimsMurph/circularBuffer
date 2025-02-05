#include "../src/circularBuffer.h"
#include "../unity/unity.h"

void setUp(void){

}

void tearDown(void){

}

//Test circular buffer immplementation
void test_initBuffer(void){
    CircularB buff = initBuffer(6);
    TEST_ASSERT_EQUAL_INT(0, buff.head);
    TEST_ASSERT_EQUAL_INT(0, buff.tail);
}

//Test isBufferFull function
//Test should fail when buffer isn't full
void test_isBufferFull(void){
    CircularB buff = initBuffer(3);
    TEST_ASSERT_FALSE(isBufferFull(&buff));
    push(&buff, 1);
    push(&buff, 2);
    push(&buff, 3);
    TEST_ASSERT_TRUE(isBufferFull(&buff));
}

//Test push function 
void test_pushtoBuff(void){
    CircularB buff = initBuffer(3);
    if(!isBufferFull(&buff)){
        push(&buff, 1);
        //Check last element is element that's just been added
        TEST_ASSERT_EQUAL(1, buff.buffer[(buff.tail-1)]);
    }

}

//Test isBufferEmpty function
void test_isBufferEmpty(void){
    CircularB buff = initBuffer(3);
    TEST_ASSERT_TRUE(isBufferEmpty(&buff));
}

void test_pullfromBuff(void){
    CircularB buff = initBuffer(3);
    push(&buff, 1);
    push(&buff, 2);
    if(isBufferEmpty(&buff)==false){
        pull(&buff);

    }
    TEST_ASSERT_EQUAL(1, buff.buffer[buff.tail-1]);
}
//Main code for unity
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_initBuffer);
    RUN_TEST(test_isBufferFull);
    RUN_TEST(test_pushtoBuff);
    RUN_TEST(test_isBufferEmpty);
    RUN_TEST(test_pullfromBuff);
    return UNITY_END();
}