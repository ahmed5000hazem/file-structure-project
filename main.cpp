#include<iostream>
#include "models/bootstraping.h"
#include "models/Worker.h"
#include "models/Product.h"
#include "models/Order.h"
#include "operationsHandler.h"
using namespace std;

int main () {

    /*
        opearations variable
        select which class or entity that you will work with
        
        1 for worker
        2 for product
        3 for order
    */
    
    short int operation;
    cout<<"\n\n\n\n\n\n";
    cout << "#################################\n";
    cout << "##### welcome to our store ######\n";
    cout << "#################################";
    cout<<"\n\n\n\n\n\n";

    while(1){
        
        cout<<"\n\n";
        cout<<"what do you want to work with: \n\n";
        cout<<"for workers enter (1) \n\n";
        cout<<"for products enter (2) \n\n";
        cout<<"for orders enter (3) \n\n";
        
        cin>>operation;
        switch (operation)
        {
        case 1:
            short int workerOperation;
            displayOperationsOptions(1); // to display the operations that the entity can do
            cin>>workerOperation;
            handleWorkerOperations(workerOperation); // to call the operations
            break;
        case 2:
            short int productOperation;
            displayOperationsOptions(2);
            cin>>productOperation;
            handleProductOperations(productOperation);
            break;
        case 3:
            short int orderOperation;
            displayOperationsOptions(3);
            cin>>orderOperation;
            handleOrderOperations(orderOperation);
            break;
        default:
            cout<<"error !!! \noperation is not esxist\n";
            break;
        }
    }
    
    return 0;
}