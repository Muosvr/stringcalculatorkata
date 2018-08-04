// WRITE HERE IF YOU'RE WORKING ON THIS!

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

void testSingleDigit(void);
void testEmptyStr(void);
void testMultipleDigits(void);
int strCalc(char *input);


int main(void)
{
    testEmptyStr();
    testSingleDigit();
    testMultipleDigits();
}

int strCalc(char *input){
    if (!strcmp("", input))
    {
        return 0;
    }

    int strtoint = 0;
    // int powerCounter = 0;
    for(int i = strlen(input); i>0; i--){

        strtoint += (input[i]-'0')*pow(10,powerCounter++);
    }

    printf("string to int: %i\n", strtoint);
    return strtoint;
}

void testEmptyStr(void)
{
    char *input = "";
    assert(strCalc(input) == 0 && "An empty string should return 0");
}

void testSingleDigit(void)
{
    char *input = "1";
    assert(strCalc(input) == 1 && "A single digit should return that same number");
}

void testMultipleDigits(void)
{
    // printf("strCalc('10') = %i", strCalc("10"));
    char *input = "10";
    assert(strCalc(input) == 10 && "multiple digits should return that same number");
}