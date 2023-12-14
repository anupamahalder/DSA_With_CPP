#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> ngElements(vector<int>nums){
    int n = nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = ngElements(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    // Output: 5 10 10 -1 -1
    return 0;
}
