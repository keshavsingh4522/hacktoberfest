Design a data-structure SpecialStack that supports all the stack operations like push(), pop()
and an additional operation getMin() which should return minimum element from the SpecialStack.

//Approach 1 : Use another stack to store min elements  => SC : O(1)

//Better approach : SC O(1) 

int minEle; //global variable

void push(stack<int>& s, int a){
	if(s.size()==0){
	    s.push(a);
	    minEle = a;
	}
	else{
	    if(a<=minEle){ 
	        s.push(2*a - minEle);       //acts like a flag coz ele we r pushing would be < minEle
	        minEle = a;
	    }
	    else
	        s.push(a);
	}
}

int pop(stack<int>& s){
    int x = top(s);
	if(x<=minEle){                  //acts like a flag coz ele we r poping would be < minEle, so we can assure that minEle is the actual element
	    minEle = 2*minEle - x;
	    s.pop();
	    return minEle;
	}
	s.pop();
	return x;
}

int getMin(stack<int>& s){
    if(s.size()==0)
        return -1;
    return minEle;
}
int top(stack<int>& s){
    if(s.size()==0)
        return -1;
    else{
        if(s.top()<minEle)      //acts like a flag
            return minEle;
        else
            return s.top();
    }
}
