// Source code taken from: http://cregnec.github.io/blog/2014/11/17/picoctf-2014-writeup.html#fancy-cache
 #include <stdlib.h>
 #include <stdio.h> 
 #include <string.h>
                                                                                                                                          
 int main(){
         char *a = "123";
         char *b = "123";
         int ret = 0;
         int *memcmp_ptr, *system_ptr;
 
         ret = memcmp(a, b, sizeof(a));
         /* compile the program, repalce this value and recompile it.*/
         memcmp_ptr = (int *)0x0804a004;
         printf("memcmp addr is 0x%08x\n", *memcmp_ptr);
 
         ret = system("foo");
         /* compile the program, repalce this value and recompile it.*/
         system_ptr = (int *)0x0804a008;
         printf("system addr is 0x%08x\n", *system_ptr);
         printf("the offset from memcmp to system is -0x%08x\n", *memcmp_ptr-*system_ptr);
 
         return 0;
 }
