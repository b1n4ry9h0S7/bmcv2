#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int i, j, a_num, choice,choice_1;
int n=100, flag=0;
FILE *old, *new, *ptr;

// @Funtions to be used
void test() //test
{
  printf("Hello World \n");
}
void clear() {
  system("clear");
}
void close(){
  exit(0);
}
void add();
void update();
void transact();
void list();
void check();
void delete();
void logout();

void menu() {
  choice_3:
  clear();
  printf("BANK MANAGEMENT SYSTEM\n\n");

  printf("[1] Open an account\n[2] Update an account\n[3] Make a transaction\n[4] Check an account\n[5] Delete an account\n[6] Customer list\n[7] Exit\n");
  printf("\nPlease enter your choice:\n");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      add();
      break;
    case 2:
      update();
      break;
    case 3:
      transact();
      break;
    case 4:
      check();
      break;
    case 5:
      delete();
      break;
    case 6:
      list();
      break;
    case 7:
      logout();
    default:
      printf("Invalid choice!\n");
      // break;
      goto choice_3;
  }

}

void logout(){
  close();
} // For logging out

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);

}
// @Add an account
void add() {
  // int count = 0;
  long test_acc;
  int choice_1;
  char a_type[100];
  int menu_exit;
  while(i<=100) {
    // printf("%d",i);
    create:
    ptr = fopen("record.dat", "a+");
    account_no:
    clear();
    printf("Enter account number:\n");
    scanf("%ld",&test_acc);
    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF)
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
    printf("Select an account type: \n['sav'] Savings \n['cur'] Current\n['fx1'] Fixed for a year\n['fx2'] Fixed for 2 years\n['fx3'] Fixed for 3 years\n Type your choice: \n");
    scanf("%s",cust[i].acc_type);
    // add a transaction file to track transactions
    fprintf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust[i].acc_num, cust[i].name, cust[i].dob.day, cust[i].dob.month, cust[i].dob.year, cust[i].address, cust[i].age, cust[i].phone, cust[i].amt, cust[i].acc_type, cust[i].deposit.day, cust[i].deposit.month, cust[i].deposit.year);
    printf("Account created successfully!\n");
    // count++;
    fclose(ptr);
    i++;
    add_choice:
    printf("Select an option:\n[1] Create another account\n[2] Goto main menu\nEnter your choice:\n");
    scanf("%d",&choice);
    if(choice == 1){
      goto create;
    }else if(choice == 2) {
      // system_1:
      menu();
      break;
    }
    else {
      printf("Invalid choice!\n");
      goto add_choice;
    }

  }

}

// @List Function
// Formating of outp\nut requi
void list() {
  // int flag = 0;
  clear();
  ptr = fopen("record.dat", "r");
  printf("Acc no. \t Name\n");
  printf("=======================\n");
  while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {
    printf("%ld \t\t %s\n\n", cust->acc_num, cust->name);
    flag++;
  }
  fclose(ptr);
  if(flag == 0) {
    printf("No records found!");
  }
  add_choice:
  printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
  scanf("%d",&choice);
  if(choice == 1){
    menu();
  } else if(choice == 2) {
    logout();
  }
  else {
    printf("Invalid choice!\n");
    goto add_choice;
  }
}


