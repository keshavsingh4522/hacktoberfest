// Implementation of List

void main() { 
   List logTypes = new List(); 
   logTypes.add("WARNING"); 
   logTypes.add("ERROR"); 
   logTypes.add("INFO");  
   
   // iterating across list 
   for(String type in logTypes){ 
      print(type); 
   } 
   
   // printing size of the list 
   print(logTypes.length); 
   logTypes.remove("WARNING"); 
   
   print("size after removing."); 
   print(logTypes.length); 
}
