#include <iostream>
//#include "bank.h"
//#include "cash_bin.h"
#include "atm.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(int argc, char** argv){

    cout <<"hello world"<<endl;
//    ttl.MakeItRain();

    int starting_amount_in_bank = 10000;
    string data_dir = "..";

    if(argc==2){
        starting_amount_in_bank = std::stoi(argv[1]);
    }

    ATM my_atm(starting_amount_in_bank ,data_dir);


    //mimicking a real ATM, this never shuts off naturally, always ready to "read a card"
    while(1){
        my_atm.startAtmFromStart();
    }
}
