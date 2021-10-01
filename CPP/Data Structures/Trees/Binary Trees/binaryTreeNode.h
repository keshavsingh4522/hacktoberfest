template <typename t>
class binarynode {
    public:
    t data;
    binarynode <t> * left;   
    binarynode <t> * right;  
    
    binarynode(t data){
        this -> data = data;
        left = right = NULL;
    }
    ~binarynode(){ 
        delete left;
        delete right;
    }

};