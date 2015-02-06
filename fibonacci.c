#include <stdlib.h>
#include <sys/time.h>
#include "fibonacci.h"

/*
 * Fibonacci generator
 *
 * Generates fibonacci numbers and emits them through a DTrace probe.
 */

/*
 * Calculate the n first fibonacci numbers,
 * emit calculation time and/or numbers through
 * the probes.
 */
void
calc_fib(int n)
{
  unsigned long a, b, x;
  struct timeval t;
  long t1, t2;

  gettimeofday(&t, NULL);
  t1= (long)(t.tv_sec*1000 + t.tv_usec);

  a= b= 1;
  for( ; n > 0; n-- )
    {
      FIBONACCI_NUMBER(a);
      x= a+b;
      a= b;
      b= x;
    }

  gettimeofday(&t, NULL);
  t2= (long)(t.tv_sec*1000 + t.tv_usec);
  FIBONACCI_TIME(t2 - t1);
}  


/*
 * Loop forever and do the work if probes are enabled.
 */
int
main(int argc, char ** argv)
{
  unsigned short n= atoi(argv[1]);
  
  while(1)
    {
      if( FIBONACCI_NUMBER_ENABLED() || FIBONACCI_TIME_ENABLED() )
	calc_fib(n);

      FIBONACCI_ARG(argv[1]);
      sleep(1);
    }
}
