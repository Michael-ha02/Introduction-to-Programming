// Michael Ha
// NID: ha272078
// Homework 5 “homework5.c”
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void PrintDeptPayrollRecords(char* dept_name);
void SaveDeptPayrollRecordsToFile(char* dept_name, char* file_name);

struct payroll {
    unsigned long long int internal_id;
    char first_name[50];
    char last_name[50];
    char department[100];
    unsigned char dob_day;
    unsigned char dob_month;
    unsigned short dob_year;
    double monthly_salary;
};

#define MAX_PAY_RECS_NO 10000
struct payroll pay_recs[MAX_PAY_RECS_NO];
size_t pay_recs_no;

int main()
{
    // test 10 case
    pay_recs_no = 10;

    pay_recs[0]. internal_id = 1000;
    strcpy(pay_recs[0]. first_name, "Michael");
    strcpy(pay_recs[0]. last_name, "Jackson");
    strcpy(pay_recs[0]. department, "HR");
    pay_recs[0]. dob_day = 1;
    pay_recs[0]. dob_month = 3;
    pay_recs[0]. dob_year = 2002;
    pay_recs[0]. monthly_salary = 15000;

    pay_recs[1]. internal_id = 2000;
    strcpy(pay_recs[1]. first_name, "Emily");
    strcpy(pay_recs[1]. last_name, "Rank");
    strcpy(pay_recs[1]. department, "Marketing");
    pay_recs[1]. dob_day = 2;
    pay_recs[1]. dob_month = 6;
    pay_recs[1]. dob_year = 2002;
    pay_recs[1]. monthly_salary = 2000;

    pay_recs[2]. internal_id = 333;
    strcpy(pay_recs[2]. first_name, "Alex");
    strcpy(pay_recs[2]. last_name, "Ha");
    strcpy(pay_recs[2]. department, "HR");
    pay_recs[2]. dob_day = 3;
    pay_recs[2]. dob_month = 4;
    pay_recs[2]. dob_year = 2003;
    pay_recs[2]. monthly_salary = 3300;

    pay_recs[3]. internal_id = 444;
    strcpy(pay_recs[3]. first_name, "David");
    strcpy(pay_recs[3]. last_name, "Maclein");
    strcpy(pay_recs[3]. department, "Engineering");
    pay_recs[3]. dob_day = 4;
    pay_recs[3]. dob_month = 4;
    pay_recs[3]. dob_year = 2004;
    pay_recs[3]. monthly_salary = 4000;

    pay_recs[4]. internal_id = 555;
    strcpy(pay_recs[4]. first_name, "Brandon");
    strcpy(pay_recs[4]. last_name, "Carvel");
    strcpy(pay_recs[4]. department, "Marketing");
    pay_recs[4]. dob_day = 5;
    pay_recs[4]. dob_month = 5;
    pay_recs[4]. dob_year = 2005;
    pay_recs[4]. monthly_salary = 5000;
    pay_recs[5]. internal_id = 666;

    strcpy(pay_recs[5]. first_name, "Taylor");
    strcpy(pay_recs[5]. last_name, "Swift");
    strcpy(pay_recs[5]. department, "HR");
    pay_recs[5]. dob_day = 6;
    pay_recs[5]. dob_month = 6;
    pay_recs[5]. dob_year = 2006;
    pay_recs[5]. monthly_salary = 6000;

    pay_recs[6]. internal_id = 777;
    strcpy(pay_recs[6]. first_name, "Lady");
    strcpy(pay_recs[6]. last_name, "Gaga");
    strcpy(pay_recs[6]. department, "Engineering");
    pay_recs[6]. dob_day = 7;
    pay_recs[6]. dob_month = 7;
    pay_recs[6]. dob_year = 2007;
    pay_recs[6]. monthly_salary = 7000;

    pay_recs[7]. internal_id = 888;
    strcpy(pay_recs[7]. first_name, "Huyen");
    strcpy(pay_recs[7]. last_name, "Chip");
    strcpy(pay_recs[7]. department, "Marketing");
    pay_recs[7]. dob_day = 8;
    pay_recs[7]. dob_month = 8;
    pay_recs[7]. dob_year = 2008;
    pay_recs[7]. monthly_salary = 8000;

    pay_recs[8]. internal_id = 999;
    strcpy(pay_recs[8]. first_name, "Philips");
    strcpy(pay_recs[8]. last_name, "Le");
    strcpy(pay_recs[8]. department, "Engineering");
    pay_recs[8]. dob_day = 9;
    pay_recs[8]. dob_month = 9;
    pay_recs[8]. dob_year = 2009;
    pay_recs[8]. monthly_salary = 9000;

    pay_recs[9]. internal_id = 1090;
    strcpy(pay_recs[9]. first_name, "Obama");
    strcpy(pay_recs[9]. last_name, "Barack");
    strcpy(pay_recs[9]. department, "HR");
    pay_recs[9]. dob_day = 10;
    pay_recs[9]. dob_month = 11;
    pay_recs[9]. dob_year = 2003;
    pay_recs[9]. monthly_salary = 12000;

    //test case exist
    PrintDeptPayrollRecords("Engineering");
    printf("\n");
    //test case not exist
    PrintDeptPayrollRecords("Design");

    char filename[100];
    printf("Enter a file name: ");
    scanf("%s",filename);
    char department[100];
    printf("Enter a department name: ");
    scanf("%s",department);
    //test savefile function
    SaveDeptPayrollRecordsToFile(department,filename);



    return 0;


}

