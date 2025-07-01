#include <iostream>
using namespace std;

class Solution {
public:
    // Preprocess the pattern to build the LPS array
    void kmp(string &pat, vector<int>& lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;

        while (i < pat.length()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // KMP search algorithm
    vector<int> search(string& pat, string& txt) {
        vector<int> ans;
        int m = pat.length();
        int n = txt.length();
        vector<int> lps(m);
        kmp(pat, lps);

        int i = 0, j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j); // Match found at index (i - j)
                j = lps[j - 1]; // Continue searching
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    string text = "ababcababcabc";
    string pattern = "abc";

    Solution sol;
    vector<int> result = sol.search(pattern, text);

    cout << "Pattern found at indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
