#include <stdlib.h>
#include <stdio.h>


using namespace std;

void fun(char **a)
{
    //*a = *a + 1;
    printf("%s\n", *a);
}

int main()
{
    char b[]={"abcd"};
    //char *a = &b;
    //const char **c = &(a+1);
    fun((char**)&b);
    fun(&b);
    char *c = b;
    fun(&c);
}
