//  Michael ha
//  NID: ha272078
//  Homework 1 “homework1-1.c”
//  COP 3223C Section 0V06, Spring 2021


#include <stdio.h>


//fuction SumofDigits
//takes a non-negative integer n as a parameter and returns a non-negative integer containing the sum of n’s digits
//intput: 1234 Output: 10
unsigned int SumOfDigits(unsigned int n)
{
    //create a sum variable
    
    unsigned int sumofdigit = 0; //create a sum variable
    
    while (n != 0) //using while loop to check the n!=0 after n/10
    {
        sumofdigit = sumofdigit + (n % 10); //get the remainder plus to sum
        n = n / 10;
    }
    printf("Output: %d\n",sumofdigit);
    return 0; //return the value after using a function
}

/*function PrintDivisors
takes a non-negative integer n and prints out all its divisors,
that is all numbers m between 1 and n (including those) such that n is divisible by m
input: 4. Output: 1 2 4
*/
void PrintDivisors(unsigned int n) 
{
    printf("Divisors of %d : ",n); 

    for (unsigned int a = 1; n >= a ; a++){ //using for loop to check conditional
        // if n % a == 0, it is the answer
        if (n % a == 0){
            printf("%d ",a);
        }
    }
}

/*Bonus question answer:
The faster way to count binomial coefficients is to use array to save the value of n
because the computer count the value n, it means it have already count value m(n>n)and value m-n
so we use the old value to store so the computer doesn't have to count 3 times
*/


unsigned int a[1000000]; 
unsigned int GetBinomialCoefficient(unsigned int n, unsigned int m)
{   
    a[0] = 1; //set a[0] = 1

    //find factorial 
    for(int i = 1; i <= n; i++){
        a[i] = a[i-1] * i;
    }

    return a[n]/(a[m] * a[n-m]); //return the result 
}


int main()
{
    unsigned int n = 0;
    unsigned int m = 0;
    
    //input and output SumofDigit Function
    printf("Enter n(n>0) to find Sum of Digit: ");
    scanf("%d",&n);//user input
    SumOfDigits(n);
    
    //input and output PrintDivisors Fuction
    printf("Enter n(n>0) to pint Divisor: ");
    scanf("%d", &n); //user input
    PrintDivisors(n);
    printf("\n");
    
    //input and out put getbinomialcoefficient
    printf("Enter n and m (n>m) to return Binomical Coefficient: ");
    scanf("%d %d", &n,&m);
    printf("Output: %d\n",GetBinomialCoefficient(n,m));

    return 0;
}


