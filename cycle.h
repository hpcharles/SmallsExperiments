// Cycle performance counter
// Extracted from cycle.h : https://github.com/FFTW/fftw3/blob/master/kernel/cycle.h

#if defined(__aarch64__) // for raspberry (should be more precise ?)
typedef uint64_t ticks;
static inline ticks getticks(void)
{
  uint64_t Rt;
  asm volatile("mrs %0,  CNTVCT_EL0" : "=r" (Rt));
  return Rt;
}
#define HAVE_TICK_COUNTER
#endif
#if (defined(__GNUC__) || defined(__ICC) || defined(__SUNPRO_C)) && defined(__x86_64__)  
typedef unsigned long long ticks;

static __inline__ ticks getticks(void)
{
     unsigned a, d;
     __asm__ __volatile__ ("rdtsc" : "=a" (a), "=d" (d));
     return ((ticks)a) | (((ticks)d) << 32);
}

#define HAVE_TICK_COUNTER
#endif

#if defined (__riscv)

/*
https://stackoverflow.com/questions/52187221/how-to-calculate-the-no-of-clock-cycles-in-riscv-clang
*/

uint64_t getticks(void)
{
    unsigned long dst;
    // output into any register, likely a0
    // regular instruction:
    asm volatile ("csrrs %0, 0xc00, x0" : "=r" (dst) );
    // regular instruction with symbolic csr and register names
    // asm volatile ("csrrs %0, cycle, zero" : "=r" (dst) );
    // pseudo-instruction:
    // asm volatile ("csrr %0, cycle" : "=r" (dst) );
    // pseudo-instruction:
    //asm volatile ("rdcycle %0" : "=r" (dst) );
    return dst;
}
#define HAVE_TICK_COUNTER
#endif



