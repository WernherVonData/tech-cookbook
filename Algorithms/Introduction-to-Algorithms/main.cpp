#include <exception>
#include <iostream>

#include "binary_search.hpp"
#include "bst.hpp"
#include "bubble_sort.hpp"
#include "counting_sort.hpp"
#include "cut_rod.hpp"
#include "demo_sorting.hpp"
#include "greedy_activity_selector.hpp"
#include "heap.hpp"
#include "heap_sort.hpp"
#include "huffman.hpp"
#include "insertion_sort.hpp"
#include "linked_list.hpp"
#include "longest_common_subsequence.hpp"
#include "matrix_multiply.hpp"
#include "maximum_subarray.hpp"
#include "merge_sort.hpp"
#include "merge_sort_improved.hpp"
#include "queue.hpp"
#include "quicksort.hpp"
#include "randomized_quicksort.hpp"
#include "rb_tree.hpp"
#include "stack.hpp"
#include "time_tracker.hpp"

#ifdef _DEBUG
#if _WIN32
#define WIN_MEMORY_LEAK_CHECKER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#endif // _WIN32
#endif // _DEBUG

void insertionSort()
{
  std::cout << "*** Insertion sort\n";
  sorting::InsertionSort insertion_sort;
  sorting::demo_sorting(insertion_sort);
  std::cout << "*****************************" << std::endl;
}

void bubbleSort()
{
  std::cout << "*** Bubble sort\n";
  sorting::BubbleSort bubble_sort;
  sorting::demo_sorting(bubble_sort);
  std::cout << "*****************************" << std::endl;
}

void mergeSort()
{
  std::cout << "*** Merge sort\n";
  sorting::MergeSort merge_sort;
  sorting::demo_sorting(merge_sort);
  std::cout << "*****************************" << std::endl;
}

void mergeSortImproved()
{
  std::cout << "*** Merge sort improved\n";
  sorting::MergeSortImproved merge_sort_improved;
  sorting::demo_sorting(merge_sort_improved);
  std::cout << "*****************************" << std::endl;
}

void heapSort()
{
  std::cout << "*** Heap sort\n";
  sorting::HeapSort heap_sort;
  sorting::demo_sorting(heap_sort);
  std::cout << "*****************************" << std::endl;
}

void quickSort()
{
  std::cout << "*** Quick sort\n";
  sorting::QuickSort quick_sort;
  sorting::demo_sorting(quick_sort);
  std::cout << "*****************************" << std::endl;
}

void randomizedQuickSort()
{
  std::cout << "*** Randomized Quick sort\n";
  sorting::RandomizedQuickSort randomized_quick_sort;
  sorting::demo_sorting(randomized_quick_sort);
  std::cout << "*****************************" << std::endl;
}

void countingSort()
{
  std::cout << "*** Counting sort\n";
  sorting::CountingSort counting_sort;
  sorting::demo_sorting(counting_sort);
  std::cout << "*****************************" << std::endl;
}

void sortingAlgorithms()
{
  std::cout << "***** Sorting algorithms\n";
  insertionSort();
  bubbleSort();
  mergeSort();
  mergeSortImproved();
  heapSort();
  /* Do not run it on big data as the "best case" causes stack overflow*/
  quickSort();
  randomizedQuickSort();
  countingSort();
  std::cout << "**********\n";
}

void binarySearch()
{
  std::cout << "*** Binary search\n";
  searching::demoSearch();
  std::cout << "*****************************" << std::endl;
}

void maximumSubarray()
{
  std::cout << "*** Maximum subarray\n";
  dac::demoMaximumSubarray();
  std::cout << "*****************************" << std::endl;
}

void matrixMultiplication()
{
  std::cout << "*** Matrix multiplication\n";
  matrix::demoMatrixMultiplication();
  std::cout << "*****************************" << std::endl;
}

void heapUsage()
{
  std::cout << "*** Heaps\n";
  std::vector<int> v{1, 2, 3, 4, 5};
  heap::Heap<int> h(v);
  h.PrintHeap();
  std::cout << "Build max heap\n";
  heap::BuildMaxHeap<int>(h);
  h.PrintHeap();
  std::cout << "*****************************" << std::endl;
}

