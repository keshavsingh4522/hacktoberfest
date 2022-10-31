// Example: Generic List

Collection_name <data_type> identifier= new Collection_name<data_type>

void main() { 
   List <String> logTypes = new List <String>(); 
   logTypes.add("WARNING"); 
   logTypes.add("ERROR"); 
   logTypes.add("INFO");  
   
   // iterating across list 
   for (String type in logTypes) { 
      print(type); 
   } 
}




