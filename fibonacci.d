/*
 * Fibonacci provider
 *
 * Probes:
 *   number: Emit the generated fibonacci number
 *   arg   : Emit the command line argument
 *
 */
provider fibonacci {
  probe number(long);
  probe arg(char *);
  probe time(int);
};
