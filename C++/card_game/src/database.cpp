#include<string>
#include<sqlite3>

DataBase::DataBase(){
    
    sqlite3* database;
    int connetionStatus = 0;
    connetionStatus = sqlite3_open("./../assets/blackmoon.db", &database);
  
    if (connetionStatus) {
        std::cout<<red<< "Failed opening the database..." << std::endl;
        return (-1);
    }

}

DataBase::getInstance(){
    if(this->instance == NULL){
        this->Instance = new DataBase();
    }
}