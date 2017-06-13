
#include <iostream>
#include <vector>
#include <utility>

// If we find an element in the first array that is larger than the first
// element of the second array, we swap the elements and make sure that the
// element moved to the second array is in the right place in the array.
// This algorithm is O(nm), but it can also be done in O(n), see
// http://www.akira.ruc.dk/~keld/teaching/algoritmedesign_f04/Artikler/04/Huang88.pdf
void merge(std::vector<int> &data1, std::vector<int> &data2) {
  for(int i = 0; i < data1.size(); ++i) {
    if(data1[i] > data2[0]) {
      std::swap(data1[i], data2[0]);
      for(int j = 1; j < data2.size(); ++j) {
        if(data2[j-1] > data2[j])
          std::swap(data2[j-1], data2[j]);
        else
          break;
      }
    }
  }
}

int main(int argc, char **argv) {
  int size;
  int tmp;
  std::vector<int> data1;
  std::vector<int> data2;
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    data1.push_back(tmp);
  }
  std::cin >> size;
  for(int i = 0; i < size; ++i) {
    std::cin >> tmp;
    data2.push_back(tmp);
  }

  merge(data1, data2);

  for(auto &a: data1)
    std::cout << a << " ";
  std::cout << std::endl;
  for(auto &a: data2)
    std::cout << a << " ";
  std::cout << std::endl;
  return 0;
}
