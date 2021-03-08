#include "main.h"


int increment;
float max_height(struct box *ptr)
{
   int x = increment;
float max=ptr->height;

for(int k=0;k<=x-1;k++)
{
    if((ptr->height) > max)
    {
        max = ptr->height;
    }
    ptr++;
    }
    return max;
}
