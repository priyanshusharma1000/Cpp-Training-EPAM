//Topic : Add two large numbers
//This file is created by Priyanshu sharma


#include <stdio.h>
#include <string.h>
void string_add(const char *num1, const char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int k = 0;
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry; 
        result[k++] = (sum % 10) + '0'; 
        carry = sum / 10;
    }
    result[k] = '\0'; 
    
    // Reverse the result
    for (int i = 0; i < k / 2; i++) {
        char temp = result[i];
        result[i] = result[k - 1 - i];
        result[k - 1 - i] = temp;
    }
}

int main() {
    char num1[1024], num2[1024], result[1024 + 1]; 

    
    printf("Enter the first large number: ");
    scanf("%s", num1); 
    printf("Enter the second large number: ");
    scanf("%s", num2);

    
    string_add(num1, num2, result);

    
    printf("Sum is: %s\n", result);

    return 0;
}