// Topic: Padding With Pack Of 2 pow 1
// This file is created by Priyanshu Sharma!
#include<stdio.h>
#pragma pack(2) // alignment of m/m in terms of 2 to the power1
struct St{
 char a;
 int b;
 double c;
};

int main(){
    struct St s;
    printf("%d",sizeof(s));
    /*Explaination : Here memory is allocated in terms of 2 to the power X so take each data member of struct one by one:
        char a => 1 byte but it is not multiple of 2, so it take 2 byte of m/m
        int b  => 4 byte of m/m which is a multiple of 2, so total m/m till now = 2 + 4 => 6
        double c => 8 byte of m/m which is a multiple of 2,so total m/m till now = 6 + 8 =>14

        That is why we get our answer 14 byte
        Priyanshu Sharma!
    */
    return 0;
    
}