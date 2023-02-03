class Solution {
public:
    unordered_map<string,bool> ump;
    bool isScrambled(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        if(s1==s2 || n==0) return true;
        
        string key = s1+" "+s2;
        if(ump.find(key) != ump.end()) return ump[key];
        
        
        bool flag = false;
        for(int i=1;i<n;i++){
            //для заміщеного рядка
            if(isScrambled(s1.substr(0,i),s2.substr(n-i,i)) || isScrambled(s1.substr(i,n-i),s2.substr(0,n-i))){ //для підстановки
                flag|=true;
                break;
            }

            //для рядка без свопінгу
            if(isScrambled(s1.substr(0,i),s2.substr(0,i)) || isScrambled(s1.substr(i,n-i),s2.substr(i,n-i))){
                flag|=true;
                break;
            }
        }
        ump[key]=flag;
        return flag;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        return isScrambled(s1,s2);
    }
};
