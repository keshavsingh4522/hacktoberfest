/*
CONVERT ROMAN NUMERALS TO INTEGER

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
class rtoi{
    public int romanToInt(String s) {
        
    int nl=s.length();
    int n[]=new int[nl];
        
        for(int i=0;i<nl;i++){
            switch(s.charAt(i)){
                //Match case and assign value 
                case 'M':n[i]=1000;
                    break;
                case 'D':n[i]=500;
                    break;
                case 'C':n[i]=100;
                    break;
                case 'L':n[i]=50;
                    break;
                case 'X':n[i]=10;
                    break;
                case 'V':n[i]=5;
                    break;
                case 'I':n[i]=1;
                    break;
                
            }
        }
        int sum=0;
      //based on next element add or subtract the value
        for(int i=0;i<nl-1;i++){
            if(n[i]<n[i+1])
                sum-=n[i];
                else
                    sum+=n[i];
            
        }
        return sum+n[nl-1];
        
    }
}
