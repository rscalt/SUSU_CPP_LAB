/*fun3.cpp*/
#include <stdio.h>                            /* �㬬� �鸞 */
int sum(int);
void main (void)
{ int n;
  printf ("\n ����� �᫮ ᫠������ ");
  scanf  ("%d",&n);
  printf ("�㬬�=%d",sum(n));
}

int sum(n)
{ int s=0,i ;
  for (i = 1; i<=n; i++)
      s+=i;
  return  s;
}