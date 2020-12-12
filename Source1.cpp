#include <iostream>
#include <string>
#include "Smart.h"


void main()
{
    Smartphones OnePlus("OnePlus 7Pro", "4", "459", "+380964657844", "4000", "6");
    Smartphones Samsung("Samsung SM76B", "8", "799", "+380986557844B", "3000", "8");
    Smartphones Vivo("Vivo NEX", "6", "600", "+380938657844", "3200", "6");
    Smartphones OPPO("OPPO FindX", "4", "510", "+380672757844", "2800", "4");
    Smartphones Xiaomi("Xiaomi MiMixAlpha", "8", "1299", "+380987457844", "4100", "8");

    PhoneStore Store;
    Store.GetSmartphone(OnePlus,0);
    Store.GetSmartphone(Samsung,1);
    Store.GetSmartphone(Vivo,2);
    Store.GetSmartphone(OPPO,3);
    Store.GetSmartphone(Xiaomi,4);
   
    Store.GetBestPhoneAndListOfPhones();
}
