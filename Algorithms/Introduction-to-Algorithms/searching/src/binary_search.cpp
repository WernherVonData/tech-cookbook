#include "binary_search.hpp"

#include <cmath>
#include <functional>
#include <iostream>

#include "time_tracker.hpp"

namespace searching
{
void demoSearch()
{
  constexpr int nb_elements = 10000000;
  std::vector<int> search_case{};
  search_case.resize(nb_elements);
  for (int i = 0; i < nb_elements; ++i) {
    search_case[i] = i + 1;
  }
  std::function<void(std::vector<int>&, int, int, SearchData&)> search = [&](std::vector<int>& A, int left_boundary, int right_boundary,
                                                                SearchData& data) {
    binarySearch(A, left_boundary, right_boundary, data);
  };

  SearchData first_value_data;
  first_value_data.searching_value = 1;
  std::cout << "First value case: "
            << utils::runWithTimeMeasure(search, search_case, 0, nb_elements - 1, first_value_data).count()
            << " milliseconds" << std::endl;
  std::cout << "First value comparisons: " << first_value_data.number_of_comparisons << std::endl;
  std::cout << "First value index: " << first_value_data.found_index << std::endl;
  std::cout << "First value number of calls " << first_value_data.number_of_calls << std::endl;
  std::cout << std::endl;

  SearchData middle_case_data;
  middle_case_data.searching_value = nb_elements / 2;
  std::cout << "Middle value case: "
            << utils::runWithTimeMeasure(search, search_case, 0, nb_elements - 1, middle_case_data).count()
            << " milliseconds" << std::endl;
  std::cout << "Middle value comparisons: " << middle_case_data.number_of_comparisons << std::endl;
  std::cout << "Middle value index: " << middle_case_data.found_index << std::endl;
  std::cout << "Middle value number of calls " << middle_case_data.number_of_calls << std::endl;
  std::cout << std::endl;

  SearchData last_value_data;
  last_value_data.searching_value = nb_elements;
  std::cout << "Last value case: "
            << utils::runWithTimeMeasure(search, search_case, 0, nb_elements - 1, last_value_data).count()
            << " milliseconds" << std::endl;
  std::cout << "Last value case comparisons: " << last_value_data.number_of_comparisons << std::endl;
  std::cout << "Last value case index: " << last_value_data.found_index << std::endl;
  std::cout << "Last value number of calls " << last_value_data.number_of_calls << std::endl;
  std::cout << std::endl;
}

void binarySearch(std::vector<int>& A, int left_boundary, int right_boundary, SearchData& data)
{
  if (left_boundary <= right_boundary) {
    // This is a floor operation
    int middle = (left_boundary + right_boundary) / 2;

    if (data.searching_value == A[middle]) {
      ++data.number_of_comparisons;
      data.found_index = middle;
    } else if (data.searching_value > A[middle]) {
      ++data.number_of_comparisons;
      ++data.number_of_calls;
      binarySearch(A, middle + 1, right_boundary, data);
    } else {
      ++data.number_of_comparisons;
      ++data.number_of_calls;
      binarySearch(A, left_boundary, middle - 1, data);
    }
  }
}
} // namespace searching