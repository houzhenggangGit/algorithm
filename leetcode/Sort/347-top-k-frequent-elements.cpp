//
// Created by 侯正罡 on 2020/1/21.
//
/*

 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 利用堆排序
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        using E = pair<int, int>;
        unordered_map<int, int> count_map;
        priority_queue<E, vector<E>, greater<> > min_heap;
        vector<int> res;
        for (auto &num: nums) count_map[num]++;
        for (auto &count : count_map) {
            min_heap.push(make_pair(count.second, count.first));
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        while (!min_heap.empty()) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};

TEST(topKFrequent, 1) { /* NOLINT */
    cout << endl;
    vector<int> input{1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> answer{2, 1};
    vector<int> output = Solution().topKFrequent(input, k);
    EXPECT_EQ(answer, output);
}

