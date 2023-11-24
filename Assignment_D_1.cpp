/* Implement program to find all distinct subsets of a 
given set using Bit Masking Approach.
Statement Given an array of integers arr[], The task is 
to find all its subsets. The subset cannot contain 
CO4
 Sanjivani College of Engineering, Kopargaon Page 40 of 100
duplicate elements, so any repeated subset should be 
considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2, 
2}, {1, 2,2}
Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}

*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findAllSubsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n; // Total number of subsets is 2^n

    unordered_set<string> seen; // To keep track of seen subsets
    vector<vector<int>> result;

    for (int i = 0; i < totalSubsets; ++i) {
        vector<int> subset;
        string subsetString = "";

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
                subsetString += to_string(nums[j]) + ",";
            }
        }

        if (seen.find(subsetString) == seen.end()) {
            result.push_back(subset);
            seen.insert(subsetString);
        }
    }

    return result;
}

void printSubsets(vector<vector<int>>& subsets) {
    cout << "Subsets: " << endl;
    for (auto& subset : subsets) {
        cout << "{";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i != subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> set1 = {1, 2, 2};
    vector<vector<int>> subsets1 = findAllSubsets(set1);
    printSubsets(subsets1);

    vector<int> set2 = {1, 2};
    vector<vector<int>> subsets2 = findAllSubsets(set2);
    printSubsets(subsets2);

    return 0;
}
