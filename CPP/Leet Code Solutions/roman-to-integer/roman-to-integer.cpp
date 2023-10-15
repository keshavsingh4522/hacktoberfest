class Solution {
public:
    int getNumber(char c){
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return -1;
        }
    }

    int romanToInt(string s) {
        int result = 0, current, next;
        int i = 0;
        int n = s.size();
        while(i<n){
            if(i==n-1){
                result += getNumber(s[i]);
                return result;
            }
            int current = getNumber(s[i]);
            int next = getNumber(s[i+1]);
            if(current>=next){
                result += current;
                i++;
            } else {
                result += next - current;
                i += 2;
            }
        }
        return result;
        
    }
};