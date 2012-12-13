rm q1 x1 q2 q3

gcc -m32 -fno-stack-protector -ggdb -o q1 q1.c
gcc -m32 -ggdb -ldl -o x1 x1.c

gcc -m32 -ggdb -o q2 q2.c

gcc -m32 -ggdb -o q3 q3.c
