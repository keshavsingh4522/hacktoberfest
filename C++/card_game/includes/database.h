#pragma once
#include<string>

class DataBase{

private:
    static DataBase* instance;
public:
    DataBase();
    Init();
    Execute(string);
    Close();


};