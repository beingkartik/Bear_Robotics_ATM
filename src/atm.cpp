
//load all the account details and balances into local memory
#include <iostream>
#include <string>
#include "atm.h"
#include "bank.h"
#include "cash_bin.h"

using namespace std;

ATM::ATM(int starting_cash_in_atm, string data_dir):my_bank(data_dir),my_cash_bin(starting_cash_in_atm){

    cout << "ATM Started with total "<<my_cash_bin.getCashInBin()<<" in the cash bin" <<endl;
//    startAtmFromStart();

}

void ATM::performWithdrawal(int& account_num){
    cout << "Enter the amount of money to be Withdrawn: ";
    int withdraw_amount;
    cin>>withdraw_amount;

    bool withdraw_possible = my_bank.checkIfCanWithdraw(account_num,withdraw_amount);
    try{
        if(!withdraw_possible ){
            throw 0;
        }else if(my_cash_bin.getCashInBin() < withdraw_amount){
            throw 1;
        }
        my_cash_bin.dispenseCash(withdraw_amount);
        my_bank.updateBalanceAfterWithdraw(account_num, withdraw_amount);
        cout << "Collect Cash from Dispenser"<<endl;

    }catch(int e){

        //Can Modify the error handling as required
        if(e == 0){
            cout << "Insufficient funds in account for withdrawal"<<endl;
        }else if(e == 1){
            cout << "Insufficient Cash in ATM. Sorry. Try Again later"<<endl;
        }
    }catch(...){

        cout << "Handle ATM Dispensing Errors";
    }
}

void ATM::performDeposit(int& account_num){

    cout << "Enter the amount of money to be deposited: ";
    int deposit_amount;
    cin>>deposit_amount;

    cout << "Put the money in the deposit can" << endl;
    try{
        int deposit_detected = my_cash_bin.acceptCash(deposit_amount);

        if(deposit_detected == deposit_amount){
            cout << "Deposit Completed Successfully" <<endl;
            my_bank.updateBalanceAfterDeposit(account_num, deposit_amount);
        }else{
            throw 0;
        }
    }catch(int e){

        cout << "Not enough cash inserted"<<endl;

    }catch(...){

        cout << "Handle ATM System Errors";
    }

}

int ATM::selectBankAccount(int user_id, vector <int>& user_accounts){
    cout << "Select the index corresponding to the account needed"<<endl;
    for(int i = 0; i<user_accounts.size();++i){
            cout << i+1 << ": " <<user_accounts[i]<<endl;
    }

    int input;
    try{

        cin >> input;
        if(input<1 || input >user_accounts.size()){
            throw 0;
        }
    }catch(int e){
        cout << "Invalid Input entered. Try Again "<<endl;
        return selectBankAccount(user_id,user_accounts);
    }

    return user_accounts[input-1];
}

bool ATM::performTransaction(int user_id, vector<int>&user_accounts){


    int account_num =selectBankAccount(user_id,user_accounts);

    cout <<"Selected account "<<account_num<<endl;
    int input;

    cout <<"What would you like to do today"<<endl;
    cout << "Enter 1 for Checking Balance, 2 for Depositing Money and 3 for Withdrawing Money"<<endl;
    cin >> input;

    switch (input){

    case 1:
        cout << "The Current Balance in Account "<< account_num << " is " << my_bank.getAccountBalance(account_num) <<endl;
        break;
    case 2:
        performDeposit(account_num);
        break;
    case 3:
        performWithdrawal(account_num);
        break;

    default:
        cout << "Invalid Option Selected"<<endl;
    }

    cout << endl<<"Do you want to perform another transaction?" <<endl;
    cout << "Enter 1 for Yes or 0 for No: ";

    cin >> input;

    if(input >= 1){
        return true;
    }else {
        cout << "Have a great day" <<endl;
        return false;
    }

}

void ATM::startAtmFromStart(){
    cout << endl<<endl<< "Welcome to Bear my_bank" << endl;
    cout << "Insert card into the slot" << endl;



    cout << "(enter the card number for test):";

    int card_number;
    cin >> card_number;


    //check if card is valid based on the card number
    if(!my_bank.isCardValid(card_number)){
        cout << "Card Invalid! Try Again or Contact Your my_bank at 999.999.9999"<<endl;
        return;
    }

    //if card is valid, ask for 4 digit pin and check if valid

    int user_id =  my_bank.getUserId(card_number);
    cout << "Enter the 4 digit pin:";

    int pin;
    cin >> pin;

    //check if pin is correct
    //in real system this part will surely require encryption
    if(!my_bank.verifyUser(card_number,pin)){

        cout << "XXX Invalid Pin XXX"<<endl;
        return;
    }else{
        cout << "Welcome " << my_bank.getUserName(user_id) << endl;
    }

    vector<int>user_accounts;
    user_accounts = my_bank.getUserAccounts(user_id);

    bool do_transaction = true;

    while(do_transaction){
        do_transaction = performTransaction(user_id,user_accounts);
    }
}
