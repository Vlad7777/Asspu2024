#include  <alloc.h>
 void *malloc_void(int Size_type, int Size_I, int Size_J = 1)
  {
 void *Name;
 if ((Name = malloc (Size_I * Size_J * Size_type)) == NULL)
	{       //�������
//	 printf("�������筮 XMS ����� ��� ࠧ��饭�� ���� - %s \r\n",Name);
//	 exit(1);  
	}
  return Name;
  }
