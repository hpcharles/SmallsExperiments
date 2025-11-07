#include <stdio.h>

#define P(TYPE)   printf("%15s : %3d bytes %3d bits \n", \
                         #TYPE, (int) sizeof (TYPE),	(int) (8*sizeof (TYPE)));
int main(int argc, char * argv[])
{
  P(char);
  P(unsigned char)

  P(short);
  P(unsigned short);

  P(int);
  P(unsigned int);
  P(long int);

  P(long);
  P(unsigned long);
  P(long long);

  P(float);

  P(double);
  P(long double);

  P(char *);
  P(__int128);

  return 0;
}
