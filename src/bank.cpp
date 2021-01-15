#include "bank.h"
//int Bank::var = 20;
#include <string>
#include <sstream>
#include <fstream>

Bank::Bank():Bank(".."){
//cout <<"222thisis" << data_dir<<"22p";


//    printUserDB();
}

Bank::Bank(string dir):data_dir(dir){

    initialiseUserDB();
    initialiseAccountDB();
//    var = a;
}

void Bank::initialiseUserDB(){

//    cout <<"222thisis" << data_dir<<"22p";
    std::string filename = data_dir + "/data/user_data.csv";
    cout << data_dir<<" "<<filename <<endl;
    std::ifstream myFile(filename);

    std::string line, colname;

    if(!myFile.is_open()) {
        cout<<"Could not open file"<<endl;
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()){

        std::getline(myFile, line);
        std::stringstream ss(line);
        cout << "Loading Data- ";
        while(std::getline(ss, colname, ',')){

            cout << colname<<" ";
            // Initialize and add <colname, int vector> pairs to result
//            result.push_back({colname, std::vector<int> {}});
        }
        cout << endl;
     }

     int val;
     vector<int>row;
     while(std::getline(myFile,line)){
        std::stringstream ss(line);
        row.clear();
        while(ss>>val){
            row.push_back(val);
//            cout << val << " " ;
            if(ss.peek() == ',' ) ss.ignore();
            if(ss.peek() == '[' || ss.peek() == ']') {
//                cout << (char)ss.peek();
                ss.ignore();
            }

        }
//        cout <<endl;
        cardUserPins[row[0]] = make_pair(row[1],row[2]);
        for(auto account=row.begin()+3; account < row.end(); account++){
            userAccounts[row[1]].push_back(*account);
        }

    }

//    cardUsers[1234] = 1;
//    cardUsers[3456] = 2;
//    cardUsers[3478] = 3;
//    cardUsers[2346] = 4;
//    cardUsers[3458] = 5;
//    cardUsers[2397] = 6;
//    userAccounts[1].push_back(2000);
//    userAccounts[1].push_back(4000);
//    userAccounts[1].push_back(3000);
//    userAccounts[2].push_back(100);
//    userAccounts[2].push_back(200);
//    userAccounts[3].push_back(99);
//    userAccounts[4].push_back(292);
//    userAccounts[4].push_back(291);
//    userAccounts[5].push_back(199);
//    userAccounts[6].push_back(299);
//
//    cardPins[1] = 1;
//    cardPins[2] = 4;
//    cardPins[3] = 6;
//    cardPins[4] = 2;
//    cardPins[5] = 3;
//    cardPins[6] = 6;

}

void Bank::printUserDB(){

        for (auto user:userAccounts){
            cout << user.first << " " ;
            for(auto acc:user.second){
                cout << acc << ":"<<accountsDB[acc] <<" ";
            }
            cout << endl;
        }

    }


void Bank::initialiseAccountDB(){

    std::string filename = "../data/account_balance.csv";
    std::ifstream myFile(filename);

    std::string line, colname;

    if(!myFile.is_open()) {
        cout<<"Could not open file"<<endl;
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()){

        std::getline(myFile, line);
        std::stringstream ss(line);
        cout << "Loading Data- ";
        while(std::getline(ss, colname, ',')){

            cout << colname<<" ";
            // Initialize and add <colname, int vector> pairs to result
//            result.push_back({colname, std::vector<int> {}});
        }
        cout << endl;
     }

     int val;
     vector<int>row;
     while(std::getline(myFile,line)){
        std::stringstream ss(line);
        row.clear();
        while(ss>>val){
            row.push_back(val);
//            cout << val << " " ;
            if(ss.peek() == ',' ) ss.ignore();
        }
//        cout <<endl;
        accountsDB[row[0]] = row[1];
    }

//        accountsDB[2000] = 1000;
//        accountsDB[4000] = 1002;
//        accountsDB[3000] =  202;
//        accountsDB[100] = 2021;
//        accountsDB[200] = 212;
//        accountsDB[99] = 201;
//        accountsDB[292] = 10011;
//        accountsDB[291] = 12223;
//        accountsDB[199] = 5545;
//        accountsDB[299] = 4465;

}


bool Bank::isCardValid(int card_number){

    if(cardUserPins.find(card_number)!=cardUserPins.end()){
        return true;
    }else{
        return false;
    }
}

int Bank::getUserId(int card_number){

    return cardUserPins[card_number].first;
}

    //get the user's name
string Bank::getUserName(int user_id){

    return "Sample User";

}



    //checks with the bank if the pin is correct for the user_id
bool Bank::verifyUser(int card_number, int pin){

    return cardUserPins[card_number].second == pin;

}

    //get the list of user's accounts -> can be multiple
vector<int> Bank::getUserAccounts(int user_id){

    return userAccounts[user_id];
}


    //get the account balance for the account number
int Bank::getAccountBalance(int account_num){

    return accountsDB[account_num];

}

    //check if can withdraw the requested amount
bool Bank::checkIfCanWithdraw(int account_num,int withdraw_amount){

    return getAccountBalance(account_num) >= withdraw_amount;
}



void Bank::updateBalance(int account_num, int change_amount){

    accountsDB[account_num] += change_amount;
}

    //update user balance after withdrawing money : reduce balance by withdraw_amount
void Bank::updateBalanceAfterWithdraw(int account_num, int withdraw_amount){

    updateBalance(account_num,-withdraw_amount);

}

    //update user balance after depositing money : incraese balance by deposity amount
void Bank::updateBalanceAfterDeposit(int account_num, int deposit_amount){

    updateBalance(account_num,deposit_amount);
}

