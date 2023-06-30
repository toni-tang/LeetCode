class Solution {
public:
    static bool customCompare(const int& a, const int& b) 
    { 
        int x = bitset<32>(a).count();
        int y = bitset<32>(b).count();
        if(x != y)
            return x < y;
        return a < b;
    } 

    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(),customCompare);
        return arr;
    }
};