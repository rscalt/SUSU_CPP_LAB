//---------------------------------------------------------------------------

#ifndef StringsH
#define StringsH
//---------------------------------------------------------------------------
#endif

#include <stdio.h>
//#include <bios.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define ESC 0x11b
//
//void Foundkey(void)
//{
//unsigned char key;
//do
//   {	key=_getch();              /*��������� ��������*/
//	printf("Symbol is %c, his (16) code is %#0x, his 10 code is %d\n",key,key,key);
//   }
//while (key !=ESC);
//}
//
//
void Code(void)
{
 int  i,j;
 for (i = 0; i < 16; i++)
 {
  for (j= 0; j < 16; j++)
	 { // if (16*i+j >7 && 16*i+j<14) continue;
	 printf(  "%c ",  16*i+j);     //���������� ������������� ���� �������
	 }
  printf("\n");
 }
}
//
//
//
////Str1 - ��������� ���������.
void Str1(void)
{
// ���������� � ������ ���������� ����������� ����.
printf ("%d\n",  sizeof(int));
printf ("%d\n",  sizeof(char));
printf ("%d\n",  sizeof(unsigned char));
//Esc ������������������ � �������
printf ("%s\n","Is String");          // ��� ������������
printf ("%s\n","Slash is written \\  ");  // ����
printf ("%s\n","Character \"apostrof\" written double");   // ��������
printf ("%s\n","The long string \
				can bi break on \
				variable parts -  \
				real this is one string.");
printf ("%s\n","The long string \n can bi break on\n variable parts - \n real this is one string.\n");
}
//
////Str2 - ������������� �����, ���� ����� �����.
void Str2(void)
{
char str_1[10];  //�������� �� ���������
char str_1_2[] = {'I','s',' ','C','h','a','r','\0'};  //������ ��������
char str_2[] = "Character";  // 10 byte
char str_3[] = "Primer & Primer";     // ��������� ������
char * str_4 = "Primer of string";    // ���������
char * str_5;    //�������� ���������, ������ �� ��������
char * str_6=""; //������ ������
//����� �����
int  i = 0;
//1. ��� ������ - ������ %s
printf("%s\n", str_2);
//2. ��� ������������������ �������� - ������ %c
i=0;
while ( str_2[i]!='\0')     //while (0), ������ ��������� '\0'
{
	printf("%c", str_2[i++]);
} ;
printf("\n");
//3. ��� ������ - ��� �������
puts (str_3);
////����������� �����.
//scanf_s ("%s",str_1);	// ���� ������ �� �������
//	printf("%s",str_1);
////���� ������.
//_gets(str_1);
//putchar ('\n');
//_gets(str_4);	   // ���� ������ �� <ENTER>
//puts(str_4);       // ��������� ������- ����� �� ����� �������.
}
//// ������ � ���������, ��������� ���������
//
//void Str3(void)
//{
//   char * str = "Primer";  // 7 ����
//   char * pts;             //��������� �� ������
//// ������� �����-������ �����
//   _gets (str);       // ������ ������ ������ - ������.
//   puts (str);
////  gets (pts); - ������, �.�.������ ���  pts �� ��������.
////  ������������ �������� ���������:
//   pts = str ;                 //��� ����� i = 0 ��� �������� []
//   pts += 4;                  //����� 14-� ������ ������ str
//   * pts = 0;                  //����� ����� ����� ������ (15-� ������)
//   pts = str;
//   pts++;                      //��� �������� �� ������ ������ ���������
//   pts++;                      //������ - ����� �� ������� ������.
//   pts = str;                  // ������ � ������ ������
//   while ( * pts )             // ���� �� ���������� �� ��������� ������
//   {
//	   printf("%c",*pts++);    // ������������ �������
//   };
//   printf("\n");
//   pts = str;
//   while ( * pts++ )
//   {
//	   *pts++ ='@';            // ������������ ������� � ��������� ��������
//   };
//   puts(str);
//}
//// ������ � ��������� ��������� - ����������� ������
//void Copy_Str(void)
//{
//// ����������� ����� ������ � ������.
//// �����, ����� ����� �����  ���������.
//// ����� ������ ������ ������ ���� �� ������.
//char Str1[] = "First string.";
//char *Str2  = "Second string.";
//// ������ ��������� ��������� �����:
//int i=0;
//while (Str2[i]!='\0')
//{
//   Str1[i]=Str2[i];
//   i++;
//}
////Str1[i]='\0';
//puts(Str1);
//// ��������� ��������� ��������� �����:
//char *Str3  = "Third string.";
//char *pts1, *pts3;
//pts1=Str1;
//pts3=Str3;
//while (*pts3!='\0')
//{
//   *pts1=*pts3;
//   pts1++;
//   pts3++;
//}
////*pts1='\0';
//puts(Str1);
//// ��� ����� �����
//pts1=Str1;
//pts3=Str2;
//while (  (*pts1++ = *pts3++) !='\0' );
//puts(Str1);
//// ��� ������ ������:
//// ������������� � ����� ����� ������������
//// ����� ������ ������� ��.
///*
//pts = Str1;               //���������� �� ������ �������.
//// ����������� ������ ������ � ������.
//while (*pts !='\0')
//   {
//	  *pts = *str2++;
//	  pts++;
//   }
////��������! ������ ������ ����� ���������� ���������!
//*/
//}
//
//void compress_1(char str[])
//{  int i,mid;
//			// i - ������� ���������� ��� ������
//			// ����� ������� ��������
//			// mid - ������� ���������� ��� ������.
//   i=0;
//   while (i < strlen(str)-1)  // str[i]!='\0'
//	  if ( str[i]==' ' && str[i+1]==' ')
//	  {
//	  for (mid=i; mid<strlen(str); mid++)
//		   str[mid]=str[mid+1]; 	  //������ '\0'���� ����������
//	  }
//	 else
//	 i++;     // �� else, ����� ��������� ������ �.�. ��������
//}
//
//void compress_2(char * str)
//{
//   char *ip, *mid;            // ������� ��������� ��� ������ � ��� ������.
//   ip = str;
//   while ( *ip!='\0')
//      if ( *ip==' ' && *(ip+1)==' ')       //��� ������� �����.
//	   {
//		  mid = ip;
//	      while (*mid !='\0')
//		{
//		  *mid =*(mid+1);
//		   mid++;
//		}
//	   }
//	 else
//	 ip++;
//}
//// �������, ������������ ������
//// ����� ����� ������������ ����� � ������.
//char *Found_word(char *Str)
//{
//puts (Str);
//char  *pts;
//char  *ptw_beg;
//char  *ptw_end;
//char  *ptw;
//char  *ptw_max;
//int w_len = 0;
//int w_len_max = 0;
//pts = Str;
//ptw_beg = pts;
//do
//{
//	if( (*pts == ' ') || (*pts == 0) )
//	{
//		ptw_end = pts;
//		w_len = ptw_end - ptw_beg;
//		if( w_len > w_len_max )
//		{
//			w_len_max = w_len;
//			ptw_max = ptw_beg;
//		};
//		printf("Len of word is: %d\n",w_len);
//		while ( * pts == ' ')   //������� ����� ��������
//		   ++pts;
//		ptw_beg = pts;
//	}
//} while ( * pts++ );
//
//// ��������� ������ ��� ����� ������
//char *Word=new char [w_len_max];
//char *pW=Word;
//// ����������� �����������
//for(pts = ptw_max; pts < ptw_max+w_len_max; pts++)
//   *pW++=*pts;
//*pW='\0';
//return  Word;
//}
//
//
////������ ������������� ������������ �������.
//int cou_dig (char *str)
//{  int count = 0;
//   while (*str !='\0')
//      { if (isdigit (*str) !=0 ) count++;
//	str++;
//       }
//   return count;
//}
//char *ac(char S[])
//{
//int i;
//for (i=0;S[i]!='\0';i++)
//{
//   if (S[i]>='�' && S[i]<='�')
//	   S[i]=S[i]-64;
//   else
//	 if (S[i]>='�' && S[i]<='�')
//	   S[i]=S[i]-16;
//	   else
//	   switch(S[i])
//	   {
//	   case '�':  S[i]=S[i]+72;
//	   case '�':  S[i]=S[i]-57;
//	   }
//}
//S[i]='\0';
//return S;
//}
//
//
//
//
//
//
//
//
