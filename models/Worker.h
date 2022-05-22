#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
// #include "bootstraping.h"
using namespace std;

class Worker
{
private:
    short int id;
    string name;
    bool role; // true means manager false means normal Worker
    short int sallary;
public:
    Worker(short int id, string name, bool role, short int salary);
    ~Worker();

    void print();
    string makeRecord(short int recStatus);
    Worker create(string rec);
    static void all();
    static Worker find(short int worker_id);
    static Worker search(string workerName);
    static void remove(short int worker_id);
    void update(string name, bool role, short int salary);

};

Worker::Worker(short int id, string name, bool role, short int sallary)
{
    this->id = id;
    this->name = name;
    this->role = role;
    this->sallary = sallary;
}

Worker::~Worker()
{
}

void Worker::print(){
    cout<<"Worker id is : "<<id<<"\n";
    cout<<"Worker name is : "<<name<<"\n";
    role ? cout<<"Worker role is : manager \n" : cout<<"Worker role is : normal worker \n";
    cout<<"Worker sallary is : "<<sallary<<endl;
}

Worker Worker::create(string rec) {

    const string path = GENERATE_PATH("stores/workers.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream workerFile;
    workerFile.open(char_array, ios::app | ios::out | ios::binary );

    if (workerFile.is_open()){
        char *mem_block = new char[rec.length() + 1];
        strcpy(mem_block, rec.c_str());
        workerFile.write(mem_block, rec.length());
    }
    workerFile.close();
    
}

string Worker::makeRecord(short int recStatus = 1){ 

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
    rec += to_string(role) + ',';
    rec += to_string(sallary) + ','+ '\n';

    return rec;
}

void Worker::all() {
    const string path = GENERATE_PATH("stores/workers.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream workerFile;
    workerFile.open(char_array, ios::in | ios::binary);

    if (workerFile.is_open()) {
        while (1)
        {
            if (workerFile.eof()) 
                break;
            
            string worker;
            getline(workerFile, worker, '\n');
            if (worker == "") break;
            
            std::istringstream iss(worker);
            
            string arr[5];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }
            
            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            string name = arr[2];
            short int role = stoi(arr[3]);
            short int sallary = stoi(arr[4]);

            Worker w(id, name, role, sallary);
            w.print();
            cout<<"##################################"<<endl;
            
        }
        workerFile.close();
    }
}

Worker Worker::find(short int worker_id){
    const string path = GENERATE_PATH("stores/workers.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream workerFile;
    workerFile.open(char_array, ios::in | ios::binary);

    if (workerFile.is_open()) {
        bool exists = false;
        while (1)
        {
            if (workerFile.eof()) break;
            
            string worker;
            getline(workerFile, worker, '\n');
            if (worker == "") break;
            
            std::istringstream iss(worker);
            
            string arr[5];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }

            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            string name = arr[2];
            short int role = stoi(arr[3]);
            short int sallary = stoi(arr[4]);

            if (id == worker_id) {
                Worker w(id, name, role, sallary);
                return w;
            }

            
        }
        if (!exists) cout<< "\nworker not found\n"<<endl;
        workerFile.close();
        Worker w(0, "", 0, 0);
        return w;
    }
}

Worker Worker::search(string workerName){
    const string path = GENERATE_PATH("stores/workers.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream workerFile;
    workerFile.open(char_array, ios::in | ios::binary);

    if (workerFile.is_open()) {
        bool exists = false;
        while (1)
        {
            if (workerFile.eof()) break;
            
            string worker;
            getline(workerFile, worker, '\n');
            if (worker == "") break;
            
            std::istringstream iss(worker);
            
            string arr[5];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }

            if (arr[0][0] == '!') continue;

            short int id = stoi(arr[1]);
            string name = arr[2];
            short int role = stoi(arr[3]);
            short int sallary = stoi(arr[4]);
            if (!name.compare(workerName)) {
                Worker w(id, name, role, sallary);
                return w;
            }

            
        }
        if (!exists) cout<< "\nworker not found\n"<<endl;
        workerFile.close();
        Worker w(0, "", 0, 0);
        return w;
    }
}

void Worker::remove(short int worker_id){
    const string path = GENERATE_PATH("stores/workers.txt");
    
    char char_array[path.length() + 1];
    strcpy(char_array, path.c_str());

    fstream workerFile;
    workerFile.open(char_array);

    if (workerFile.is_open()) {
        bool exists = false;
        int readPos = 0;
        while (1)
        {
            if (workerFile.eof())
                break;
            
            string worker;
            readPos = workerFile.tellg();
            getline(workerFile, worker, '\n');
            if (worker == "") break;
            
            std::istringstream iss(worker);
            
            string arr[5];
            int i = 0;
            for (std::string token; std::getline(iss, token, ','); )
            {
                arr[i] = token;
                i++;
            }
            
            if (arr[0][0] == '!') continue;
            
            short int id = stoi(arr[1]);
            string name = arr[2];
            short int role = stoi(arr[3]);
            short int sallary = stoi(arr[4]);

            if (id == worker_id) {
                break;
                exists = true;
            }

            
        }

        workerFile.seekp(readPos);
        workerFile.write("!", 1);
        readPos = workerFile.tellp();

        workerFile.close();
        
    }
}

void Worker::update(string name, bool role, short int salary){
    short int id = this->id;
    this->name = name;
    this->role = role;
    this->sallary = sallary;

    remove(this->id);
    Worker w(this->id, name, role, salary);
    string rec = w.makeRecord(2);
    w.create(rec);
}