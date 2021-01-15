#pragma once//  Ensure file is included only once
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
//using namespace std::endl;
class Tools{
private:
    std::unordered_map<int,std::vector<int>>userDataBase;
    std::unordered_map<int,long>accountsDB;

public:
    int a;
    void MakeItSunny();
    void MakeItRain();

    void initialiseUserDB(){
    userDataBase[1].push_back(2000);
    userDataBase[1].push_back(4000);
    userDataBase[1].push_back(3000);
    userDataBase[2].push_back(100);
    userDataBase[2].push_back(200);
    userDataBase[3].push_back(99);
    userDataBase[4].push_back(292);
    userDataBase[4].push_back(291);
    userDataBase[5].push_back(199);
    userDataBase[6].push_back(299);
    }

    void printUserDB(){

        for (auto user:userDataBase){
            cout << user.first << " " ;
            for(auto acc:user.second){
                cout << acc << ":"<<accountsDB[acc] <<" ";
            }
            cout << endl;
        }

    }


    void initialiseAccountDB(){

        accountsDB[2000] = 1000;
        accountsDB[4000] = 1002;
        accountsDB[3000] =  202;
        accountsDB[100] = 2021;
        accountsDB[200] = 212;
        accountsDB[99] = 201;
        accountsDB[292] = 10011;
        accountsDB[291] = 12223;
        accountsDB[199] = 5545;
        accountsDB[299] = 4465;

    }

};
