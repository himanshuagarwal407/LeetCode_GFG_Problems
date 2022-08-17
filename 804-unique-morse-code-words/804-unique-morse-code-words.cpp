class Solution {
    vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string transform(string s)
    {
        string res="";
        for(auto a:s)
            res+=code[int(a)-97];
        
        return res;
    }
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> unique;
        
        for(int i=0; i<words.size(); i++)
        {
            string s=transform(words[i]);
            unique.insert(s);
        }
        
        return unique.size();
    }
};