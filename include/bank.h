#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Bank{

  private:


      std::unordered_map<int,std::vector<int>>userAccounts;
      std::unordered_map<int,int>accountsDB;
      std::unordered_map<int,std::pair<int,int>>cardUserPins; //stores [card]: <userId,pin>
      std::string data_dir;

      void initialiseUserDB();
      void initialiseAccountDB();
      void printUserDB();


      void updateBalance(int account_num, int change_amount);

  public:
    Bank();

    //initialse - load user and account data
    Bank(string dir);
    //dir : directory location

    bool isCardValid(int card_number);

    //returns user id corresponding to card number
    int getUserId(int card_number);

    //get the user's name
    string getUserName(int user_id);

    //checks with the bank if the pin is correct for the user_id
    bool verifyUser(int user_id, int pin);

    //get the list of user's accounts -> can be multiple
    vector<int> getUserAccounts(int user_id);

    //get the account balance for the account number
    int getAccountBalance(int account_num);

    //check if can withdraw the requested amount
    bool checkIfCanWithdraw(int account_num,int withdraw_amount);

    //update user balance after withdrawing money : reduce balance by withdraw_amount
    void updateBalanceAfterWithdraw(int account_num, int withdraw_amount);

    //update user balance after depositing money : incraese balance by deposity amount
    void updateBalanceAfterDeposit(int account_num, int deposit_amount);
};
