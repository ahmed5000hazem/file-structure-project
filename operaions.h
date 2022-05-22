void createWorker(){

    short int id;
    string name;
    bool role; // true means manager false means normal Worker
    short int sallary;
    
    cout<<"enter the worker id : ";
    cin>>id;
    
    cout<<"enter the worker name :";
    cin>>name;
    char roleChar;
    cout<<"is he a manager ? (Y or N) : ";
    cin>>roleChar;
    
    if (roleChar == 'y' || roleChar == 'Y'){ 
        role = true;
    } else {
        role = false;
    }
    cout<<"enter the worker sallary : ";
    cin>>sallary;

    Worker w(id, name, role, sallary);
    string rec = w.makeRecord();
    w.create(rec);
}

void listWorkers(){
    Worker::all();
}

void findWorker(){
    short id;
    cout<<"enter the worker id: ";
    cin >> id;
    Worker w = Worker::find(id);
    w.print();
}

void searchWorker(){
    string name;
    cout<<"enter the worker name: ";
    cin >> name;
    Worker w = Worker::search(name);
    w.print();
}

void updateWorker() {
    
    short int id;
    cout<<"enter the worker id to update : ";
    cin>>id;

    Worker w = Worker::find(id);
    w.print();
    
    string name;
    bool role; // true means manager false means normal Worker
    short int sallary;
    
    cout<<"enter the new worker name : ";
    cin>>name;
    char roleChar;
    cout<<"is he a manager ? (Y or N) : ";
    cin>>roleChar;
    
    if (roleChar == 'y' || roleChar == 'Y'){ 
        role = true;
    } else {
        role = false;
    }
    cout<<"enter the new worker sallary : ";
    cin>>sallary;

    w.update(name, role, sallary);

    w.print();
}

void removeWorker() {
    short id;
    cout<<"enter the worker id to remove : ";
    cin >> id;
    Worker::remove(id);
}

// **************************** product section

void createProduct(){

    short int id;
    string name;
    string color;
    short int price;
    string size;
    
    cout<<"enter the product id : ";
    cin>>id;
    
    cout<<"enter the product name :";
    cin>>name;
    
    cout<<"enter the product color : ";
    cin>>color;

    cout<<"enter the product price : ";
    cin>>price;

    cout<<"enter the product size : ";
    cin>>size;

    Product p(id, name, color, price, size);
    string rec = p.makeRecord();
    p.create(rec);
}

void listProducts(){
    Product::all();
}

void findProduct(){
    
    short id;
    cout<<"enter the product id: ";
    cin >> id;
    Product p = Product::find(id);
    p.print();
}

void searchProduct(){
    string name;
    cout<<"enter the product name: ";
    cin >> name;
    Product p = Product::search(name);
    p.print();
}

void updateProduct() {
    
    short int id;
    cout<<"enter the product id to update : ";
    cin>>id;

    Product p = Product::find(id);
    p.print();
    
    string name;
    string color;
    short int price;
    string size;
    
    cout<<"enter the new product name : ";
    cin>>name;
    
    cout<<"enter the new product color : ";
    cin>>color;
    
    cout<<"enter the new product price : ";
    cin>>price;
    
    cout<<"enter the new product size : ";
    cin>>size;

    p.update(name, color, price, size);

    p.print();
}

void removeProduct() {
    short id;
    cout<<"enter the Product id to remove : ";
    cin >> id;
    Product::remove(id);
}

// **************************** product section

void createOrder(){

    short int id;
    short int worker_id;
    short int product_id;
    string customer_number;
    string date;
    
    cout<<"enter the Order id : ";
    cin>>id;
    
    cout<<"enter the Order worker_id :";
    cin>>worker_id;
    
    cout<<"enter the Order product_id : ";
    cin>>product_id;

    cout<<"enter the Order customer_number : ";
    cin>>customer_number;

    cout<<"enter the Order date : ";
    cin>>date;

    Order o(id, worker_id, product_id, customer_number, date);
    string rec = o.makeRecord();
    o.create(rec);
}

void listOrders(){
    Order::all();
}

void findOrder(){
    short id;
    cout<<"enter the order id: ";
    cin >> id;
    Order p = Order::find(id);
    p.print();
}

void updateOrder() {
    
    short int id;
    cout<<"enter the order id to update : ";
    cin>>id;

    Order o = Order::find(id);
    o.print();
    
    short int worker_id;
    short int product_id;
    string customer_number;
    string date;
    
    cout<<"enter the new order worker_id : ";
    cin>>worker_id;
    
    cout<<"enter the new order product_id : ";
    cin>>product_id;
    
    cout<<"enter the new order customer_number : ";
    cin>>customer_number;
    
    cout<<"enter the new order date : ";
    cin>>date;

    o.update(worker_id, product_id, customer_number, date);

    o.print();
}

void removeOrder() {
    short id;
    cout<<"enter the order id to remove : ";
    cin >> id;
    Order::remove(id);
}
