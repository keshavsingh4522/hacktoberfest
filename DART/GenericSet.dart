//Example: Generic Set

Collection_name <data_type> identifier= new Collection_name<data_type> 

void main() { 
   Set <int>numberSet = new  Set<int>(); 
   numberSet.add(100); 
   numberSet.add(20); 
   numberSet.add(5); 
   numberSet.add(60);
   numberSet.add(70); 
   
   // numberSet.add("Tom"); 
   compilation error; 
   print("Default implementation  :${numberSet.runtimeType}");  
   
   for(var no in numberSet) { 
      print(no); 
   } 
} 


//test3
