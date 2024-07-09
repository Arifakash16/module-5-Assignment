class Solution {
public:
    // calculate hash value of a string
    int getHashValue(string str) 
    {
        int hash = 0;
        for(int i=0;i<str.length();i++)
            hash+=(str[i]-'a');
        
        return hash;
    }

    // to check substring of haystack is equal to the needle
    int isCheck(string haystack,string needle) 
    {
        for(int i=0;i<needle.length();i++)
        {
            if(needle[i]!=haystack[i])
                return 0;
        }
        return 1;
        
    }


    int strStr(string haystack, string needle) {
        int len_haystack = haystack.length();
        int len_needle = needle.length();

        int needleHash = getHashValue(needle);
        int tempHash = getHashValue(haystack.substr(0,len_needle));
        if(needleHash == tempHash) // to check needle hash and substring of haystack is equal
        {
            if(isCheck(haystack.substr(0,len_needle),needle)) // check all chararcters are eaual
                return 0;

        }

        for(int i=1;i<len_haystack-len_needle+1;i++)
        {
            tempHash = tempHash - (haystack[i-1]-'a') + (haystack[i+len_needle-1]-'a');
            if(tempHash!=needleHash) // to check needle hash and substring of haystack is not equal
                continue;
            if(isCheck(haystack.substr(i,len_needle),needle))// check all chararcters are eaual
                return i;
        }

        return -1;
    }
};

// Time complexity: O(n*n) in worst case but it is significantly faster if i take more complex hash function.
// Space complexity: O(1)