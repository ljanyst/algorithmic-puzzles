
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

// an array is consecutive if difference between minimum and the maximum
// element plus one is equal to the size of the array and if each element
// between minimum and maximum appears exactly once
bool is_consecutive(const std::vector<int> &arr, int start, int end) {
  std::unordered_set<int> elems;
  int min = arr[start];
  int max = arr[start];
  for(int i = start; i <= end; ++i) {
    if(elems.find(arr[i]) != elems.end())
      return false;
    elems.insert(arr[i]);
    if(max < arr[i]) max = arr[i];
    if(min > arr[i]) min = arr[i];
  }
  if(max - min != end - start)
    return false;

  for(int i = min; i <= max; ++i)
    if(elems.find(i) == elems.end())
      return false;
  return true;
}

std::pair<int, int> consecutive_nums(const std::vector<int> &arr) {
  auto ret         = std::make_pair(-1, -1);
  int  current_len = 0;
  for(int i = 0; i < arr.size(); ++i) {
    for(int j = i; j < arr.size(); ++j) {
      if(is_consecutive(arr, i, j)) {
        int len = j-i+1;
        if(current_len < len) {
          current_len = len;
          ret.first   = i;
          ret.second  = j;
        }
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

  auto ret = consecutive_nums(data);
  for(int i = ret.first; i <= ret.second; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;
  return 0;
}
