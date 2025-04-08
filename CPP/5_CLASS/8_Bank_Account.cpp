// 🏦 Problem Title: Basic Banking System Simulator
// Difficulty: Medium
// Category: OOP / Simulation

// 🧾 Problem Description:
// You are required to simulate a basic banking system where a user can:

// Create multiple bank accounts.

// Deposit money into a specific account.

// Withdraw money from a specific account.

// Each account is automatically assigned a unique account number based on a predefined pattern. The system should dynamically handle multiple accounts and support basic banking operations.

// 🧩 Functionalities to Implement:
// Design a class BankAccount with the following features:

// 🔹 CreateBankAccount(int count)
// Generates a unique account number using the format "242040312" followed by a count number.

// Takes input for the account holder's name and initial balance.

// 🔹 deposit(float amount)
// Deposits the given amount into the account and prints a success message.

// 🔹 withdraw(float amount)
// Withdraws the given amount only if sufficient balance is available; else, prints an error.

// 📥 Input Format:
// The program starts with an empty list of bank accounts.

// Users are shown a menu to choose:

// 1 to create an account

// 2 to deposit into an account

// 3 to withdraw from an account

// 4 to exit

// Each choice will require relevant user input (like account number, name, amount, etc.).

// 📤 Output Format:
// Print appropriate messages for account creation, deposit, withdrawal, and error handling (like invalid account number or insufficient balance).

// 🚫 Constraints:
// Account holder name: string (up to 50 characters)

// Balance and deposit/withdraw amounts: float (positive numbers only)

// Maximum number of accounts: Dynamic (initially 10, increases by 10 as needed)

// Account numbers are unique and generated using the format:

// "24204031208" + count (if count < 10)

// "2420403120" + count (if 10 ≤ count < 100)

// "242040312" + count (if count ≥ 100)

// ✅ Sample Input / Output:

// 1.) Create Account
// 2.) Deposit Amount
// 3.) Withdraw Amount
// 4.) Exit
// Enter your choice:- 1
// Enter Full Name of Account holder:- Alice
// Enter amount to deposit:- 5000
// Account created

// Enter your choice:- 2
// Enter Account no.:- 242040312081
// Enter an amount you want to deposit:- 1500
// Dear Customer, Account 242040312081 has been credited for Rs.1500 your new balance is Rs.6500

// Enter your choice:- 3
// Enter Account no.:- 242040312081
// Enter an amount you want to withdraw:- 3000
// Dear Customer, Account 242040312081 has been debited for Rs.3000 your new balance is Rs.3500

// Enter your choice:- 3
// Enter Account no.:- 242040312081
// Enter an amount you want to withdraw:- 4000
// Insufficient Balance


//Program to perform basic banking operation
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// void reallocating_size(BankAccount bank_account_details[],int *size)


class BankAccount
{
    private:
        string accountNumber,accountHolder;
        float balance;
    
    public:
        void CreateBankAccount(int count)
        {
            if(count >= 1 && count < 10)
            {
                accountNumber = "24204031208" + to_string(count);
            }
            else if(count >= 10 && count < 100) 
            {
                accountNumber = "2420403120" + to_string(count);
            }
            else 
            {
                accountNumber = "242040312" + to_string(count);
            }
            cout<<"Enter Full Name of Account holder:- ";
            cin.ignore();
            getline(cin,accountHolder);
            cout<<"Enter amount to deposit:- ";
            cin>>balance;
            cout<<"Account created"<<endl;
        }
        //Getter methods
        string get_accountNumber()
        {
            return accountNumber;
        }
        string get_accountHolder()
        {
            return accountHolder;
        }
        float get_balance()
        {
            return balance;
        }

        //Setter methods
        void set_accountNumber(string accountNumber)
        {
            this->accountNumber = accountNumber;
        }
        void set_accountHolder(string accountHolder)
        {
            this->accountHolder = accountHolder;
        }
        void set_balance(float balance)
        {
            this->balance = balance;
        }

        void deposit(float amount)
        {
            balance += amount;
            cout<<"Dear Customer, Account "<<accountNumber<<" has been credited for Rs."<<amount<<" your new balance is Rs."<<balance<<endl;
        }

        void withdraw(float amount)
        {
            if(balance >= amount)
            {
                balance -= amount;
                cout<<"Dear Customer, Account "<<accountNumber<<" has been debited for Rs."<<amount<<" your new balance is Rs."<<balance<<endl;

            }
            else 
            {
                cout<<"\nInsufficient Balance";
            }
        }
};

void reallocating_size(BankAccount *bank_account_details,int *size)
{
    BankAccount *new_bank_details = new BankAccount[*size+10];
    copy(bank_account_details,bank_account_details+*size,new_bank_details);
    *size +=10;
    delete[] bank_account_details;
    bank_account_details = new_bank_details;
    delete[] new_bank_details;
}


int main()
{
    int amount,choice,size_array_of_objects=10,count=0,flag=0;
    string accountNumber;
    BankAccount *bank_account_details = new BankAccount[size_array_of_objects]; 
    do
    {
        cout<<"\n1.) Create Account";
        cout<<"\n2.) Deposit Amount";
        cout<<"\n3.) Withdraw Amount";
        cout<<"\n4.) Exit";
        cout<<"\nEnter your choice:- ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                if(count == size_array_of_objects)
                {
                    reallocating_size(bank_account_details,&size_array_of_objects);
                }
                bank_account_details[count++].CreateBankAccount(count);
                break;

            case 2:
                cout<<"Enter Account no.:- ";
                cin>>accountNumber;
                for(int i=0;i<count;i++)
                {
                    if(bank_account_details[i].get_accountNumber() == accountNumber)
                    {
                        cout<<"Enter an amount you want to deposit:- ";
                        cin>>amount;
                        bank_account_details[i].deposit(amount);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    cout<<"No such Account exist!"<<endl;
                }
                flag = 0;
                break;

            case 3:
                cout<<"Enter Account no.:- ";
                cin>>accountNumber;
                for(int i=0;i<count;i++)
                {
                    if(bank_account_details[i].get_accountNumber() == accountNumber)
                    {
                        cout<<"Enter an amount you want to withdraw:- ";
                        cin>>amount;
                        bank_account_details[i].withdraw(amount);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    cout<<"No such Account exist!";
                }
                flag = 0;
                break;

            case 4:
                break;

            default:
                cout<<"\nInvalid Choice";
        }
        
    } while (choice != 4);
    
    return 0;
}