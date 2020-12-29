#include <stdlib.h>
#include <stdio.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

//typedef struct _retire_info retire_info;

double compute_capital(double balance, double rate, double contribution)
{

  balance = balance * (1 + rate/12);

  balance = balance + contribution;

  return balance;
}

void print_data(int month, double balance)
{
  int year = 0;
  int mont = 0;

  year = month/12;
  mont = month%12;

  printf("Age %3d month %2d you have $%.2lf\n",year,mont,balance);
}


void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{

  //retirement account while working
  double balance = initial;
  int age_month = startAge;


  for(age_month = startAge; age_month <= startAge + working.months + retired.months; age_month++)
    {
      print_data(age_month,balance);

      if(age_month <= startAge + working.months){

	balance = compute_capital(balance,working.rate_of_return,working.contribution);
      }

      if(age_month > startAge + working.months && age_month <= startAge + working.months + retired.months){

	balance = compute_capital(balance,retired.rate_of_return,retired.contribution);
      }
    }

}


int main(void){

  int startAge = 327;

  double initial = 21345;

  retire_info working = {489,1000,0.045};

  retire_info retired = {384,-4000,0.01};

  retirement(startAge,initial,working,retired);

}