void PrintDeptPayrollRecords(char* dept_name)
{
    int count = 0, flag = 0,i;
    double total_Salary = 0.0;
    //check if the department has existed in the array
    for(i = 0;i < pay_recs_no; i++)
    {
        //check the string is exist or not
        if (strcmp(dept_name, pay_recs[i].department) == 0)
        {
            flag = 1;
            break; //if it exist, break
        }
    }

    if (flag == 1) //if the department name is correct, print it
    {
        printf("Employees of the %s Department:\n",dept_name);
        printf("Last Name \t First Name \t Date of Birth \t Monthly Salary \n");
        printf("---------------------------------------------------------- \n");
        //loop though the elements
        for (i = 0; i < pay_recs_no; i++){
            if(strcmp(dept_name,pay_recs[i].department) == 0){
                printf("%s        \t",pay_recs[i]. last_name);
                printf("%s       \t",pay_recs[i]. first_name);
                printf("%d,%d,%d \t",pay_recs[i].dob_month,pay_recs[i].dob_day,pay_recs[i]. dob_year);
                printf("%.2f \n",pay_recs[i].monthly_salary);
                count ++; //check how many people in the department
                total_Salary = total_Salary + pay_recs[i].monthly_salary;
            }

        }
        printf("Total Number of Employees in the Department: %d\n",count);
        printf("Aggregated Salary of the Department: %.3f",total_Salary);

    }
    else
        printf("Department %s has no payroll records.\n",dept_name);
}

void SaveDeptPayrollRecordsToFile(char* dept_name, char* file_name)
{
    //check the file has a problem or not
    if (file_name == NULL || strlen(file_name) == 0)
    {
        printf("ERROR: There is nothing to write to the file!\n");
        return;
    }
    FILE *fp; //open a file
    char *filename = file_name;
    fp = fopen(filename,"w");
    //the same idea as the function above
    int count = 0, flag = 0,i;
    double total_Salary = 0.0;
    //check if the department has existed in the array
    for(i = 0;i < pay_recs_no; i++) {
        if (strcmp(dept_name, pay_recs[i].department) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        fprintf(fp,"Employees of the %s Department:\n",dept_name);
        fprintf(fp,"Last Name \t First Name \t Date of Birth \t Monthly Salary \n");
        fprintf(fp,"---------------------------------------------------------- \n");
        //loop as the same first function
        for (i = 0; i < pay_recs_no; i++){
            if(strcmp(dept_name,pay_recs[i].department) == 0){
                fprintf(fp,"%s        \t",pay_recs[i]. last_name);
                fprintf(fp,"%s       \t",pay_recs[i]. first_name);
                fprintf(fp,"%d,%d,%d \t",pay_recs[i].dob_month,pay_recs[i].dob_day,pay_recs[i]. dob_year);
                fprintf(fp,"%.2f \n",pay_recs[i].monthly_salary);
                count ++;
                total_Salary = total_Salary + pay_recs[i].monthly_salary;
            }

        }
        fprintf(fp,"Total Number of Employees in the Department:%d\n",count);
        fprintf(fp,"Aggregated Salary of the Department:%.3f",total_Salary);

    }
    else
        fprintf(fp,"Department %s has no payroll records.\n",dept_name);
    fclose(fp); //close file
}

