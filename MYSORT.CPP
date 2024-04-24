#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(int *x, int *y)
 {
    return(*x - *y);
 }

int mysort(int list[], int NB)

{
   qsort((int *)list, NB, sizeof(list[0]), (int(*)(const void *,const void *))compare);
   return 0;
}

