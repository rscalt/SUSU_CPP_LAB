#include <stdio.h>
#include <string.h>
#define  LEN_MAX 10

// Вывод массива на экран.
void Print_mas (int mas[], int len)    //Длина не изменяется, len-значение
{ int i;
	printf("Is array:\n");
	for (i=0;i<len;i++)
	   printf("%5d",mas[i]);
	printf("\n");
}
// Вывод массива в файл.
void Print_mas(FILE * out, int mas[], int len)  //Длина не изменяется, len-значение
{
	int i;
	//fprintf(out, "Is array:\n");
	for (i = 0; i<len; i++)
		fprintf(out, "%5d", mas[i]);
	fprintf(out, "\n");
}

void Input_mas (int mas[], int len)    //Длина не изменяется, len-значение
{ int i;
	for (i=0;i<len;i++)
	   scanf("%d",&mas[i]);
}

// Ввод массива с окончанием по feof (Ctrl_Z)
void Input_mas (FILE *in, int *mas, int &len)    // Массив длиной len<100
{
len=0;
do                                  // a) конец файла.
   {                                // б) длина <100.
	 fscanf(in,"%d", &mas[len]);    // размер массива
	 len++;
   }
while(!feof(in) && len<LEN_MAX);
   len--;
}

// Чтение матрицы из файла
void Read_matr(FILE *in, int matr[][10],int &n, int &m)
{
   fscanf(in,"%d", &n);    // размер матрицы - строк, столбцов
   fscanf(in,"%d", &m);
   int i,j;
   for (i=0; i<n; i++)
      for (j=0; j<m; j++)
		 fscanf(in,"%d", &matr[i][j]);
}
// Вывод матрицы в файл
void Print_matr(FILE * out, int matr[][10],int n, int m)
{
int i,j;
   for (i=0;i<n;i++)
   {
      for (j=0;j<m;j++)
		 fprintf(out,"%6d",matr[i][j]);
   fprintf(out,"\n");
   }
}

// Пример для преобразования строк

char * Add_10(char * str)
{
  char *s;
  s = new char [2*strlen(str)];
  int i,j=1;
  s[0]='!';
  for (i=0; i<strlen(str); i++)
  { if (i%10==0 && i!=0)
	{ s[j++]=':';
      s[j++]='!';
      s[j++]=':';
    }
    else
      s[j++]=str[i];
   }
  s[j]='\0';
  return s;
  }

