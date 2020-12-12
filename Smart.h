#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;
class PhoneStore;
class Smartphones {
private:
    string smartphone_model;
    string smartphone_RAM;
    string smartphone_price;
    string smartphone_mobile_number;
    string smartphone_battery_capacity;
    string smartphone_cores;

public:
    friend PhoneStore;

    Smartphones(string smartphone_model, string smartphone_RAM, string smartphone_price, string smartphone_mobile_number, string smartphone_battery_capacity, string smartphone_cores) {
        this->smartphone_model = smartphone_model;
        this->smartphone_RAM = smartphone_RAM;
        this->smartphone_price = smartphone_price;
        this->smartphone_mobile_number = smartphone_mobile_number;
        this->smartphone_battery_capacity = smartphone_battery_capacity;
        this->smartphone_cores = smartphone_cores;
    }
};

class PhoneStore { 

private:
    string smartphone[5][7];

public:
    friend Smartphones;

    void GetSmartphone(Smartphones &phone, int smartphone_number) {
        smartphone[smartphone_number][0] = phone.smartphone_model;
        smartphone[smartphone_number][1] = phone.smartphone_RAM;
        smartphone[smartphone_number][2] = phone.smartphone_price;
        smartphone[smartphone_number][3] = phone.smartphone_mobile_number;
        smartphone[smartphone_number][4] = phone.smartphone_battery_capacity;
        smartphone[smartphone_number][5] = phone.smartphone_cores;
    }

    void GetBestPhoneAndListOfPhones() {
        float budget = 2000;
        int temporary_value;
        int smartphone_rating[5] = {0,0,0,0,0};
        temporary_value = stoi(smartphone[0][1]);
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) < budget) {
                if (stoi(smartphone[i][1]) > temporary_value) {
                    temporary_value = stoi(smartphone[i][1]);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][1]) == temporary_value) {
                smartphone_rating[i]++;
            }
        }

        temporary_value = budget;
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) <= budget) {
                if (stoi(smartphone[i][2]) < temporary_value) {
                    temporary_value = stoi(smartphone[i][2]);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) == temporary_value) {
                smartphone_rating[i]++;
            }
        }

        temporary_value = stoi(smartphone[0][4]);
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) <= budget) {
                if (stoi(smartphone[i][4]) > temporary_value) {
                    temporary_value = stoi(smartphone[i][4]);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][4]) == temporary_value) {
                smartphone_rating[i]++;
            }
        }

        temporary_value = stoi(smartphone[0][5]);
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) <= budget) {
                if (stoi(smartphone[i][5]) > temporary_value) {
                    temporary_value = stoi(smartphone[i][5]);
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][5]) == temporary_value) {
                smartphone_rating[i]++;
            }
        }

        int best_smartphone_rating = 0;
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) <= budget) {
                if (smartphone_rating[i] > best_smartphone_rating) {
                    best_smartphone_rating = smartphone_rating[i];
                }
            }
        }

        cout << "Budget: " << budget << "$" << endl << endl;
        cout << "Smartphone(s) with best rating: " << endl;
        for (int i = 0; i < 5; i++) {
            if (stoi(smartphone[i][2]) <= budget) {
                if (smartphone_rating[i] == best_smartphone_rating) {
                    cout << smartphone[i][0] << "   rating: " << smartphone_rating[i] << endl;
                }
            }
        }

        cout << endl;
        list<float> phone_list;
        int lowest_price = stoi(smartphone[0][2]);
        int temporary_lowest_price = 0;
        cout << "List from lower to bigger price: " << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (stoi(smartphone[j][2]) < lowest_price && stoi(smartphone[j][2]) > temporary_lowest_price) {
                    lowest_price = stoi(smartphone[j][2]);
                }
            }
            phone_list.push_back(lowest_price);
            temporary_lowest_price = lowest_price;
            lowest_price = 9999;
        }

        for (list<float>::iterator cost = phone_list.begin(); cost != phone_list.end(); ++cost)
        {
            for (int k = 0; k < 5; k++) {
                if (stoi(smartphone[k][2]) == *cost) {
                    cout << smartphone[k][0] << "   " << *cost << " $ " << endl;
                }
            }
        }
    };
};
