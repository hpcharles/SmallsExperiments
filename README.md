# SmallsExperiments

This repository provide small codes which helps to experiment with compilers

## SizeOfType

* SizeOfTypes.c will print the differrent size of basic C data type

## VectorAdd

Basic question, is there a difference between vector addition, if the
vector is statically defined or dynamically defined ? 

* VectorAdd.c is a vector addition with 2 implementations :
  * Static : loop and vector are statically defined
  * Dynamic : loop and vector are dyanmically defined (via the command line)

Short answer : yes. But it depends on the architecture / compiler couple.

> gre066469:SmallExperiments/>grep "model name" /proc/cpuinfo|uniq
> model name	: 11th Gen Intel(R) Core(TM) i5-1135G7 @ 2.40GHz
> gre066469:SmallExperiments/>./VectorAdd 10000000
> Give 10000000 as dynamic size
>             size      ticks   time (s) dummy value
>  Static    10000000   43425700   0.031402   10000000
>  Dynamic   10000000   39186662   0.028347   10000000



## References:

* cycle.h Copyright (c) 2003, 2007-14 Matteo Frigo https://github.com/FFTW/fftw3/blob/master/kernel/cycle.h
