#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define TIMER_DURATION 20
#define MAX_LENGTH 20

int userInterface();
int createAccount();
int takeEmail();
int verifyEmail();
void getContactNumber();
void getAlternativeContactNumber();
void verifyAlternativeContactNumber();
int accountNumber();
int setPIN();
int timer();
int login1();
int login2();
int login3();

int main()
{
    userInterface();
    return 0;
}

int userInterface()
{
    mainHeadingDesign();
    subHeadingDesign();
    printf("+-------------------+\t\t\t+-----------+\n");
    printf("| 1. Create Account |\t\t\t| 2.Login   |\n");
    printf("+-------------------+\t\t\t+-----------+\n");
    printf("Enter Choice:");
    int choice1; // choice1=choice between create account and login
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
        createAccount();
    }
    else if (choice1 == 2)
    {
        login1();
    }
    else
    {
        int i;
        char text[] = "Wrong Choice";
        for (i = 0; i < 8; i++)
        { 
            printf("\r%s", (i % 2 == 0) ? text : "            ");
            fflush(stdout);
            sleep(1); // wait for 1 second
        }
        printf("\n");
        userInterface();
    }
    return 0;
}
int mainHeadingDesign()
{
    printf("\t\t\t\t\t\t\t+----------------------------------+\n");
    printf("\t\t\t\t\t\t\t|        C r o w n V a u l t       |\n");
    printf("\t\t\t\t\t\t\t+----------------------------------+\n");
    return 0;
}
int subHeadingDesign()
{
    printf("\t\t\t\t\t\t\t+------------------------------------+\n");
    printf("\t\t\t\t\t\t\t|  W e l c o m e   t o   C r o w n   |\n");
    printf("\t\t\t\t\t\t\t|             V a u l t              |\n");
    printf("\t\t\t\t\t\t\t+------------------------------------+\n");
    return 0;
}
char firstname[50]; // Global Variable
int createAccount()
{

    printf("Account Holder Name:");
    scanf("%s", &firstname);

    char lastname[50];
    printf("Last Name:");
    scanf("%s", &lastname);

    takeEmail();
    return 0;
}
char email[100]; // Global Variable
int takeEmail()  // Input email From user
{

    printf("Email Address:");
    scanf("%s", &email);

    verifyEmail();
    return 0;
}

int verifyEmail() // Verify Email by sending OTP And checking whether mail contains @gmail.com
{
    int i;
    int found = 0;
    for (i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            if (email[i + 1] == 'g' && email[i + 2] == 'm' && email[i + 3] == 'a' &&
                email[i + 4] == 'i' && email[i + 5] == 'l' && email[i + 6] == '.' &&
                email[i + 7] == 'c' && email[i + 8] == 'o' && email[i + 9] == 'm')
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        srand(time(NULL));
        int token = rand() % 9000 + 1000; // Generate a random 4-digit number

        printf("A proof of login has been generated and sent to your Email.\n");
        printf("Proof of login: %d\n", token);

        int inputToken;
        printf("Please enter the proof of login  received on your Email:");
        scanf("%d", &inputToken);

        if (inputToken == token)
        {
            printf("Mail Id Verified!\n");
            getContactNumber();
        }
        else
        {
            int i;
            char text[] = "Invalid Email ID";
            for (i = 0; i < 8; i++)
            {                                                              
                printf("\r%s", (i % 2 == 0) ? text : "                 "); 
                fflush(stdout);
                sleep(1); // wait for 1 second
            }
            printf("\n"); // move to the next line
            takeEmail();
        }
    }

    else
    {
        int i;
        char text[] = "Invalid Email ID";
        for (i = 0; i < 8; i++)
        {                                                              
            printf("\r%s", (i % 2 == 0) ? text : "                 "); 
            fflush(stdout);
            sleep(1); 
        }
        printf("\n");
        takeEmail();
    }

    return 0;
}
void getContactNumber()
{
    checkContactNumber();
}
int checkContactNumber()
{
    long long number;
    int digitCount = 0;
    printf("Contact Number:");
    scanf("%lld", &number); // Count the digits in the number
    while (number != 0)
    {
        number /= 10;
        digitCount++;
    }
    if (digitCount == 10)
    {
        getAlternativeContactNumber();
    }
    else
    {
        int i;
        char text[] = "Invalid Contact Number";
        for (i = 0; i < 8; i++)
        {                                                                   
            printf("\r%s", (i % 2 == 0) ? text : "                      "); 
            fflush(stdout);
            sleep(1); 
        }
        printf("\n"); 
        checkContactNumber();
    }
    return 0;
}
int AlternativeContactNumber; // Global Variable
void getAlternativeContactNumber()
{

    printf("Alternative Contact Number:");
    scanf("%d", &AlternativeContactNumber);
    verifyAlternativeContactNumber();
}

