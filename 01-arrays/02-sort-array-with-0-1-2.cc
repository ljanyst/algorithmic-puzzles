
#include <iostream>
#include <vector>
#include <utility>

void sort(std::vector<int> &arr) {
  int start       = 0;
  int end         = arr.size()-1;
  int i           = 1;
  const int pivot = 1;
  while(i <= end) {
    if(arr[i] < pivot)
      std::swap(arr[i], arr[start++]);
    else if(arr[i] > pivot)
      std::swap(arr[i], arr[end--]);
    else
      ++i;
  }
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
  sort(nums);
  for(auto a: nums)
    std::cout << a << " ";
  std::cout << std::endl;
  return 0;
}
