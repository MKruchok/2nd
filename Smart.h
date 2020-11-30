#pragma once
#include <iostream>
#include <string>
#include <list>

class PhoneStore;

class Smartphones {
private:
    std::string model;
    std::string RAM;
    std::string Price;
    std::string Mob_num;
    std::string Bat_cap;
    std::string Core_num;
public:
    friend PhoneStore;
    Smartphones() {
    }

    Smartphones(std::string smart_model, std::string smart_RAM, std::string smart_price, std::string smart_MNUM, std::string smart_BCAP, std::string smart_CNUM) {
        model = smart_model;
        RAM = smart_RAM;
        Price = smart_price;
        Mob_num = smart_MNUM;
        Bat_cap = smart_BCAP;
        Core_num = smart_CNUM;
    }

};


class PhoneStore {
private:
    std::string Smart[5][7];
public:
    friend Smartphones;
    PhoneStore() {
    }

    void get(Smartphones &smart, int num) {
        Smart[num][0] = smart.model;
        Smart[num][1] = smart.RAM;
        Smart[num][2] = smart.Price;
        Smart[num][3] = smart.Mob_num;
        Smart[num][4] = smart.Bat_cap;
        Smart[num][5] = smart.Core_num;
    }

    void get_best_phn_and_list() {
        float budget = 2000;
        int temp_v;
        int SmartR[5] = {0,0,0,0,0};
        temp_v = std::stoi(Smart[0][1]);
        //RAM
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) < budget) {
                if (std::stoi(Smart[i][1]) > temp_v) {
                    temp_v = std::stoi(Smart[i][1]);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][1]) == temp_v) {
                SmartR[i]++;
            }
        }
        //Price
        temp_v = budget;
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) <= budget) {
                if (std::stoi(Smart[i][2]) < temp_v) {
                    temp_v = std::stoi(Smart[i][2]);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) == temp_v) {
                SmartR[i]++;
            }
        }
        //Battery cap
        temp_v = std::stoi(Smart[0][4]);
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) <= budget) {
                if (std::stoi(Smart[i][4]) > temp_v) {
                    temp_v = std::stoi(Smart[i][4]);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][4]) == temp_v) {
                SmartR[i]++;
            }
        }
        //Core num
        temp_v = std::stoi(Smart[0][5]);
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) <= budget) {
                if (std::stoi(Smart[i][5]) > temp_v) {
                    temp_v = std::stoi(Smart[i][5]);
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][5]) == temp_v) {
                SmartR[i]++;
            }
        }
        //Best rating
        int BestR = 0;
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) <= budget) {
                if (SmartR[i] > BestR) {
                    BestR = SmartR[i];
                }
            }
        }
        std::cout << "Бюджет: " << budget << "$" << std::endl << std::endl;
        std::cout << "Смартфон(и) з найкращим рейтингом: " << std::endl;
        for (int i = 0; i < 5; i++) {
            if (std::stoi(Smart[i][2]) <= budget) {
                if (SmartR[i] == BestR) {
                    std::cout << Smart[i][0] << "   рейтинг: " << SmartR[i] << std::endl;
                }
            }
        }
        std::cout << std::endl;

        std::list<float> phnlist;
        int low_num = std::stoi(Smart[0][2]);
        int temp_low = 0;
        std::cout << "Лист вiд найдешевшого до найдорожчого: " << std::endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (std::stoi(Smart[j][2]) < low_num && std::stoi(Smart[j][2]) > temp_low) {
                    low_num = std::stoi(Smart[j][2]);
                }
            }
            phnlist.push_back(low_num);
            temp_low = low_num;
            low_num = 9999;
        }
        for (std::list<float>::iterator cost = phnlist.begin(); cost != phnlist.end(); ++cost)
        {
            for (int k = 0; k < 5; k++) {
                if (std::stoi(Smart[k][2]) == *cost) {
                    std::cout << Smart[k][0] << "   " << *cost << " $ " << std::endl;
                }
            }
        }
    };
};