// @Delete an account
void delete(){
  FILE *old, *new;
  int flag = 0;
  int a_num;
  old = fopen("record.dat", "r");
  new = fopen("new.dat", "w");

  invalid_record:
  clear();
  printf("Enter account to number to be deleted: \n");
  scanf("%d",&a_num);

  while (fscanf(old, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF)
  {
      if(cust->acc_num != a_num) {
        fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
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

    }
    add_choice:
    printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
    scanf("%d",&choice);
    if(choice == 1){
      menu();
    } else if(choice == 2) {
      logout();
    }
    else {
      printf("Invalid choice!\n");
      goto add_choice;
    }
    }


void update(){
  int choice, flag = 0;
  char new_address[100];
  double new_phone;
  old = fopen("record.dat", "r");
  new = fopen("new.dat", "w");
  clear();
  printf("Enter account number to be updated: \n");
  scanf("%d", &a_num);
    while (fscanf(old, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {

      if(cust->acc_num == a_num) {
        flag = 1;
        printf("Select an information to be updated: \n[1] Address\n[2] Phone\nEnter your choice: \n");
        scanf("%d",&choice);
        if(choice==1) {
          clear();
            printf("Enter new address: \n");
            scanf("%s",new_address);
            fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, new_address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
            printf("Changes saved! \n");
            system_beta:
          printf("Do you want to continue to:\n[1] Main menu\n[2] Logout");
          printf("%ls\n",&choice);
          switch (choice) {
            case 1:
              menu();
            case 2:
              logout();
            default:
              printf("Invalid choice!\n");
              goto system_beta;
          }
        } else if(choice == 2) {
          clear();
          printf("Enter new phone number: \n");
          scanf("%lf",&new_phone);
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, new_address, cust->age, new_phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
          printf("Changes saved! \n");
          printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
          scanf("%d",&choice);
          if(choice == 1){
            menu();
          }else if(choice == 2) {
            // system_1:
            logout();
            // break;
          }
          else {
            printf("Invalid choice!\n");
            // goto add_choice;
          }
        } else {
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
        }
        fclose(old);
        fclose(new);
        remove("record.dat");
        rename("new.dat", "record.dat");
        if (flag == 0) {
          printf("No such record! \n");

        }

        add_choice:
        printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
        scanf("%d",&choice);
        if(choice == 1){
          menu();
        } else if(choice == 2) {
          logout();
        }
        else {
          printf("Invalid choice!\n");
          goto add_choice;
        }
        }
      }
    }
 //Edit/Update an account

// @Transact money from an account
void transact(){
  int a_num;
  float d_amt,w_amt;
  old = fopen("record.dat", "r");
  new = fopen("new.dat", "w");
  clear();
  printf("Enter account number: \n");
  scanf("%d",&a_num);
  while (fscanf(old, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {

    if(cust->acc_num == a_num) {
      flag = 1;
      if (strcmp(cust->acc_type,"fx1") == 0 || strcmp(cust->acc_type,"fx2") == 0 || strcmp(cust->acc_type,"fx3") == 0) {
        printf("You cannot withdraw or deposit cash in fixed accounts!\n");

        // add menu link
      } else {
        choice_1:
        clear();
        printf("Do you want to\n[1] Deposit\n[2] Withdraw\nEnter your choice:\n" );
        scanf("%d",&choice);
        if(choice == 1) {
          clear();
          printf("Enter amount to deposit:\n");
          scanf("%f",&d_amt);
          cust->amt += d_amt;
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
          printf("Deposited successfully!\n" );
        } else if(choice == 2) {
          clear();
          printf("Enter amount to withdraw:\n");
          scanf("%f",&w_amt);
          cust->amt -= w_amt;
          fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
          printf("withdrawn successfully!\n");
        } else {
          printf("Invalid choice\n");
          goto choice_1;
        }
      }
    } else {
      fprintf(new, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d \n", cust->acc_num, cust->name, cust->dob.day, cust->dob.month, cust->dob.year, cust->address, cust->age, cust->phone, cust->amt, cust->acc_type, cust->deposit.day, cust->deposit.month, cust->deposit.year);
    }
  }
  fclose(old);
  fclose(new);
  remove("record.dat");
  rename("new.dat", "record.dat");
  if (flag != 1) {
    printf("No such record!\n");

  }
  add_choice:
  printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
  scanf("%d",&choice);
  if(choice == 1){
    menu();
  } else if(choice == 2) {
    logout();
  }
  else {
    printf("Invalid choice!\n");
    goto add_choice;
  }
  }

//Check/Validate an existing account
void check(){
int rate,a_num;
float time,inrst;
char a_name[100];
ptr = fopen("record.dat", "r");
choice_2:
clear();
printf("Select an option to check customer info:\n[1] Account number\n[2] Name\nEnter your choice:\n");
scanf("%d",&choice);
if (choice == 1) {
  printf("Enter account number:\n");
  scanf("%d",&a_num);
  while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {
      if (cust->acc_num == a_num) {
        flag = 1;
        printf("Account number: %ld\nName: %s\nDate of birth: %d/%d/%d \nAge: %d \nAddress %s \nPhone number: %lf \n Account Type: %s \n Current Balance: %lf \n Created on: %d/%d/%d \n",cust->acc_num,cust->name,cust->dob.day,cust->dob.month,cust->dob.year,cust->age,cust->address,cust->phone,cust->acc_type,cust->amt,cust->deposit.day,cust->deposit.month,cust->deposit.year);
        if (strcmp(cust->acc_type,"fx1") == 0) {
          time = 1.0;
          rate = 9;
          inrst = interest(time,cust->amt,rate);
          printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+1);
        } else if (strcmp(cust->acc_type,"fx2") == 0) {
          time = 2.0;
          rate = 11;
          inrst = interest(time,cust->amt,rate);
          printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+2);
        } else if (strcmp(cust->acc_type,"fx3") == 0) {
          time = 3.0;
          rate = 13;
          inrst = interest(time,cust->amt,rate);
          printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+3);
        } else if (strcmp(cust->acc_type,"sav") == 0) {
          time = (1.0 / 12.0);
          rate = 8;
          printf("Rs. %0.2f as interest will be added on %d of every month.\n", inrst,cust->deposit.day);
        } else {
          printf("Current accounts don't get interests!");
        }
  } else if (choice == 2) {
    printf("Enter customer name:\n");
    scanf("%s",a_name);
    clear();
    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %lf %lf %s %d/%d/%d", &cust->acc_num, cust->name, &cust->dob.day, &cust->dob.month, &cust->dob.year, cust->address, &cust->age, &cust->phone, &cust->amt, cust->acc_type, &cust->deposit.day, &cust->deposit.month, &cust->deposit.year)!=EOF) {

        if (cust->name == a_name) {
          flag = 1;
          printf("Account number: %ld\nName: %s\nDate of birth: %d/%d/%d \nAge: %d \nAddress %s \nPhone number: %lf \n Account Type: %s \n Current Balance: %lf \n Created on: %d/%d/%d \n",cust->acc_num,cust->name,cust->dob.day,cust->dob.month,cust->dob.year,cust->age,cust->address,cust->phone,cust->acc_type,cust->amt,cust->deposit.day,cust->deposit.month,cust->deposit.year);
          if (strcmp(cust->acc_type,"fx1") == 0) {
            time = 1.0;
            rate = 9;
            inrst = interest(time,cust->amt,rate);
            printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+1);
          } else if (strcmp(cust->acc_type,"fx2") == 0) {
            time = 2.0;
            rate = 11;
            inrst = interest(time,cust->amt,rate);
            printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+2);
          } else if (strcmp(cust->acc_type,"fx3") == 0) {
            time = 3.0;
            rate = 13;
            inrst = interest(time,cust->amt,rate);
            printf("Rs. %0.2f as interest will be added on %d/%d/%d \n", inrst,cust->deposit.day,cust->deposit.month,cust->deposit.year+3);
          } else if (strcmp(cust->acc_type,"sav") == 0) {
            time = (1.0 / 12.0);
            rate = 8;
            printf("Rs. %0.2f as interest will be added on %d of every month.\n", inrst,cust->deposit.day);
          } else {
            printf("Current accounts don't get interests!");
          }
        }
      }
  } else {
    printf("Invalid choice!\n");
    goto choice_2;

  }
}
    fclose(ptr);
    if (flag != 1) {
      printf("No such record!\n");

    }
    add_choice:
    printf("\n\nSelect an option:\n[1] Main Menu\n[2] Logout\nEnter your choice:\n");
    scanf("%d",&choice);
    if(choice == 1){
      menu();
    } else if(choice == 2) {
      logout();
    }
    else {
      printf("Invalid choice!\n");
      goto add_choice;
    }
    }
}




int main(void) {
char pass[10], pin_num[10] = "1337";
int i = 0;
try:
clear();
printf("Login\n\n");
printf("Enter the system pin:\n");
scanf("%s",pass);
if (strcmp(pass,pin_num)== 0) {
  clear();
  menu();
} else {
  printf("Wrong password!\n");
  choice_4:
  printf("Would you like to try again? \n[1] Yes\n[2] No\nEnter your choice:\n");
  scanf("%d",&choice);
  if (choice == 1) {
    goto try;
  } else if(choice == 2) {
      close();
  } else {
    printf("Invalid choice!");
    goto choice_4;
  }
}

return 0;
}
