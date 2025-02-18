// Topic: STRUCTURE WITH POINTER AS A DATA MEMBER
// This file is created by Priyanshu Sharma!
#include<stdio.h>
#include<strings.h>
struct Intern_Epam
{
    char name[100];
    int *id;
    char domain[100];
};

int main(){
   struct Intern_Epam I1;
   strcpy(I1.name ,"Priyanshu Sharma");
   I1.id = (int*)malloc(sizeof(int));
   *(I1.id) = 661436;
   strcpy(I1.domain,"CPP");
   printf("Below are the details of Intern \n name : %s\n id : %d\n domain : %s\n",I1.name,*(I1.id),I1.domain);
   return 0;
}
// Implemented by Priyanshu Sharma @ 18 feb 2025!