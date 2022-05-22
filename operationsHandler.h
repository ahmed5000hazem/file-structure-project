#include "operaions.h"

void displayOperationsOptions (short int operation) {
    switch (operation)
    {
    case 1:
        cout<<"what do you want form workers ?\n";
        cout<<"-------------------------------\n";
        cout<<"to create worker Enter (1) \n\n";
        cout<<"to list all the workers Enter (2) \n\n";
        cout<<"to find worker Enter (3) \n\n";
        cout<<"to search worker Enter (4) \n\n";
        cout<<"to update worker Enter (5) \n\n";
        cout<<"to delete worker Enter (6) \n\n";
        cout<<"to quit press Zero ... \n\n";
        cout<<"\n";
        break;
    case 2:
        cout<<"what do you want form products ?\n";
        cout<<"-------------------------------\n";
        cout<<"to create product Enter (1) \n\n";
        cout<<"to list all the products Enter (2) \n\n";
        cout<<"to find product Enter (3) \n\n";
        cout<<"to search product Enter (4) \n\n";
        cout<<"to update product Enter (5) \n\n";
        cout<<"to delete product Enter (6) \n\n";
        cout<<"to quit press Zero ... \n\n";
        cout<<"\n";
        break;
    case 3:
        cout<<"what do you want form orders ?\n";
        cout<<"-------------------------------\n";
        cout<<"to create order Enter (1) \n\n";
        cout<<"to list all the orders Enter (2) \n\n";
        cout<<"to find order Enter (3) \n\n";
        cout<<"to update order Enter (4) \n\n";
        cout<<"to delete order Enter (5) \n\n";
        cout<<"to quit enter Zero ... \n\n";
        cout<<"\n";
        break;
        
    default:
        break;
    }
}

void handleWorkerOperations(short int workerOperation){
    switch (workerOperation)
    {
    case 1:
        createWorker();
        break;
    case 2:
        listWorkers();
        break;
    case 3:
        findWorker();
        break;
    case 4:
        searchWorker();
        break;
    case 5:
        updateWorker();
        break;
    case 6:
        removeWorker();
        break;
    default:
        break;
    }
}
void handleProductOperations(short int productOperation){
    switch (productOperation)
    {
    case 1:
        createProduct();
        break;
    case 2:
        listProducts();
        break;
    case 3:
        findProduct();
        break;
    case 4:
        searchProduct();
        break;
    case 5:
        updateProduct();
        break;
    case 6:
        removeProduct();
        break;
    default:
        break;
    }
}

void handleOrderOperations(short int orderOperation){
switch (orderOperation)
    {
    case 1:
        createOrder();
        break;
    case 2:
        listOrders();
        break;
    case 3:
        findOrder();
        break;
    case 4:
        updateOrder();
        break;
    case 5:
        removeOrder();
        break;
    default:
        break;
    }
}