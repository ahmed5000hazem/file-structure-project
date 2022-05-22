#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
// #include "bootstraping.h"
using namespace std;

class Order
{
private:
    short int id;
    short int worker_id;
    short int product_id;
    string customer_number;
    string date;
public:
    Order(short int id, short int worker_id, short int product_id, string customer_number, string date);
    ~Order();

    void print();
    string makeRecord(short int recStatus);
    Order create(string rec);
    static void all();
    static Order find(short int order_id);
    static void remove(short int order_id);
    void update(short int worker_id, short int product_id, string customer_number, string date);
};

Order::Order(short int id, short int worker_id, short int product_id, string customer_number, string date)
{
    this->id = id;
    this->worker_id = worker_id;
    this->product_id = product_id;
    this->customer_number = customer_number;
    this->date = date;
}

Order::~Order()
{
}

void Order::print() {
    cout<<"order id is : "<<this->id<<endl;
    cout<<"order worker id is : "<<this->worker_id<<endl;
    cout<<"order product id is : "<<this->product_id<<endl;
    cout<<"customer number is : "<<this->customer_number<<endl;
    cout<<"order date is : "<<this->date<<endl;
}

Order Order::create(string rec) {

    const string path = GENERATE_PATH("stores/orders.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream orderFile;
    orderFile.open(char_array, ios::app | ios::out | ios::binary);

    if (orderFile.is_open()){
        char *mem_block = new char[rec.length() + 1];
        strcpy(mem_block, rec.c_str());
        orderFile.write(mem_block, rec.length());
        orderFile.close();
    }
    
}

string Order::makeRecord(short int recStatus = 1){ 
    // record status is an interger to identify the record status 
    //if it = 1 then it's new record if 2 it's updated record if 0 it's deleted record
    string rec = "";

    string metaData;

    switch (recStatus)
    {
    case 0:
        metaData = "!,"; // deleted record
        break;
    case 1:
        metaData = "@,"; // new record
        break;
    case 2:
        metaData = "$,"; // updated record
        break;
    default:
        metaData = "@,";
        
        break;
    }

    rec += metaData;
    rec += to_string(id) + ',';
    rec += to_string(worker_id) + ',';
    rec += to_string(product_id) + ',';
    rec += customer_number + ',';
    rec += date + ','+ '\n';

    return rec;
}

void Order::all() {
    const string path = GENERATE_PATH("stores/orders.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream orderFile;
    orderFile.open(char_array, ios::in | ios::binary);

    if (orderFile.is_open()) {
        while (1)
        {
            if (orderFile.eof()) 
                break;
            
            string worker;
            getline(orderFile, worker, '\n');
            if (worker == "") break;
            
            std::istringstream iss(worker);
            
            string arr[6];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }
            
            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            short int worker_id = stoi(arr[2]);
            short int product_id = stoi(arr[3]);
            string customer_number = arr[4]; 
            string date = arr[5]; 

            Order o(id, worker_id, product_id, customer_number, date);
            o.print();
            cout<<"##################################"<<endl;
            
        }
        orderFile.close();
    } else {
        cout<<"cannot open file";
    }
}

Order Order::find(short int order_id){
    const string path = GENERATE_PATH("stores/orders.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream orderFile;
    orderFile.open(char_array, ios::in | ios::binary);

    if (orderFile.is_open()) {
        bool exists = false;
        while (1)
        {
            if (orderFile.eof()) break;
            
            string order;
            getline(orderFile, order, '\n');
            if (order == "") break;

            std::istringstream iss(order);
            
            string arr[6];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }

            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            short int worker_id = stoi(arr[2]);
            short int product_id = stoi(arr[3]);
            string customer_number = arr[4]; 
            string date = arr[5]; 

            if (id == order_id) {
                Order o(id, worker_id, product_id, customer_number, date);
                return o;
            }

            
        }
        if (!exists) cout<< "\norder not found\n"<<endl;
        orderFile.close();
        Order o(0, 0, 0, 0, "");
        return o;
    }
}

void Order::remove(short int order_id){
    const string path = GENERATE_PATH("stores/orders.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream orderFile;
    orderFile.open(char_array);

    if (orderFile.is_open()) {
        bool exists = false;
        int readPos = 0;
        while (1)
        {
            if (orderFile.eof())
                break;
            
            string order;
            readPos = orderFile.tellg();
            getline(orderFile, order, '\n');
            if (order == "") break;
            
            std::istringstream iss(order);
            
            string arr[6];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }

            short int id = stoi(arr[1]);
            short int worker_id = stoi(arr[2]);
            short int product_id = stoi(arr[3]);
            string customer_number = arr[4]; 
            string date = arr[5]; 

            if (id == order_id) {
                break;
                exists = true;
            }

            
        }

        orderFile.seekp(readPos);
        orderFile.write("!", 1);
        readPos = orderFile.tellp();

        orderFile.close();
        
    }
}

void Order::update(short int worker_id, short int product_id, string customer_number, string date){
    short int id = this->id;

    this->worker_id = worker_id;
    this->product_id = product_id;
    this->customer_number = customer_number;
    this->date = date;

    remove(id);
    Order o(id, worker_id, product_id, customer_number, date);
    string rec = o.makeRecord(2);
    o.create(rec);
}
