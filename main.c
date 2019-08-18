#include <stdio.h>

// @Variable declations
struct date {
  int day, month, year;
};

struct Customer {
  char name[100];
  int age;
  long acc_num;
  double phone,amt;
  char address[100];
  char acc_type[100];
  struct date dob;
  struct date deposit;
  struct date withdraw;
};
struct Customer cust[100];
int i,j;
int n=100;
FILE * ptr;

// @Funtions to be used
void test() //test
{
  printf("Hello World \n");
}

// @Add an account
void add() {
  long test_acc;
  int choice;
  char a_type[100];

  ptr = fopen("record.dat", "a+");
  while(i<100) {
    account_no:
    printf("Enter account number: \n");
    scanf("%ld",&test_acc);
    while(fscanf(ptr, "%ld\n", &cust->acc_num) != EOF)
    {
        if (test_acc == cust->acc_num)
        {
            printf("Account no. already in use!\n");
            goto account_no;
        }
    }
    cust[i].acc_num = test_acc;
    printf("Enter today's date (dd/mm/yy):\n");
    scanf("%d/%d/%d", &cust[i].deposit.day, &cust[i].deposit.month, &cust[i].deposit.year);
    printf("Enter customer's Name:\n");
    scanf("%s",cust[i].name);
    printf("Enter customer's date of birth (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &cust[i].dob.day, &cust[i].dob.month, &cust[i].dob.year);
    printf("Enter customer's age:\n");
    scanf("%d",&cust[i].age);
    printf("Enter customer's phone number: \n");
    scanf("%lf",&cust[i].phone);
    printf("Enter inital deposit amount: \n");
    scanf("%lf",&cust[i].amt);
    printf("Select an account type: \n ['sav'] Savings \n ['cur'] Current\n['fx1'] Fixed for a year\n['fx2'] Fixed for 2 years\n['fx3'] Fixed for 3 years");
    scanf("%s",cust[i].acc_type);

    //@FIX here and continue
    fprintf(ptr, "%ld\n", cust[i].acc_num);
    fclose(ptr);
    printf("Account created successfully!\n");
    add_choice:
    printf("Do you want to add another account? \n[1] Yes\n[2] No\nEnter your choice:\n");
    scanf("%d",&choice);
    if(choice == 1){
      i++;
    }else if(choice == 2) {
      break;
    }
    else {
      printf("Invalid choice!\n");
      goto add_choice;
    }
  }
}



void delete(){

} //Delete an account

// void list() {
//   int flag = 0;
//   ptr = fopen("record.dat", "r");
//
// }
void update(){} //Edit/Update an account

void check(){} //Check/Validate an existing account

void transact(){} //Transact money from an account

void login(){} //For Login operations

void logout(){} // For logging out

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);

}


int main(void) {
// test();
// int test = sizeof(cust);
// printf("%d",test);
test();
add();
return 0;
}
