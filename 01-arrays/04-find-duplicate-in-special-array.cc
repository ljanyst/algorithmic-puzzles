
#include <iostream>
#include <vector>
#include <numeric>

// the array contains elements from 1 to n-1 and only one duplicate

int find_duplicate(const std::vector<int> &arr) {
  int sum  = std::accumulate(arr.begin(), arr.end(), 0);
  int size = arr.size()-1;
  return sum - (size*(size+1))/2;
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
  std::cout << find_duplicate(nums) << std::endl;
  return 0;
}
