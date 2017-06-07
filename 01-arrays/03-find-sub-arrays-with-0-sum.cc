
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

//------------------------------------------------------------------------------
// If we have seen a given sum before at some index, then all the elements
// starting from the next index up until the current index must sum up to zero.
//------------------------------------------------------------------------------
std::vector<std::pair<int, int>> find_sub_arrays_with_0_sum(
  const std::vector<int> &arr) {
  std::unordered_multimap<int, int> sums;
  sums.insert(std::make_pair(0, -1));

  std::vector<std::pair<int, int>> ret;
  int sum = 0;

  for(int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    auto it = sums.find(sum);
    if(it != sums.end()) {
      for(; it != sums.end() && it->first == sum; ++it)
        ret.push_back(std::make_pair(it->second+1, i));
    }
    sums.insert(std::make_pair(sum, i));
  }
  return ret;
}

int main(int argc, char **argv) {
  int size = 0;
  int tmp;
  std::vector<int> nums;
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    nums.push_back(tmp);
  }
  auto ret = find_sub_arrays_with_0_sum(nums);
  for(auto a: ret)
    std::cout << a.first << " " << a.second << std::endl;
  return 0;
}
