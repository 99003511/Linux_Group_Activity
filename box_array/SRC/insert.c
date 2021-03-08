#include"main.h"
int increment=0;
int insert(struct box *b2,int uid,float update_length,float update_breadth,float update_height,float update_weight,int update_color)
{
printf("increment %d\n",increment);
 if(increment==0)
 {
   
}
 else
 {
     //printf("here\n");
  b2=b2+increment;
  printf("inc %d\n",increment);
  
 }


 
 b2->length=update_length;
  printf("inc %d\n",increment);
 b2->unique_id=uid;
 b2->breadth=update_breadth;
 
 b2->height=update_height;
 b2->weight=update_weight;
 b2->color=update_color;
 printf("before increment added %d\n",increment);
increment=increment+1;
printf("after increment added %d\n",increment);

 return 1;
}
