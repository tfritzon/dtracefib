# dtracefib
Generate fibonacci numbers and emit them from a DTrace probe. A silly example of building an in-application DTrace provider.

Running
=======

To run, give the number of fibonacci numbers to calculate (n):

    $ ./fibonacci 50 & 

To get the numbers, using dtrace:

    $ sudo dtrace -n 'fibonacci::number { printf("%d", arg0) }'

To get the time, in ms, it takes to calculate the numbers:

    $ sudo dtrace -n 'fibonacci::time { printf("%d", arg0) }'

To get the command line argument:

    $ sudo dtrace -n 'fibonacci::arg { printf("%s", copyinstr(arg0)) }'
