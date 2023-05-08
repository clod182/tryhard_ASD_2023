#include <vector>

class MaxHeap{
public:
  MaxHeap();
  MaxHeap(std::vector<int>& arr);
  ~MaxHeap();

  bool heapEmpty() const;
  int heapMaximum() const;
  int heapMinimum() const;
  int heapExtractMax();
  void heapInsert(int k);
  void heapDelete(size_t i);
  int heapSearch(int k) const;
  void mySimplePrintMaxHeap(int index, int level); //WIP aggiunta io

private:
  struct Impl;
  Impl* pimpl;
  void maxHeapify(size_t i);
  int auxSearch(int k, size_t node) const;
};