//---------------------------------------------------------------------------
#include <stdio.h>
#define N 5
#define M 5

void print_matr(int mas[][M], int n, int m) //�����������! ����� ������-�����
{
int i,j;
printf ("Is Matrix\n");
	 for (i=0; i<n; i++)
		 {
			 for(j=0; j<m; j++)
			     printf("%5d", mas[i][j]);
		     printf("\n");
		 }
}
void input_matr(int mas[][M], int &n, int &m)
{
   int i,j;
   do
   {
	  printf("Input Rows <=%d & Columns <=%d\n",N,M);
	  scanf("%d%d",&n,&m);
   }while (n>5 || m>5);
   printf("Input elements\n");
   for (i=0; i<n; i++)
	  for(j=0; j<m; j++)
		 scanf("%d", & mas[i][j]);
}


/* ���������� � ���������� ������ � ���������� ��������� -.
��������� �����, ��� ����������� ���������  -
����� ������ �� �������,
� ������� �� ���������� ����� ��� ��������� �� �������.
��� �������� - �������� �� ��������.
*/

void Sum_Rows(int mas[][M], int n, int m, int Sum[])
{
   int i,j;
   for (i=0; i<n; i++)
   {
   Sum[i]=0;
	  for(j=0; j<m; j++)
		 Sum[i] += mas[i][j];
   }
}
void Sum_Columns(int mas[][M], int n, int m, int Sum[])
{
   int i,j;
   for (j=0; j<m; j++)
   {
   Sum[j]=0;
	  for(i=0; i<n; i++)
		 Sum[j] += mas[i][j];
   }
}

// ����� ������� � ����� ����
void print_mas(int mas[], int len)

  { int i;
	printf("Is Array:\n");
	for (i=0; i<len; i++)
       printf("%5d",mas[i]);
	printf("\n");
  }


// ��������� ������� - ������������ ������.
//���������� ��������� � ������ ��������� �� ������.

int ** get_matr (int & n, int & m)
{
int	**a;
int i,j;
printf ("Input Rows, Columns\n");
scanf("%d%d", &n,&m);

a = new int * [n];       // ��� ������� �����
if (a == NULL)
{  printf("\n No memory\n");
   return NULL;         // �� �������
}
for (i = 0; i < n; i++)
{  a[i] = new int [m];  // ��� ������ ������
     if (a[i] == NULL) {
	printf("\nNo memory");
	return NULL;        // �� �������
}
}
printf ("Input matrix A(%d,%d)", n, m);
for (i = 0; i < n; i++)
   for (j = 0; j < m; j++)
	  scanf("%d", &a[i][j]);
return a;    // ����� ������������ ������
}

// ����� �������.
void print_matr_din (int **mas, int n, int m)     // ����������� ���������
{  int i,j;
   for (i=0;i<n;i++)
	  {
	  for(j=0;j<m;j++)
		 printf("%5d", mas[i][j]);//*(mas+i*m+j));
	  printf("\n");
	  }
}

// ������� � ��������� ������.
// �������� � ������� ������ ������� ��� ����������� �������.
// ������������� ������� �������������� ����������� �������
// ��� ������ �� �������� �������.

void print_matr_1(int mas[][M], int n, int m)
{
   for (int i=0; i<n; i++)
	  print_mas (mas[i],m);
}

void Change (int mas[], int len)
{   //���������� ������� ���������� ������
	int *ip;
	int *min=mas;
	for (ip=mas; ip<mas+len; ip++)
	  if (*ip<*min)
		 min=ip;
	// ������������
	*ip = *min;
	*min =*mas;
	*mas = *ip;
}


