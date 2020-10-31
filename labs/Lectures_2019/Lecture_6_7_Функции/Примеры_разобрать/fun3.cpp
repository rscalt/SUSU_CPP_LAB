/*fun3.cpp*/
#include <stdio.h>                            /* αγ¬¬  ΰο¤  */
int sum(int);
void main (void)
{ int n;
  printf ("\n ‚Ά¥¤¨ η¨α«® α« £ ¥¬λε ");
  scanf  ("%d",&n);
  printf ("‘γ¬¬ =%d",sum(n));
}

int sum(n)
{ int s=0,i ;
  for (i = 1; i<=n; i++)
      s+=i;
  return  s;
}