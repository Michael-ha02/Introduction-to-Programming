// Michael Ha
// NID: ha272078
// Homework 4 “homework4.c”
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>
#include <string.h>


#define MAX_STR_LEN 1000
void reverseStr(char* str);
_Bool SumCIntegers(char* cx, char* cy, char* res);
_Bool MultiplyCIntegers(char* cx, char* cy, char* res);
void GetFactorial(unsigned short n, char* res);
int main()
{
    char res[MAX_STR_LEN];
    //test 10,20,50 as requirement
    GetFactorial(10,res);
    printf("%s\n",res);

    GetFactorial(20,res);
    printf("%s\n",res);

    GetFactorial(50,res);
    printf("%s\n",res);

    return 0;
}

/*  step 1: reverse the variable to expand to the right
    step 2: loop to multiple them
    step 3: after loop, using SumCInteger function to calculate
    step 4: check variable
*/
//this function helps me to convert integer to string
void reverseStr(char* str)
{
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++)
    {
        char ch = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = ch;
    }
}
_Bool SumCIntegers(char* cx, char* cy, char* res)
{
    size_t len_cx = strlen(cx), len_cy = strlen(cy);
    size_t length;
    unsigned int cur_sum = 0, cur_remainder = 0;
    long long int i = 0;

    if (len_cx < len_cy) //it means that we need to add zero before cx
    {
        //copy cx to the back
        for (i = len_cx; i >= 0; i--)
            cx[i + (len_cy -len_cx)] = cx[i];

        for (i = 0; i < len_cy - len_cx; i++)
            cx[i] = '0';
    }
    else if (len_cy < len_cx)
    {
        for (i = len_cy; i >= 0; i--)
            cy[i + (len_cx - len_cy)] = cy[i];
        for (i = 0; i < len_cx - len_cy; i++)
            cy[i] = '0';
    }
    //choose the maximun len to use
    length = (len_cx > len_cy ? len_cx : len_cy);
    if (length == 0)
    {
        res[0] = '\0';
        return 1;
    }
    res[length] = '\0';
    for (i = length - 1; i >= 0; i--)
    {
        //check if the position is from 0-9
        if (cx[i] < '0' || cx[i] > '9' || cy[i] < '0' || cy[i] > '9')
        {
            res[0] = '\0';
            return 0;  // Error: at least one of the summands is not a non-negative integer
        }
        //count sum
        cur_sum = cx[i] + cy[i] - '0' -'0' + cur_remainder;
        cur_remainder = cur_sum / 10;
        res[i] = cur_sum % 10 + '0';
    } // for i
    if (cur_remainder == 1)
    {
        if (length == MAX_STR_LEN) // Overflow
        {
            res[0] = '\0';
            return 0;
        }
        for (i = length; i >= 0; i--)
            res[i+1] = res[i];
        res[0] = '1';
    }
    return 1;
}
_Bool MultiplyCIntegers(char* cx, char* cy, char* res)
{

    size_t len_cx = strlen(cx), len_cy = strlen(cy);
    int i = 0, j = 0;

    // track variable at the end of the loop
    char tmp[MAX_STR_LEN] = "";

    res[0] = '0';
    res[1] = '\0';
    //if the cx or cy is 0, the answer is 0;
    if (strcmp(cx, "0") == 0 || strcmp(cy, "0") == 0)
    {
        res[0] = '0';
        res[1] = '\0';
        return 1;
    }

    //reverse string to expand the array
    //we can not expand the array to the left, so reverse it and expand it to the right
    reverseStr(cx);
    reverseStr(cy);

    int carry,mul,sum;
    //outer loop
    for(i = 0; i < len_cx; i++)
    {
        carry = 0;
        //inner loop to multiple
        for (j = 0; j < len_cy; j++) {
            mul = (cx[i] - '0') * (cy[j] - '0') + carry;
            sum = mul % 10;
            carry = mul / 10;
            tmp[j] = sum + '0'; //count the result in reverse
        }
        //add the last value to tmp
        if (carry > 0) {
            tmp[j] = carry + '0';
            j = j + 1;
        }
        //define the last index = \0
        tmp[j] = '\0';

        reverseStr(tmp);

        //we need to add '0' to plus it after reverse
        for (int a = 0; a < i; a++)
            tmp[a + j] = '0'; //the next value will need 0 as the example of SumInterger in lecture

        //redefine the last index = \0
        tmp[j + i] = '\0';
        //using the fucntion SumCIntergers to check if it can be sum after we analyze
        //if it can be add and not have any problems, it is okay!
        if (SumCIntegers(res, tmp, res) == 0)
        {
            res[0] = '\0';
            return 0;
        }
        //reset
        *tmp = '\0';
    }
    //if nothing wrong, return 1;
    return 1;
}
/*
 * Step 1: using for loop to loop until n;
 * Step 2: Using MultiplyCInteger to calculate them
 * Step 3: Update the count and res using SumCIntegers.
 */

void GetFactorial(unsigned short n, char* res)
{
    int i;
    char count[MAX_STR_LEN] = "1";
    char plus_one[MAX_STR_LEN] = "1";
    char temp[MAX_STR_LEN] = "1";
    strcpy(res,"1"); //swap res begin with 1;
    //loop the factorial number
    for (i = 1; i <= n; i++)
    {
        //using MultiplyCIntegers function to count
        MultiplyCIntegers(res,count,temp);
        strcpy(res,temp); //swap temp and res
        //update the res and count variable
        SumCIntegers(count,plus_one,count);
    }
}










