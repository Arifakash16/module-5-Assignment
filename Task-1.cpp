class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string temp;
        temp.resize(n);  // initialize the temp string as size same as string s;
        for(int i=0;i<n;i++)
        {
            temp[indices[i]] = s[i]; // storing each char according their indices
        }
        return temp;  // return restoring string
    }
};

Time complexity: O(n)
Space complexity: O(n)