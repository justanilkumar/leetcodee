
class Solution {

    void helper(int open,int close,String ans,int n,List<String> ls){
        if(open == close && open+close == 2*n) ls.add(ans);
        if(open < n) helper(open+1,close,ans+"(",n,ls);
        if(open > close) helper(open,close+1,ans+")",n,ls);
    }
    public List<String> generateParenthesis(int n) {
        List<String> ls = new ArrayList<>();
        helper(0,0,"",n,ls);
        return ls;
    } 
}