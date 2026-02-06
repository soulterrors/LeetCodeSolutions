#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class FizzBuzzSolution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        s.reserve(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) s.push_back("FizzBuzz");
            else if (i % 3 == 0) s.push_back("Fizz");
            else if (i % 5 == 0) s.push_back("Buzz");
            else s.push_back(to_string(i));
        }
        return s;
    }
};

class TwoSumSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.find(diff) != map.end()) {
                return { map[diff], i };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    // --- Test Case: FizzBuzz ---
    cout << "Testing FizzBuzz(15)..." << endl;
    FizzBuzzSolution fb;
    vector<string> fbResult = fb.fizzBuzz(15);
    vector<string> fbExpected = { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz" };

    if (fbResult == fbExpected) {
        cout << "[ SUCCESS ] FizzBuzz matched expected output." << endl;
    }
    else {
        cout << "[ FAILED ] FizzBuzz did not match." << endl;
    }

    cout << "---------------------------------------" << endl;

    // --- Test Case: TwoSum ---
    cout << "Testing TwoSum({2, 7, 11, 15}, 9)..." << endl;
    TwoSumSolution ts;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> tsResult = ts.twoSum(nums, target);
    vector<int> tsExpected = { 0, 1 };

    if (tsResult == tsExpected) {
        cout << "[ SUCCESS ] TwoSum found the correct indices: {0, 1}" << endl;
    }
    else {
        cout << "[ FAILED ] TwoSum returned incorrect indices." << endl;
    }

    return 0;
}