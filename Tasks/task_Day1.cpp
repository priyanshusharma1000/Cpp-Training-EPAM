/* task_Day1.cpp : This file contains all the codes that is assigned during the first day of training */

/* All string operations */
#include <iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string str, int s, int e) {
    while (s <= e) {
        if (str[s] != str[e]) {
            return false;
        }
        s++;
        e--;

    }
    return true;
}

void convertouppercase(string& str) {
    int i = 0;
    while (i < str.length()) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            str[i] = ch - 'a' + 'A';
        }
        i++;
    }
}

bool issubstring(string str1, string str2) {
    for (int i = 0;i < str1.length();i++) {
        for (int j = i + 1;j <= str1.length();j++) {
            if (str1.substr(i, j - i) == str2)
                return true;
        }
    }
    return false;
}

int main()
{
    // intialization of string
    string str = "c++ intern at Epam";

    // different operations we can perform on string 

    // 1. calculate its length

  
    int length = 0;
    for (int i = 0;str[i] != '\0';i++) {
        length++;
    }

    cout << "length of string" << str << "is :" << length << endl;

    // we have direct function which can calculate the length of string 

    int func_through_length = str.length();
    cout << "length calculated through function is :" << func_through_length << endl;



    cout << endl << endl;
    // 2) reverse a string 
    string st = "Epam";
    cout << "string before swapping is :" << st << endl;
    int s = 0;
    int e = st.length() - 1;
    while (s <= e) {
        swap(st[s++], st[e--]);
    }
    cout << "string after swapping is :" << st << endl;

    // we can do the same implementation with c++ stl reverse function
    cout << endl << endl;
    st = "Epam";
    cout << "string before swapping is :" << st << endl;
    reverse(st.begin(), st.end());
    cout << "string after swapping is :" << st << endl;

    cout << endl << endl;
    //3) to check whether the string is palindrom or not 
    string str1 = "santhosh";
    string str2 = "nayan";

   
    if (isPalindrome(str1, 0, str1.length() - 1))
    {
        cout << str1 << " is a palindrome" << endl;
    }
    else {
        cout << str1 << " is not a palindrome" << endl;
    }

    if (isPalindrome(str2, 0, str2.length() - 1))
    {
        cout << str2 << " is a palindrome" << endl;
    }
    else {
        cout << str2 << " is not a palindrome" << endl;
    }


    //4) to convert all the lowercase character of string to uppercase 
    cout << endl << endl;
    string str3 = "EpAm";
    cout << "before conversion string is :" << str3 << endl;
    convertouppercase(str3);
    cout << "after conversion string is :" << str3 << endl;

    cout << endl << endl;
    // 5) to find whether a string is substring of another string 
    string str4 = "c++ intern at Epam";
    string str5 = "intern";
    string str6 = "Sattva";

    if (issubstring(str4, str5))
    {
        cout << str5 << "  is substring of :" << str4 << endl;
    }
    else {
        cout << str5 << "  is not substring of :" << str4 << endl;
    }
    
    if (issubstring(str4, str6))
    {
        cout << str6 << "  is substring of :" << str4 << endl;
    }
    else {
        cout << str6 << "  is not substring of :" << str4 << endl;
    }

    return 0;

}

// created by priyanshu sharma  ......!    