#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
    char* str1 = "123";
    char* str2 = "123";
    char str3[] = "123";
    char str4[] = "123";

    if(str1 == str2){
        printf("0");
    }else{
        printf("1");
    }
    if(str3 == str4){
        printf("0");
    }else{
        printf("1");
    }
}