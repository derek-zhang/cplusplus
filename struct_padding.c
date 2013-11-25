#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct padding_type {
    short m1;
    int m2;
} padding_type_t;

int main()
{
    padding_type_t a;
    a.m1=0;
    a.m2=0;
    padding_type_t b;

    memset(&b, 0, sizeof(b));

    if (0 == memcmp(&a, &b, sizeof(a))) {
        printf("Equal!\n");
    }
    else {
        printf("No equal!\n");
    }

    return 0;
}

/*
为什么是这样呢？其实有经验的开发都会立刻反应到，这是由于对齐造成的。
没错，就是因为struct padding_type->m1的类型是short型，而m2的类型是int型，
根据自然对齐的原则。padding_type的每个成员需要对齐到4字节。
因此编译器会在m1后面插入2个padding字节，而padding的字节的值是随机的。
也就是说a中的padding 字节的值是随机的，而b中的padding则被清零。
所以当使用memcmpy去比较这两个结构体时，返回值是不等。

除非用memset清0了才行。
*/
