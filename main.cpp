#include<iostream>
#include "models/bootstraping.h"
#include "models/Worker.h"
#include "models/Product.h"
#include "models/Order.h"
using namespace std;

int main () {
    
    Order o(2, 3, 4, "01010592308", "15/may/2022");
    string s = o.makeRecord();
    // o.create(s);

    // Order o2 = Order::find(1);
    // o2.print();

    
    
    return 0;
}