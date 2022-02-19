#ifndef SORTING_MERGE_SORT_HPP
#define SORTING_MERGE_SORT_HPP

#include "sorting_algorithm.hpp"

namespace sorting
{
class MergeSort : public SortingAlgorithm
{
public:
  ~MergeSort() = default;
  void Sort(int* array_to_sort, int number_of_elements) override;

private:
  void Sort(int* A, int p, int r);
  void Merge(int* A, int p, int q, int r);
};
} // namespace sorting

#endif