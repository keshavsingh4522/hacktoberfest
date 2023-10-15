#include<vector>
using namespace std;

template <typename t>
class treenode{
    public:
    t data;
    vector <treenode<t>*> children; 
    
    treenode(t data){
        this -> data = data;
    }
    
    ~treenode(){
        for (int i =0;i<children.size();i++){
            delete children[i];
        }
    }
};