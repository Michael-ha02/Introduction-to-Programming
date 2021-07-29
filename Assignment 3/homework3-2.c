// Michael Ha
// NID: ha272078
// Homework 3 “homework3.c”
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>
#include <string.h>

unsigned long long CountWords(char text[]);
long long int fix_sorted_array(double arr[], size_t arr_size);
void BubbleSort(double a[], size_t array_size);
//testing 
int main()
{
    //test the CountWords Function
    char s[200] = "This   is a test  text!!!";
    //print the output
    printf("Count words: :%llu\n", CountWords(s));

    //check fix_sorted_array function
    printf("The Array is:");
    double a[] = {-1,23,70.39,500,1000,7000,23520,10};
    //printf the original array
    for (int i = 0; i < 8; i++)
        printf("%.2f, ", a[i]);

    //find position outlier of the array
    printf("\nPosition of the outlier: %lli",fix_sorted_array(a,8));
    //print the array after sorting
    printf("\nAfter array sorting: ");
    for (int i = 0; i < 8; i++)
        printf("%.2f, ", a[i]);
    printf("\n");
    return 0;
}

unsigned long long CountWords(char text[])
{
    int status = 0;
    unsigned long long  count = 0;
    int i = 0;
    //loop all the value in the string
    while(text[i])
    {
        //check if the first character is character or not
        if(text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == '!' || text[i] == '?' || text[i] == ':')
            status = 0;
        //if the text[i] == character and the status is 0(it means that the text[i] is a character,we change the status == 1 and increment the count = count + 1

        else if(status == 0)
        {
            status = 1;
            count++;
        }
        //move to te next character in order to check
        i++;
    }
    //return value
    return count;
}

//create a BubbleSort Function to sort the array
void BubbleSort(double a[], size_t array_size)

{
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            //if the next element is smaller than the element, swap them
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

long long int fix_sorted_array(double arr[], size_t arr_size)
{
    //if array is empty, return -1;
    if(arr_size == 0) return -1;
    
    long long int outlier_position = -1;
    
    //create a variable to check status
    int status = 0, status2 = 0;
    
    //loop in an array
    for (int i = 0; i < arr_size; i++)
    {
        //if the array doesn't have any outlier position, status == 1 && status2 == 0
        if(arr[i] < arr[i+1] && i < arr_size -1)
        {
            status = 1;
        }
        
        //if the array does have a outlier position, status2 == 1
        //assign outlier_position = i(the index outlier)
        if(i < arr_size - 1 && arr[i] > arr[i+1])
        {
            status2 = 1;
            outlier_position = i;

        }
        
        //if the last element is bigger than before
        if(i < arr_size - 1 && arr[arr_size -1] < arr[arr_size -2])
        {
            status2 = 1;
            outlier_position = i + 1;
        }
    }
    //use bubble sort to sort the array after we find the outlier position
    BubbleSort(arr,arr_size);
    //check status to return value
    if (status == 1 && status2 == 0)
        return - 1;
    else if (status == 1 && status2 == 1)
        return outlier_position;
    //using bubble sort to sort the function after finding the outlier_position
    return 0;
    //return the old position of outlier
}
