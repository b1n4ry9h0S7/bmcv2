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
int i, j, a_num, choice;
int n=100, flag=0;
FILE *old, *new, *ptr;

// @Funtions to be used
void test() //test
{
  printf("Hello World \n");
}

// @Add an account
void add() {
  int count = 0;
  long test_acc;
  // int choice;
  char a_type[100];

  ptr = fopen("record.dat", "a+");
  while(i<=100) {
    printf("%d",i);
    account_no:
    printf("Enter account number: \n");
    scanf("%ld",&test_acc);
    while(fscanf(ptr, "%ld\n", &cust->acc_num) != EOF)
    {
        if (test_acc == cust->acc_num)
        {
            printf("Account number already exists!\n");
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
    printf("Enter customer's address: \n");
    scanf("%s",cust[i].address);
    printf("Enter customer's age:\n");
    scanf("%d",&cust[i].age);
    printf("Enter customer's phone number: \n");
    scanf("%lf",&cust[i].phone);
    printf("Enter inital deposit amount: \n");
    scanf("%lf",&cust[i].amt);
    printf("Select an account type: \n ['sav'] Savings \n ['cur'] Current\n['fx1'] Fixed for a year\n['fx2'] Fixed for 2 years\n['fx3'] Fixed for 3 years\n Type your choice: \n");
    scanf("%s",cust[i].acc_type);

    //@FIX here and continue
    // add a transaction file to track transactions
    fprintf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust[i].acc_num, cust[i].name, cust[i].dob.day, cust[i].dob.month, cust[i].dob.year, cust[i].address, cust[i].age, cust[i].phone, cust[i].amt, cust[i].acc_type, cust[i].deposit.day, cust[i].deposit.month, cust[i].deposit.year);
    printf("%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust[i].acc_num, cust[i].name, cust[i].dob.day, cust[i].dob.month, cust[i].dob.year, cust[i].address, cust[i].age, cust[i].phone, cust[i].amt, cust[i].acc_type, cust[i].deposit.day, cust[i].deposit.month, cust[i].deposit.year);
    printf("Account created successfully!\n");
    count++;
    add_choice:
    printf("Do you want to add another account? \n[1] Yes\n[2] No\nEnter your choice:\n");
    scanf("%d",&choice);
    if(choice == 1){
      i++;
    }else if(choice == 2) {
      fclose(ptr);
      break;
    }
    else {
      printf("Invalid choice!\n");
      goto add_choice;
    }
  }
}

// @List Function
// Formating of output required
void list() {
  // int flag = 0;
  ptr = fopen("record.dat", "r");
  printf("Acc no. Name Address \n");
  while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {
    printf("%ld %s %s", cust->acc_num, cust->name, cust->address);
    flag++;
  }
  fclose(ptr);
  if(flag == 0) {
    printf("No records found!");
  }

//Add a main menu link
}


// @Delete an account
void delete(){
  FILE *old, *new;
  int flag = 0;
  int a_num;
  old = fopen("record.dat", "r");
  new = fopen("new.dat", "w");
  invalid_record:
  printf("Enter account to number to be deleted: \n");
  scanf("%d",&a_num);

  while (fscanf(old, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {

      if(cust->acc_num != a_num) {
        fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
      } else {
        flag++;
        printf("Record deleted successfully! \n");
      }
  }
  fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (flag == 0) {
      printf("No such record found! \n");

      //Add a main menu link
    }
}


void update(){
  int choice, flag = 0;
  char new_address[100];
  double new_phone;
  old = fopen("record.dat", "r");
  new = fopen("new.dat", "w");
  printf("Enter account number to be updated: \n");
  scanf("%d", &a_num);
    while (fscanf(old, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {

      if(cust->acc_num == a_num) {
        flag = 1;
        printf("Select an information to be updated: \n [1] Address\n[2] Phone\nEnter your choice: \n");
        scanf("%d",&choice);
        if(choice==1) {
            printf("Enter new address: \n");
            scanf("%s",new_address);
            fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, new_address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
            printf("Changes saved! \n");
        } else if(choice == 2) {
          printf("Enter new phone number: \n");
          scanf("%lf",&new_phone);
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, new_address, cust->age, new_phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
          printf("Changes saved! \n");
        } else {
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
        }
        fclose(old);
        fclose(new);
        remove("record.dat");
        rename("new.dat", "record.dat");
        if (flag == 0) {
          printf("No such record! \n");

          // Add a main menu link
        }
      }
    }


} //Edit/Update an account

void check(){} //Check/Validate an existing account

void transact(){
  
} //Transact money from an account

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
// list();
// delete();
// update();
return 0;
}
