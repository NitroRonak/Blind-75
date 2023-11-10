#include<bits/stdc++.h>
using namespace std;

//Time Complexity:O(N*K*log(K))
// where N is the number of strings in the input array strs, 
// and K is the maximum length of any string in strs. This is because, 
// for each string, the code sorts its characters, and the 
// sorting operation takes O(K * log(K)) time.
//Space Complexity:O(N*K);
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    for (const string& s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(s);
    }
    vector<vector<string>> result;
    for (const auto& entry : anagramGroups) {
        result.push_back(entry.second);
    }
    return result;
}
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (const auto& v : ans) {
        for (const auto& s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}