#include "main.h"
int increment;
int specific_color(struct box *ptr,int Spec_Color)
{
int count = 0;
    int x = increment;
for(int k=0;k<=x-1;k++)
{ 
    if(!strcmp(ptr->color,Spec_Color))
        {
        //printf("%d %f %f %f %s %f", *(ptr + j)->unique_id, *(ptr + j)->length,*(ptr+j)->breadth,*(ptr+j)->height,*(ptr+j)->color,*(ptr+j)->weight);
        count += 1;
        }
    ptr++;
}
printf("%d",count);
}

 

      