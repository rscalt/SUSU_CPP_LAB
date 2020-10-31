#include <stdio.h>
#include <string.h>
#define  LEN_MAX 10

// ����� ������� �� �����.
void Print_mas (int mas[], int len)    //����� �� ����������, len-��������
{ int i;
	printf("Is array:\n");
	for (i=0;i<len;i++)
	   printf("%5d",mas[i]);
	printf("\n");
}
// ����� ������� � ����.
void Print_mas(FILE * out, int mas[], int len)  //����� �� ����������, len-��������
{
	int i;
	//fprintf(out, "Is array:\n");
	for (i = 0; i<len; i++)
		fprintf(out, "%5d", mas[i]);
	fprintf(out, "\n");
}

void Input_mas (int mas[], int len)    //����� �� ����������, len-��������
{ int i;
	for (i=0;i<len;i++)
	   scanf("%d",&mas[i]);
}

// ���� ������� � ���������� �� feof (Ctrl_Z)
void Input_mas (FILE *in, int *mas, int &len)    // ������ ������ len<100
{
len=0;
do                                  // a) ����� �����.
   {                                // �) ����� <100.
	 fscanf(in,"%d", &mas[len]);    // ������ �������
	 len++;
   }
while(!feof(in) && len<LEN_MAX);
   len--;
}

// ������ ������� �� �����
void Read_matr(FILE *in, int matr[][10],int &n, int &m)
{
   fscanf(in,"%d", &n);    // ������ ������� - �����, ��������
   fscanf(in,"%d", &m);
   int i,j;
   for (i=0; i<n; i++)
      for (j=0; j<m; j++)
		 fscanf(in,"%d", &matr[i][j]);
}
// ����� ������� � ����
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

// ������ ��� �������������� �����

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

