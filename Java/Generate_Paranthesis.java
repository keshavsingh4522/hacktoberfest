/*
22. Generate Parentheses
Medium

15301

585

Add to List

Share
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
 */

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        generate(0,0,n,"",list);
        return list;
    }
    
    public void generate(int open,int close,int n,String s,List<String> list){
        if(s.length()==(2*n))
            list.add(s);
        if(open<n){
            generate(open+1,close,n,s+"(",list);
        }
        if(open>close){
            generate(open,close+1,n,s+")",list);
        }
          
    }
}