cs4235-hw1
==========

Homework 1 for CS4235 Fall 2012

Build with build.sh

Question 1:
Run x1 to demonstrate a stack-based overflow against q1 (works best on my Fedora VM)

It first gets the address of system() via libc, then mallocs the length of the 
target buffer (12) plus the length of a 32-bit address (4). It then 
concatenates the overflow string and the address to form the first argument for
the q1 program. The string overflows the buffer and replaces the file pointer 
with the address of system. The fptr call then feeds the second argument to 
system instead of myprint.

Question 2:

Run q2 to demonstrate a heap overflow.
The program calculates the difference in memory location between two malloc'd char buffers.
It fills the lower buffer with "A" and then overflows the higher buffer to
overwrite the first 4 bytes of the lower buffer with the address of system().
It then casts those first 4 bytes to a function pointer in a hideous perversion
of all that is good in this world. Calling that pointer with "/bin/sh" gives a shell.

Question 3:
Run q3 to demonstrate an integer overflow.

The maximum unsigned 32-bit integer is a negative number in two's complement. 
Thus it is possible to construct a number that appears positive to unsigned
checks but appears negative in applications such as array indicies. In this case,
foo.buf[0xFFFFFFFF] is equivalent to foo.buf[-1], which addresses memory one size
unit prior to the start of the array. Since it's an int array (size 4), this places
our pointer at the correct location to overwrite fptr.

