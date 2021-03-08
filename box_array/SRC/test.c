#include"main.h"
#include "unity.h"
struct box b1[10];
struct box *ptr= NULL;
int increment;
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown()
{
    
}

void test_insert1(void)
{

    TEST_ASSERT_EQUAL(1,insert(&ptr,3,2,5,3,2,11));

}

void test_insert3(void)
{
 
    TEST_ASSERT_EQUAL(1,insert(&ptr,4,1,5,5,2,12));
    TEST_ASSERT_EQUAL(1,insert(&ptr,4,1.0,5,3,2,12));
}
void test_insert4(void)
{

    TEST_ASSERT_EQUAL(1,insert(&ptr,5,4,5,4,2,12));
}
void test_insert5(void)
{

    TEST_ASSERT_EQUAL(1,insert(&ptr,6,4,5,3,2,12));
}
void test_search(void)
{
    TEST_ASSERT_EQUAL(1,search(&ptr,4));

}

void test_max_height(void)
{
    TEST_ASSERT_EQUAL(5,max_height(&ptr));
}
/*
void test_update_weight(void)
{
    TEST_ASSERT_EQUAL(1,change_weight(&ptr,2,25));
}
*/
void test_specific_color(void)
{
    TEST_ASSERT_EQUAL(5,specific_color(&ptr,11));
}
int main(int argc, char *argv[])
{
 
increment=0;
ptr=(struct box*)malloc(10*sizeof(struct box));
if(ptr==NULL)
{
    printf("memory not alllocated\n");
    return;
}
ptr=b1;

 
 //insert(&ptr,0,1,1,1,1,1,10);
 //display(&ptr,1);
 
   UNITY_BEGIN();
  
  RUN_TEST(test_insert1);
  RUN_TEST(test_insert3);
  RUN_TEST(test_insert4);
  RUN_TEST(test_insert5);

  //RUN_TEST(test_update_weight);
  RUN_TEST(test_max_height);
  RUN_TEST(test_specific_color);

  RUN_TEST(test_search);

  display(&ptr,increment);
  /* Close the Unity Test Framework */
  return UNITY_END();
 
 
 

 }
