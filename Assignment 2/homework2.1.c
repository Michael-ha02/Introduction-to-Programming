// Michael Ha
// NID: ha272078
// Homework 2“homework2.c”
// COP 3223CSection 0V06, Spring2021


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

_Bool IsDecimalInteger(char str[]);
char GetSortingOrder(double arr[], size_t arr_size);
void RemoveExtraSpaces(char txt[]);


int main()
{   
    //check each function
    char a[] = "1-23";
    if(IsDecimalInteger(a) == 1)
        printf("Is Descimal\n");
    else   
        printf("Not Descimal\n");
    
    double b[] = {1,2,3,-5};
    printf("%d \n",GetSortingOrder(b,4));
    char c[] = "Hello   World  !";
    RemoveExtraSpaces(c);
    printf("%s\n",c);
    return 0;
}

_Bool IsDecimalInteger(char str[])
{
    //check the first character can be negative or not
    if ((str[0] != 45) &&! ((str[0] >= 48) && (str[0] <=57))) return 0;
    //if str[i] from 0-9(using ASCII Table)
    for (unsigned int i = 1 ;i < strlen(str); i++)
    {
        if ((str[i] < 48) || (str[i] > 57)) return 0;
    }
    return 1;
}

char GetSortingOrder(double arr[], size_t arr_size)
{   
    //check if string is empty or not
    
    if (arr_size == 0) return -1;
    // if arr_size == 1, return 3;
    if(arr_size == 1) return 3;

    int status; //create a status variable to check the status of the array
    //in order to sort one time, we need to check the status of begining
    if(arr[0]< arr[1]) status = 1;
    else if (arr[0] > arr[1]) status = 2;
    else if (arr[0] == arr[1]) status = 3;
    
    //switch status to each case when something happen
    for (unsigned int i = 1; i < arr_size - 1; i++) //fix 
    {   
        
        if (status == 1)
            if (arr[i] > arr[i+1]) return 0; //check if it is wrong for the status = 1
        if (status == 2)
            if (arr[i] < arr[i+1]) return 0; ////check if it is wrong for the status = 2
        if (status == 3) // check if it is wrong for the status = 3
        {
            if (arr[i] > arr[i+1]) status = 2;
            else if (arr[i] < arr[i+1]) status = 1;
        }  
    }
    //return 0,1,2,3 and -1 for each case
    if(status == 1) return 1;
    else if(status == 2) return 2;
    else if(status == 3) return 3;
    return 0;
}

void RemoveExtraSpaces(char txt[])
{
	int i,j;
	for(i = j = 0; txt[i]; i++) //create j variable to count the non-space location
        //add next character if it is not a space or if the left character is not a space
		if ((txt[i] != ' ') || (i > 0 && txt[i-1] != ' '))
			txt[j++] = txt[i];
    // if the last character is space, remove it
    if (j-1 > 0 && txt[j-1] == ' ')
        txt[j-1] = '\0'; 
    else
	    txt[j] = '\0'; //make sure the last character is "\0"
}
