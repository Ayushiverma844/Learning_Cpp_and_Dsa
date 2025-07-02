#include <iostream>
using namespace std;

class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        
        int n = temp.length();
        vector<int> lps(n, 0);
        
        for(int i = 1; i < n; i++) {
            int len = lps[i - 1];
            
            while(len > 0 && temp[i] != temp[len]) {
                len = lps[len - 1];
            }
            
            if(temp[i] == temp[len]) {
                len++;
            }
            
            lps[i] = len;
        }
        
        return s.length() - lps[n - 1];
    }
};

int main() {
    string str;
    cin >> str;
    
    Solution obj;
    int result = obj.minChar(str);
    
    cout << result << endl;
    
    return 0;
}
