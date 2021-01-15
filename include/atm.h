#pragma once
//load all the account details and balances into local memory
#include <iostream>
#include <string>
#include "bank.h"
#include "cash_bin.h"

class ATM{

private:
    Bank my_bank;
    CashBin my_cash_bin;

    //asks for user input regarding amount to be withdrawn
    //checks if its valid as per the account balance
    //checks if there is enough cash in the atm
    //if all valid, then amount is withdrawn, and deducted from the user's account, as well as from cash bin
    void performWithdrawal(int& account_num);


    //asks for user input regarding amount to be withdrawn
    //has provision to check if enough cash is deposited physically (not possible to implement right now)
    //if all valid, then amount is deposited, and added to the user's account, as well as to cash bin
    void performDeposit(int& account_num);

    //each user can have multiple bank accounts
    //this asks user's input to select which account is needed right now
    int selectBankAccount(int user_id, vector <int>& user_accounts);

    //the main function handling the transactions
    //prompts for selecting account
    //prompts for selecting the kind of activity being performed today - withdraw, deposit or withdraw
    //after each transaction, user can start another transaction without having to enter card or pin again
    //on completion, returns to the atm "home screeen", ready to read a card
    bool performTransaction(int user_id, vector<int>& user_accounts);

public:

    //Constructor: starting_cash_in_atm = total starting cash in the atm; data_dir = specify the project directory address
    ATM(int starting_cash_in_atm,string data_dir);

    //starts the atm "home screen", ready to "read the card"
    //prompts for user pin, and checks if valid
    //if valid, sends user to perform transactions
    void startAtmFromStart();
};
