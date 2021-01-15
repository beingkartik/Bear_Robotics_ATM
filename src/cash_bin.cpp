#include "cash_bin.h"


CashBin::CashBin(){
}

CashBin::CashBin(int starting_cash):total_cash_in_bin(starting_cash){
}


void CashBin::setCashinBin(int starting_cash){
    total_cash_in_bin = starting_cash;
}


int CashBin::getCashInBin(){
    return total_cash_in_bin;
}

void CashBin::updateCashInBin(int change_amount){

    total_cash_in_bin += change_amount;

}
void CashBin::dispenseCash(int dispense_amount){

    //Interface with the cash bin to dispense

    //update the amount in bin
    updateCashInBin(-dispense_amount);
}

    //returns the amount of money detected by the sensor
    //in our controller, this always returns the deposit_amount
int CashBin::acceptCash(int deposit_amount){

    updateCashInBin(deposit_amount);

    //actually connects with the cash bin
    return deposit_amount;
}
