#include <iostream>
#include <string>
#include "Smart.h"


void main()
{
    setlocale(LC_ALL, "");
    std::string Mob_numb[5] = { "+380964657844","+380986557844B","+380938657844","+380672757844","+380987457844" };
    std::string name[5] = { "OnePlus 7Pro","Samsung SM76B","Vivo NEX","OPPO FindX","Xiaomi MiMixAlpha" };
    Smartphones OnePlus(name[0], "4", "459", Mob_numb[0], "4000", "6");
    Smartphones Samsung(name[1], "8", "799", Mob_numb[1], "3000", "8");
    Smartphones Vivo(name[2], "6", "600", Mob_numb[2], "3200", "6");
    Smartphones OPPO(name[3], "4", "510", Mob_numb[3], "2800", "4");
    Smartphones Xiaomi(name[4], "8", "1299", Mob_numb[4], "4100", "8");

    PhoneStore Store;
    Store.get(OnePlus,0);
    Store.get(Samsung,1);
    Store.get(Vivo,2);
    Store.get(OPPO,3);
    Store.get(Xiaomi,4);
   
    Store.get_best_phn_and_list();
}
