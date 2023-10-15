class MinStack {
     static Stack<Integer> s;
     static Stack<Integer> ss;

    public MinStack() {
         s=new Stack<>();
         ss=new Stack<>();
    }
    //push function implementation
    public void push(int val) {
        s.push(val);
        if(ss.size()==0 || ss.peek()>=val){
            ss.push(val);
        }
    }
    //pop function implementation
    public void pop() {
        if(s.size()==0) return ;
        
        int ans=s.peek();
        s.pop();
        if(ss.peek()==ans) ss.pop();
    
    }
    //top function implementation 
    public int top() {
        if(s.size()==0) return -1;
        return s.peek();
    }
   //getting minimum value from stack in O(1)  
    public int getMin() {
        if(ss.size()==0) return -1;
        
        return ss.peek();
    }
}
