
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

// We replace 0 with -1 and look for largest array having 0 sum. Since
// we look for the largest array we don't need a multimat because we
// only want to know the index that is furthest away from our current
// position.
std::pair<int, int> find_largest_sub_array(std::vector<int> arr) {
  auto ret = std::make_pair(-1, -1);
  for(auto &a: arr)
    if(a == 0)
      a = -1;
  std::unordered_map<int, int> sums;
  sums[0] = -1;
  int sum = 0;
  for(int i = 0; i < arr.size(); ++i) {
    sum += arr[i];
    if(sums.find(sum) == sums.end())
      sums[sum] = i;
    else {
      if((i - sums[sum]) > (ret.second-ret.first+1)) {
        ret.first  = sums[sum]+1;
        ret.second = i;
      }
    }
  }
  return ret;
}

int main(int argc, char **argv) {
  int size = 0;
  int tmp;
  std::vector<int> data;
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    data.push_back(tmp);
  }
  auto ret = find_largest_sub_array(data);
  if(ret.first == -1)
    std::cout << "no such sub array" << std::endl;
  else {
    for(int i = ret.first; i <= ret.second; ++i)
      std::cout << data[i] << " ";
    std::cout << std::endl;
  }
  return 0;
}
