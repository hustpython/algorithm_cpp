#include <stdio.h>
#define LENGTH(array)( (int)(sizeof(array)/sizeof(array[0])) )

/*
problem :
  s e n d
+ m o r e
---------
m o n e y
mapping:
s e n d m o r y
0 1 2 3 4 5 6 7
*/

int LINE1[] = { 0, 1, 2, 3 };
int LINE2[] = { 4, 5, 6, 1 };
int RESULT[] = { 4, 5, 2, 1, 7 };
int values[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int k=0;
int test_proposal() {
    int number1 = 0, number2 = 0, result = 0, i, l;
    /* We refuse number starting with 0 */
    if ((values[LINE1[0]] == 0) || (values[LINE2[0]] == 0) || (values[RESULT[0]] == 0)) {
        return 0;
    }
    for(i=0,l=LENGTH(LINE1); i<l; ++i) number1 = number1*10 + values[LINE1[i]];
    for(i=0,l=LENGTH(LINE2); i<l; ++i) number2 = number2*10 + values[LINE2[i]];
    for(i=0,l=LENGTH(RESULT);i<l; ++i) result = result*10 + values[RESULT[i]];
    k++;
    i = (number1 + number2) == result;
    if(i){
        printf("%d\n",k);
        printf("Solution found: \n   %4d \n+  %4d \n= %5d", number1, number2, result);
    }
    return i;
}

int free_digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int free_digits_count = 10;

int make_proposal(int varID) {
    int i, tmp;
    for (i = 0;  i < free_digits_count; ++i) {
        tmp = free_digits[i];
        values[varID] = tmp;

        if(varID+1 < LENGTH(values)) {
            //Swap, decrease
            free_digits_count--;
            free_digits[i] = free_digits[free_digits_count];
            free_digits[free_digits_count] = tmp;

            if(make_proposal(varID+1)) return 1;
            //Swap, increase
            free_digits[free_digits_count] = free_digits[i];
            free_digits[i] = tmp;
            free_digits_count++;
        }else{
            if(test_proposal()) return 1;
        }
    }
    return 0;
}

int main() {
    int found = make_proposal(0);
    if (!found){
        printf("No solution found:\n");
    }
}