void verifyAlternativeContactNumber()
{
    int digitCount = 0; // Count the digits in the number
    while (AlternativeContactNumber != 0)
    {
        AlternativeContactNumber /= 10;
        digitCount++;
    }
    if (digitCount == 10)
    {
        srand(time(NULL));
        int otp = rand() % 900000 + 100000; // Generate OTP
        printf("Your OTP for contact number verification is: %06d\n", otp);
        int user_otp;
        printf("Enter the OTP you received: ");
        scanf("%d", &user_otp);
        if (user_otp == otp) // OTP Verification
        {
            printf("OTP verified successfully!\n");
            accountNumber();
        }
        else
        {
            int i;
            char text[] = "OTP Verification Failed. Try Again";
            for (i = 0; i < 8; i++)
            {                                                                                   
                printf("\r%s", (i % 2 == 0) ? text : "                                      "); 
                fflush(stdout);
                sleep(1);
            }
            printf("\n"); 
            getAlternativeContactNumber();
        }
    }
    else
    {
        int i;
        char text[] = "Invalid Alternative Contact Number";
        for (i = 0; i < 8; i++)
        {                                                                                  
            printf("\r%s", (i % 2 == 0) ? text : "                                     "); 
            fflush(stdout);
            sleep(1); 
        }
        printf("\n"); 
        getAlternativeContactNumber();
    }
}
int accountNumberGeneration; // Global Variable
int accountNumber()
{

    srand(time(NULL));          // Random number generation
    for (int i = 0; i < 9; i++) // Generate random 9-digit account number
    {
        accountNumberGeneration = accountNumberGeneration * 10 + rand() % 10;
    }
    printf("  ###################################\n");
    printf("         Generated Account         \n");
    printf("         Number:%09d               \n", accountNumberGeneration);
    printf("  ###################################\n");
    int i;
    char text[] = "Remember Account Number for LOGIN";
    for (i = 0; i < 12; i++)
    {
        printf("\r%s", (i % 2 == 0) ? text : "                                    ");
        fflush(stdout);
        sleep(1); 
    }
    printf("\n"); 

    setPIN();
    return 0;
}
int confirmPIN; // Global Variable
int setPIN()
{
    int PIN;
    printf("Create a 4 Digit Pin:");
    scanf("%d", &PIN);

    printf("Confirm:");
    scanf("%d", &confirmPIN);

    timer();
    if (PIN == confirmPIN)
    {
        accountCreationAnimation();
        userInterface();
    }
    else if (PIN != confirmPIN)
    {
        int i;
        char text[] = "PIN DOES NOT MATCH. TRY AGAIN";
        for (i = 0; i < 8; i++)
        {
            printf("\r%s", (i % 2 == 0) ? text : "                                 ");
            fflush(stdout);
            sleep(1); 
        }
        printf("\n");
        setPIN();
    }
    return 0;
}
int accountCreationAnimation()
{
    printf("PROCESSING......\n");
    const int progressBarWidth = 50;
    int progress;
    for (progress = 0; progress <= 100; progress += 2)
    { 
        int numSymbols = progress * progressBarWidth / 100;
        printf("\r[");
        int i;
        for (i = 0; i < numSymbols; i++)
        {
            printf("#");
        }
        for (i = numSymbols; i < progressBarWidth; i++)
        {
            printf(" ");
        }
        printf("] %d%%", progress);
        fflush(stdout);
        usleep(100000);
    }
    printf("\nAccount Creation Successfull!\n"); 
    return 0;
}
int timer()
{
    printf("\033[2J\033[H"); // Clear screen 
    printf("PROCESSING REQUEST.PLEASSE WAIT\n");
    printf("PROCESSING REQUEST.PLEASSE WAIT\n");
    printf("PROCESSING REQUEST.PLEASSE WAIT\n");
    for (int i = TIMER_DURATION; i > 0; --i)
    {
        printf("\033[2K\r%d seconds left.          ", i);
        fflush(stdout); 
        sleep(1);
    }
    printf("\nTimer completed.\n");
}
int login1()
{
    char checkName[50];
    printf("Account Holder Name:");
    scanf("%s", &checkName);
    if (strcmp(firstname, checkName) == 0)
    {
        login2();
    }
    else
    {
        printf("INAVLID NAME.TRY AGAIN\n");
        login1();
    }
    return 0;
}
int login2()
{
    int accountNumberVerify;
    printf("Account Number:");
    scanf("%d", &accountNumberVerify);
    if (accountNumberGeneration == accountNumberVerify)
    {
        login3();
    }
    else
    {
        printf("INAVLID ACCOUNT NUMBER.TRY AGAIN\n");
        login2();
    }
    return 0;
}
int login3()
{
    int checkPin;
    printf("Enter PIN:");
    scanf("%d", &checkPin);
    if (confirmPIN == checkPin)
    {
        timer();
        loginCreationAnimation();
        homePage();
    }
    else
    {
        printf("INAVLID PIN.TRY AGAIN\n");
        login3();
    }
    return 0;
}
int loginCreationAnimation()
{
    printf("PROCESSING......\n");
    const int progressBarWidth = 50;
    int progress;
    for (progress = 0; progress <= 100; progress += 2)
    { 
        int numSymbols = progress * progressBarWidth / 100;
        printf("\r[");
        int i;
        for (i = 0; i < numSymbols; i++)
        {
            printf("#");
        }
        for (i = numSymbols; i < progressBarWidth; i++)
        {
            printf(" ");
        }
        printf("] %d%%", progress);
        fflush(stdout);
        usleep(100000);
    }
    printf("\nLogin Successfull!\n"); 
    return 0;
}
int homePage()
{
    printf("  +-------------------------+\n");
    printf("  |     CrownVault          |\n");
    printf("  +-------------------------+\n");
    printf("  | 1-Deposit Amount        |\n");
    printf("  +-------------------------+\n");
    printf("  | 2-Withdraw Amount       |\n");
    printf("  +-------------------------+\n");
    printf("  | 3-Check Balance         |\n");
    printf("  +-------------------------+\n");
    printf("  | 4-Logout                |\n");
    printf("  +-------------------------+\n");
    printf("Enter Choice:");
    int choice2;
    scanf("%d", &choice2); // choice2=choice between deposit and withdraw amount
    if (choice2 == 1)
    {
        depositAmount();
    }
    else if (choice2 == 2)
    {
        withdrawAmount();
    }
    else if (choice2 == 3)
    {
        checkBalance();
    }
    else if (choice2 == 4)
    {
        logout();
    }
    else
    {
        int i;
        char text[] = "Wrong Choice";
        for (i = 0; i < 8; i++)
        { 
            printf("\r%s", (i % 2 == 0) ? text : "            ");
            fflush(stdout);
            sleep(1); 
        }
        printf("\n");
        homePage();
    }
    return 0;
}
float CURRENT_BALANCE = 0.0;
int depositAmount()
{

    float depositMoney;
    printf("Enter the Amount to be Deposited:");
    scanf("%f", &depositMoney);

    int enterAccountNumber;
    printf("Account Number:");
    scanf("%d", &enterAccountNumber);

    if (enterAccountNumber == accountNumberGeneration)
    {
        CURRENT_BALANCE = CURRENT_BALANCE + depositMoney;
        printf("Depositing Amount......\n");
        const int progressBarWidth = 50;
        int progress;
        for (progress = 0; progress <= 100; progress += 2)
        {
            int numSymbols = progress * progressBarWidth / 100;
            printf("\r[");
            int i;
            for (i = 0; i < numSymbols; i++)
            {
                printf("#");
            }
            for (i = numSymbols; i < progressBarWidth; i++)
            {
                printf(" ");
            }
            printf("] %d%%", progress);
            fflush(stdout);
            usleep(100000);
        }
        printf("\nAmount Deposited!\n");
        printf("Amount Deposited=%f\t\tCurrent Balance=%f\t\t", depositMoney, CURRENT_BALANCE);
        dateAndTime();
        homePage();
    }
    else if (enterAccountNumber != accountNumberGeneration)
    {
        int i;
        char text[] = "Invalid Account Number";
        for (i = 0; i < 8; i++)
        {
            printf("\r%s", (i % 2 == 0) ? text : "                        ");
            fflush(stdout);
            sleep(1); 
        }
        printf("\n");
        depositAmount();
    }

    return 0;
}
int withdrawAmount()
{

    float withdrawMoney;
    printf("Enter the Amount to be Withdrawed:");
    scanf("%f", &withdrawMoney);

    int enterPin;
    printf("PIN:");
    scanf("%d", &enterPin);

    if (enterPin == confirmPIN)
    {
        CURRENT_BALANCE = CURRENT_BALANCE - withdrawMoney;
        printf("Withdrwaing Amount......\n");
        const int progressBarWidth = 50;
        int progress;
        for (progress = 0; progress <= 100; progress += 2)
        {
            int numSymbols = progress * progressBarWidth / 100;
            printf("\r[");
            int i;
            for (i = 0; i < numSymbols; i++)
            {
                printf("#");
            }
            for (i = numSymbols; i < progressBarWidth; i++)
            {
                printf(" ");
            }
            printf("] %d%%", progress);
            fflush(stdout);
            usleep(100000);
        }
        printf("\nAmount Withdrawed!\n");
        printf("Amount Withdrawed=%f\t\tCurrent Balance=%f\t\t\t\t", withdrawMoney, CURRENT_BALANCE);
        dateAndTime();
        homePage();
    }
    else if (enterPin != confirmPIN)
    {
        int i;
        char text[] = "Invalid PIN";
        for (i = 0; i < 8; i++)
        {
            printf("\r%s", (i % 2 == 0) ? text : "            ");
            fflush(stdout);
            sleep(1); 
        }
        printf("\n"); 
        withdrawAmount();
    }
    return 0;
}
void checkBalance()
{
    printf("Current Balance=%d", CURRENT_BALANCE);
    homePage();
}
void logout()
{
    timer();
    printf("SUCCESSFULLY ");
    fflush(stdout);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout); 
        usleep(250000);
        printf("\b \b"); 
        fflush(stdout);  
        usleep(250000);
    }

    printf(" LOGGED OUT\n"); 
}
void dateAndTime()
{
    time_t currentTime;
    time(&currentTime);
    char formattedTime[50];
    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", localtime(&currentTime));
    printf("Transaction time: %s\n", formattedTime);
}
