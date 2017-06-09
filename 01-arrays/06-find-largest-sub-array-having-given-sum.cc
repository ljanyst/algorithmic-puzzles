
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// We remember indexes at which we have seen the each sum. We look if we have
// seen the current sum minus the requested sum in the past. If we did, then all
// the subsequent elements must have summed up to the requested sum. We find the
// largest array having this property.
std::pair<int, int> find_sub_array_with_sum(
  const std::vector<int> &arr, int sum) {

  std::unordered_multimap<int, int> sums;
  sums.insert(std::make_pair(0, -1));

  auto ret = std::make_pair(-1, -1);
  int max_length = 0;
  int current_sum = 0;
  for(int i = 0; i < arr.size(); ++i) {
    current_sum += arr[i];
    int level = current_sum - sum;
    auto it = sums.find(level);
    if(it != sums.end()) {
      for(; it != sums.end() && it->first == level; ++it) {
        if(i - it->second > max_length) {
          max_length = i - it->second;
          ret.first  = it->second+1;
          ret.second = i;
        }
      }
    }
    sums.insert(std::make_pair(current_sum, i));
  }
  return ret;
}

int main(int argc, char **argv) {
  int size;
  int sum;
  int tmp;
  std::vector<int> data;
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    data.push_back(tmp);
  }
  std::cin >> sum;

  auto ret = find_sub_array_with_sum(data, sum);
  if(ret.first == -1) {
    std::cout << "none" << std:: endl;
    return 0;
  }

  for(int i = ret.first; i <= ret.second; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;
  return 0;
}
