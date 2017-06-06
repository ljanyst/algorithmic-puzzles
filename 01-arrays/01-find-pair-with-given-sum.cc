
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

std::pair<int, int> find_sum(const std::vector<int> &arr, int sum) {
  std::unordered_map<int, int> diffs;
  for(int i = 0; i < arr.size(); ++i) {
    auto it = diffs.find(sum-arr[i]);
    if(it != diffs.end())
      return std::make_pair(it->second, i);
    diffs[arr[i]] = i;
  }
  return std::make_pair(-1, -1);
}

int main(int argc, char **argv) {
  int size = 0;
  int sum = 0;
  int tmp;
  std::vector<int> nums;
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    nums.push_back(tmp);
  }
  std::cin >> sum;
  auto ret = find_sum(nums, sum);
  std::cout << ret.first << " " << ret.second << std::endl;
  return 0;
}
