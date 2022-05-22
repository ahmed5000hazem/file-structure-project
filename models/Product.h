#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
// #include "bootstraping.h"
using namespace std;

class Product
{
private:
    short int id;
    string name;
    string color;
    short int price;
    string size;
public:
    Product(short int id, string name, string color, short int price, string size);
    ~Product();

    void print();
    Product create(string rec);
    string makeRecord(short int recStatus);
    static void all();
    static Product find(short int product_id);
    static Product search(string productName);
    static void remove(short int product_id);
    void update(string name, string color, short int price, string size);
};

Product::Product(short int id, string name, string color, short int price, string size)
{
    this->id = id;
    this->name = name;
    this->color = color;
    this->price = price;
    this->size = size;
}

Product::~Product()
{
}

void Product::print(){
    cout<<"id is : "<<this->id<<endl;
    cout<<"name is : "<<this->name<<endl;
    cout<<"color is : "<<this->color<<endl;
    cout<<"price is : "<<this->price<<endl;
    cout<<"size is : "<<this->size<<endl;
}

Product Product::create(string rec) {

    const string path = GENERATE_PATH("stores/products.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream productFile;
    productFile.open(char_array, ios::app | ios::out | ios::binary);

    if (productFile.is_open()){
        char *mem_block = new char[rec.length() + 1];
        strcpy(mem_block, rec.c_str());
        productFile.write(mem_block, rec.length());
        productFile.close();
    }
    
}

string Product::makeRecord(short int recStatus = 1){
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
    rec += name + ',';
    rec += color + ',';
    rec += to_string(price) + ',';
    rec += size + ','+ '\n';

    return rec;
}

void Product::all() {
    const string path = GENERATE_PATH("stores/products.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream productFile;
    productFile.open(char_array, ios::in | ios::binary);

    if (productFile.is_open()) {
        while (1)
        {
            if (productFile.eof()) 
                break;
            
            string product;
            getline(productFile, product, '\n');
            if (product == "") break;
            
            std::istringstream iss(product);
            
            string arr[6];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }
            
            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            string name = arr[2];
            string color = arr[3];
            short int price = stoi(arr[4]);
            string size = arr[5];

            Product p(id, name, color, price, size);
            p.print();
            cout<<"##################################"<<endl;
            
        }
        productFile.close();
    }
}

Product Product::find(short int product_id){
    const string path = GENERATE_PATH("stores/products.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream productFile;
    productFile.open(char_array, ios::in | ios::binary);

    if (productFile.is_open()) {
        bool exists = false;
        while (1)
        {
            if (productFile.eof()) break;
            
            string worker;
            getline(productFile, worker, '\n');
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
            string name = arr[2];
            string color = arr[3];
            short int price = stoi(arr[4]);
            string size = arr[5];

            if (id == product_id) {
                Product p(id, name, color, price, size);
                return p;
            }

            
        }
        if (!exists) cout<< "\nproduct not found\n"<<endl;
        productFile.close();
        Product p(0, "", "", 0, 0);
        return p;
    }
}

Product Product::search(string productName){
    const string path = GENERATE_PATH("stores/products.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream productFile;
    productFile.open(char_array, ios::in | ios::binary);

    if (productFile.is_open()) {
        bool exists = false;
        while (1)
        {
            if (productFile.eof()) break;
            
            string worker;
            getline(productFile, worker, '\n');
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
            string name = arr[2];
            string color = arr[3];
            short int price = stoi(arr[4]);
            string size = arr[5];

            if (!name.compare(productName)) {
                Product p(id, name, color, price, size);
                return p;
            }

            
        }
        if (!exists) cout<< "\nproduct not found\n"<<endl;
        productFile.close();
        Product p(0, "", "", 0, 0);
        return p;
        
    }
}

void Product::remove(short int product_id){
    const string path = GENERATE_PATH("stores/products.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream productFile;
    productFile.open(char_array);

    if (productFile.is_open()) {
        bool exists = false;
        int readPos = 0;
        while (1)
        {
            if (productFile.eof())
                break;
            
            string worker;
            readPos = productFile.tellg();
            getline(productFile, worker, '\n');
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
            string name = arr[2];
            string color = arr[3];
            short int price = stoi(arr[4]);
            string size = arr[5];

            if (id == product_id) {
                break;
                exists = true;
            }
            
        }

        productFile.seekp(readPos);
        productFile.write("!", 1);
        readPos = productFile.tellp();

        productFile.close();
    }
}

void Product::update(string name, string color, short int price, string size){
    short int id = this->id;

    this->name = name;
    this->color = color;
    this->price = price;
    this->size = size;

    remove(id);
    Product p(id, name, color, price, size);
    string rec = p.makeRecord(2);
    p.create(rec);
}