void stackUsage()
{
  std::cout << "*** Stack\n";
  data_structures::Stack stack(5);
  try {
    stack.pop();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  try {
    stack.push(6);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;

  std::cout << "*****************************" << std::endl;
}

void queueUsage()
{
  std::cout << "*** Queue\n";
  data_structures::Queue queue(3);
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.printQueue();
  queue.enqueue(4);
  queue.printQueue();
  std::cout << queue.dequeue() << std::endl;
  std::cout << "*****************************" << std::endl;
}

void linkedListUsage()
{
  std::cout << "*** Linked List\n";
  data_structures::LinkedList list;
  for (int i = 1; i <= 10; ++i) {
    list.insert(i, i * 100);
  }
  list.printList();
  auto elem = list.search(3);
  list.remove(elem);
  list.printList();
  if (elem == nullptr) {
    std::cout << "Elem was removed\n";
  }
  std::cout << "*****************************" << std::endl;
}

void bstUsage()
{
  std::cout << "*** BST\n";
  data_structures::BST bst;
  bst.insert(10, 100);
  bst.insert(2, 20);
  bst.insert(1, 10);
  bst.insert(3, 30);
  bst.insert(4, 40);
  bst.inorderTreeWalk();
  auto elem = bst.search(3);
  bst.remove(elem);
  bst.inorderTreeWalk();
  std::cout << "*****************************" << std::endl;
}

void rbTreeUsage()
{
  std::cout << "*** Red-Black Trees\n";
  data_structures::RBTree rbTree;

  rbTree.insert(41, 100);
  rbTree.insert(38, 20);
  rbTree.insert(31, 10);
  rbTree.insert(12, 10);
  rbTree.insert(19, 10);
  rbTree.insert(8, 10);

  std::cout << "After add\n";
  std::cout << "Inorder walk *****************************" << std::endl;
  rbTree.inorderTreeWalk();
  std::cout << "Order walk *****************************" << std::endl;
  rbTree.orderTreeWalk();

  rbTree.remove(rbTree.search(8));
  rbTree.remove(rbTree.search(12));
  rbTree.remove(rbTree.search(19));
  rbTree.remove(rbTree.search(31));
  rbTree.remove(rbTree.search(38));
  rbTree.remove(rbTree.search(41));

  std::cout << "*****************************" << std::endl;
}

void cutRod()
{
  std::cout << "*** Dynamic Programming - Cut Rod problem\n";
  std::cout
      << "Cut Rod in traditional approach "
      << utils::runWithTimeMeasure(dynamic_programming::cutRodRecursively, dynamic_programming::ROD_PRICES, 20).count()
      << "ms" << std::endl;

  std::cout
      << "Cut Rod in memoized approach "
      << utils::runWithTimeMeasure(dynamic_programming::memoizedCutRod, dynamic_programming::ROD_PRICES, 20).count()
      << "ms" << std::endl;

  std::cout
      << "Cut Rod in bottom-up approach "
      << utils::runWithTimeMeasure(dynamic_programming::bottomUpCutRod, dynamic_programming::ROD_PRICES, 20).count()
      << "ms" << std::endl;
  std::cout << "*****************************" << std::endl;
}

void longestCommonSubsequence()
{
  std::cout << "*** Dynamic Programming - Longest Common Subsequence problem\n";
  std::vector<int> X{5, 6, 8, 6, 1, 3, 6, 2, 4, 6, 7, 9, 2, 2, 1};
  std::vector<int> Y{9, 7, 8, 6, 1, 5, 6, 1, 4, 7};
  // Implementation is awful, but the understanding of the problem counts here for me
  auto result = dynamic_programming::lcsLength(X, Y);
  dynamic_programming::printLcs(result, X, X.size(), Y.size());
  std::cout << "*****************************" << std::endl;
}

void greedyAlgorithms()
{
  std::cout << "*** Greedy algorithms\n";

  std::cout << "Recursive activity selection\n";
  // Recursive problem must have artificial activity at the beginning with start time and end time of zero
  std::vector<greedy::Activity> activities_recursive{{0, 0}, {1, 4},  {3, 5},  {0, 6},  {5, 7},  {3, 9},
                                                     {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};
  auto activitiesSelectedRecursively =
      greedy::recursiveActivitySelector(activities_recursive, 0, activities_recursive.size());
  for (const auto& a : activitiesSelectedRecursively) {
    std::cout << a.start_time_ << " : " << a.end_time_ << std::endl;
  }
  std::cout << "Iterative activity selection\n";
  std::vector<greedy::Activity> activities_iterative{{1, 4},  {3, 5},  {0, 6},  {5, 7},  {3, 9},  {5, 9},
                                                     {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};
  auto activitesSelectedIteratively = greedy::greedyActivitySelector(activities_iterative);
  for (const auto& a : activitesSelectedIteratively) {
    std::cout << a.start_time_ << " : " << a.end_time_ << std::endl;
  }
  std::cout << "Huffman codes\n";
  std::vector<greedy::Node> startingNodes{{45, 'a'}, {13, 'b'}, {12, 'c'}, {16, 'd'}, {9, 'e'}, {5, 'f'}};
  auto node = greedy::Huffman(startingNodes);
  greedy::SetValues(node);
  greedy::TreeWalk(node);

  std::cout << "*****************************" << std::endl;
}

int main()
{
  std::cout << "***** Introduction to Algorithms 3rd edition" << std::endl << std::endl;
  sortingAlgorithms();

  binarySearch();

  maximumSubarray();

  matrixMultiplication();

  heapUsage();

  stackUsage();

  queueUsage();

  linkedListUsage();

  bstUsage();

  rbTreeUsage();

  cutRod();
  
  longestCommonSubsequence();
  
  greedyAlgorithms();

#ifdef WIN_MEMORY_LEAK_CHECKER
  _CrtDumpMemoryLeaks();
#endif // WIN_MEMORY_LEAK_CHECKER

  getchar();
  return 0;
}
