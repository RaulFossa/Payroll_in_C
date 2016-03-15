/*
** This is a program written in C.
** creates a payroll earnings statement for the sales force at
** Spaceley Space Sprockets. All employees are on a straight
** commission basis of 12.5% of sales. Each month, they also
** receive a bonus that varies depending upon the profit for
** the month and their length of service. The sales manager,
** Cosmo Spaceley, calculates the bonus separately and enters
** it with the salesperson’s total sales for the month. This
** program also to calculates the withholding taxes and retirement
** contribution for the month based on the following rates:

   a. 25% Federal withholding
   b. 10% State withholding
   c. 8% Retirement contribution
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes
void read_data   (float *monthly_sales, float *bonus_sales);

void results_pay (float *gross_pay, float *federal_tax, float *state_tax,
                  float *retirement, float *net_pay, float monthly_sales,
                  float bonus_amount);

float withholding (float gross_pay, float fed, float state);

void earnings    (float sales_float, float bonus_float, float gross_pay,
                  float federal_tax, float state_tax, float retirement,
                  float net_pay);

int main (void)
{
    //Local Variable Declarations.
    //Each of these variables will store a value.
    float monthly_sales; //stores the monthly sales value
    float bonus_amount;  //stores the monthly bonus value
    float gross_pay;     //stores the gross pay value
    float federal_tax;   //stores the federal tax value
    float state_tax;     //stores the state tax value
    float retirement;    //stores the retirement value
    float net_pay;       //stores the net_pay value

    //FUNCTION CALLS
    //Read data function call
    read_data (&monthly_sales, &bonus_amount);

    //Net pay function call
    results_pay (&gross_pay, &federal_tax, &state_tax,
                 &retirement, &net_pay, monthly_sales, bonus_amount);

    //Print earnings statement function call
    earnings (monthly_sales, bonus_amount, gross_pay,
              federal_tax, state_tax, retirement,
              net_pay);

    return 0;
}//main

//FUNCTIONS**********************
//Read Data from Keyboard Function
//This function uses Upward Communication with the calling function
void read_data (float *monthly_sales, float *bonus_amount)
{
    //User prompts!
    //Prompts the user for the monthly sales $$$$
    printf("Enter monthly sales: ");
    scanf("%f", monthly_sales);
    //Prompts the user for the bonus amount
    printf("Enter bonus amount:  ");
    scanf("%f", bonus_amount);
    printf("\n\n");

    return;
}//read_data

//Net Pay Function
//The Parameters are passed by value and also by address
void results_pay (float *gross_pay, float *federal_tax, float *state_tax,
                  float *retirement, float *net_pay, float monthly_sales,
                  float bonus_amount)
{
    //Named Constants
    const float COMMISSION = 12.5;
    const float FEDERAL    = 25;
    const float STATE      = 10;
    const float RETIREMENT = 8;

    *gross_pay = (((monthly_sales * COMMISSION) / 100) + bonus_amount);
                                                    // ^ adds bonus to sales
    *federal_tax = (*gross_pay * FEDERAL) / 100;

    *state_tax = (*gross_pay * STATE) / 100;

    *retirement = (*gross_pay * RETIREMENT) / 100;

    *net_pay = *gross_pay - withholding (*gross_pay, FEDERAL, STATE) - *retirement;
                             // ^ Calls Withholding function
    return;
}//results_pay

//Calculate Withholding Function
//Takes parameters passed by value only and returns a value
float withholding (float gross_pay, float fed, float state)
{
    //Local Declarations
    float federal_tax;
    float state_tax;

    //Statements
    federal_tax = (gross_pay * fed) / 100;
    state_tax = (gross_pay * state) / 100;

    return federal_tax + state_tax;
}//withholding

//Print Earning Statement Function
//Takes parameters passed by value only and returns a void
void earnings (float sales_float, float bonus_float, float gross_pay,
               float federal_tax, float state_tax, float retirement,
               float net_pay)
{
    //Output Earning Statement
    //Spaceley Space Sprockets
    printf("Spaceley Space Sprockets \nEarning Statement:\n\n");

    //Total Sales Output
    printf("Total sales: %11.2f\n", sales_float);

    //Bonus Amount Output
    printf("Bonus amount: %10.2f\n\n", bonus_float);

    //Gross Sales Output
    printf("Gross pay: %13.2f\n", gross_pay);

    //Federal Tax Output
    printf("Federal tax: %11.2f\n", federal_tax);

    //State Tax Output
    printf("State tax: %13.2f\n", state_tax);

    //Retirement Output
    printf("Retirement: %12.2f\n", retirement);
    printf("------------------------\n");//<<<Formatted Line

    //Net Pay Output
    printf("Net Pay: %15.2f\n", net_pay);
    printf("========================\n\n");//<<<Formatted Line>

    return;
}//earnings
