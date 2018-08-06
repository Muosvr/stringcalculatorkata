// WRITE HERE IF YOU'RE WORKING ON THIS! Jason: finished #3 comma delimited sum
//Challenge link http://www.peterprovost.org/blog/2012/05/02/kata-the-only-way-to-learn-tdd/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

void testSingleDigit(void);
void testEmptyStr(void);
void testMultipleDigits(void);
void testCommaDelimitedSum(void);

int strCalc(char *input);


int main(void)
{
    testEmptyStr();
    testSingleDigit();
    testMultipleDigits();
    testCommaDelimitedSum();
}

int strCalc(char *input){
    if (!strcmp("", input))
    {
        return 0;
    }
    // printf("String: %s\n", input);

    int result = 0;
    int powerIndex = 0;
    int digitPointer = strlen(input)-1;
    // printf("Power start index : %d\n", powerIndex);

    for (int i = 0; i<strlen(input); i++)
    {

        if(input[digitPointer]==','){
            powerIndex = 0; //restart powetIndex count
            // printf("Comma found\n");
            digitPointer--; //cannot be put in if statement
        }else{
            // printf("digitPointer: %d, powerIndex: %d\n", digitPointer, powerIndex);
            result += (input[digitPointer--]-'0')*pow(10,powerIndex++); //add each digit to the sum according to its position
            // printf("result: %d\n", result);
        }
    }

    // printf("Final result : %i\n", result);
    return result;
}

void testEmptyStr(void)
{
    char *input = "";
    assert(strCalc(input) == 0 && "An empty string should return 0");
}

void testSingleDigit(void)
{
    char *input = "6";
    assert(strCalc(input) == 6 && "A single digit should return that same number");
}

void testMultipleDigits(void)
{
    // printf("strCalc('10') = %i", strCalc("10"));
    char *input = "526";
    assert(strCalc(input) == 526 && "multiple digits should return that same number");
}

void testCommaDelimitedSum(void){
    char *input = "53,796";
    assert(strCalc(input) == 849 && "Two numbers delimited by comma should return sum");
}