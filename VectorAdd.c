#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cycle.h"
// riscv32-linux-gnu-gcc -S VectorAdd.c -O3  -fopt-info
// aarch64-linux-gnu-gcc -S VectorAdd.c -O3  -fopt-info

// Static definitions to help compiler
#define VSIZE 10000
typedef  int vector_t[VSIZE];
vector_t sx, sy, sz;

// Function VaddStatic should be
// * unrolled (depending on VSIZE)
// * vectorized (depending on targer processor & compiler & optimisation option)
void VaddStatic(vector_t a, vector_t b, vector_t r)
{
  for (int i = 0; i< VSIZE; i++)
    r[i] = a[i] + b[i];
}

// Function VaddDynamic should be
// * unrolled 
// * vectorized (depending on targer processor & compiler & optimisation option)
void VaddDynamic(vector_t a, vector_t b, vector_t r, int vSize)
{
  for (int i = 0; i< vSize; i++)
    r[i] = a[i] + b[i];
}


void FillVector(vector_t a, int init, int increment, int vSize)
{
  for (int i = 0; i< vSize; i++)
    a[i] = init+i*increment;
}

void printVector (char * message, int * vector, int size, int ncolumn)
{
  printf ("%s :\n", message);
  for (int i=0; i<size; i++)
    {
      printf ("%d ", vector[i]);
      if (i % ncolumn == (ncolumn-1))
        printf ("\n");
    }
  printf("\n");
}


int main(int argc, char * argv[])
{
  int vSize;
  uint64_t ticks;

  if (argc < 2)
    {
      printf ("Give a size\n");
      exit(-1);
    }

  // Static data set
  FillVector(sx,     0,  1, VSIZE);
  FillVector(sy, VSIZE, -1, VSIZE);
  ticks = getticks();
  VaddStatic(sx, sy, sz);
  ticks = getticks() - ticks;
  printf ("        %10s %10s\n", "size" , "ticks" );
  printf ("Static  %10d %10ld \n", VSIZE, ticks);
  //  printVector ("Résultat Statique", sz, VSIZE, 10);


  int * dx, *dy, *dz;   // Dynamic data set
  vSize = atoi(argv[1]);
  dx = malloc (vSize*sizeof (int));
  dy = malloc (vSize*sizeof (int));
  dz = malloc (vSize*sizeof (int));
  FillVector(dx,     0,  1, vSize);
  FillVector(dy, vSize, -1, vSize);
  ticks = getticks();
  VaddDynamic(dx, dy, dz, vSize);
  ticks = getticks() - ticks;
  printf ("Dynamic %10d %10ld\n", vSize, ticks);
  //  printVector ("Résultat Statique", dz, vSize, 10);
  return 0;
}
