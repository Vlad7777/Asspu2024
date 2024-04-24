#include <stdlib.h>
 void *malloc_void(int Size_type, int Size_I, int Size_J = 1)
  {
 void *Name;
 if ((Name = malloc (Size_I * Size_J * Size_type)) == NULL)
	{
//	 printf("Недостаточно XMS памяти для размещения буфера - %s \r\n",Name);
	 exit(1);  /* terminate program if out of memory */
   }
  return Name;
  }
