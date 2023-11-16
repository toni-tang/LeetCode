class Solution {
public:
    
    bitset<16> addOne(bitset<16>& binaryNumber) {
        for (size_t i = 0; i < binaryNumber.size(); ++i) {
            if (!binaryNumber[i]) {
                binaryNumber[i] = 1;
                break;
            } else {
                binaryNumber[i] = 0;
            }
        }
        return binaryNumber;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string, int> mp;
        
        for(auto& str : nums) {
            mp[str]++;
        }
        
        bitset<16> bits;
        for(int i = 0; i <= n*n; i++) {
            string str = bits.to_string();
            if(mp.find(str.substr(16 - n, 16)) == mp.end() ) {
                return str.substr(16 - n, 16);
            }
               
            addOne(bits);
        }
        
        return nums[0][0] == '0' ? "1" : "0";
    }
};