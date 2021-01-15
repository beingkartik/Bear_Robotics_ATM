#pragma once

class CashBin{

  private:

    int total_cash_in_bin;

    void updateCashInBin(int change_amount);

  public:

    CashBin();
    CashBin(int starting_cash);

    void setCashinBin(int starting_cash);
    int getCashInBin();

    void dispenseCash(int dispense_amount);

    //returns the amount of money detected by the sensor
    //in our controller, this always returns the deposit_amount
    int acceptCash(int deposit_amount);

};
