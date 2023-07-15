class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, candidates, temp, target, 0);
        return res;
    }

private:
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, vector<int>& temp, int target, int start) {
        if(target < 0) {
            return;
        }
        else if(target == 0) {
            res.push_back(temp);
            return;
        } 
        else {
            for(int i = start; i < candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(res, candidates, temp, target - candidates[i], i);
                temp.pop_back();
            }
        }
    }
    
    
// public List<List<Integer>> combinationSum(int[] nums, int target) {
//     List<List<Integer>> list = new ArrayList<>();
//     Arrays.sort(nums);
//     backtrack(list, new ArrayList<>(), nums, target, 0);
//     return list;
// }

// private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int remain, int start){
//     if(remain < 0) return;
//     else if(remain == 0) list.add(new ArrayList<>(tempList));
//     else{ 
//         for(int i = start; i < nums.length; i++){
//             tempList.add(nums[i]);
//             backtrack(list, tempList, nums, remain - nums[i], i); // not i + 1 because we can reuse same elements
//             tempList.remove(tempList.size() - 1);
//         }
//     }
// }
    

};