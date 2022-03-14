// #include <array>
#include <iostream>
#include <vector>
#include <random>
#include "minheap.h"

using namespace std;

void print(const long *arr, size_t N);

void print(const vector<long> &v);

int main()
{
  array<long, 8> arr({10, 30, 40, 60, 50, 20, 80, 70});
  cout << "array: ";
  print(arr.data(), arr.size());
  cout << endl;
  MinHeap m(arr.data(), arr.size());
  cout << "minimum: " << m.Minimum() << endl;
  m.ExtraireMin();
  cout << "array: ";
  print(arr.data(), arr.size());
  cout << endl;
  size_t x = (size_t)(random() / RAND_MAX * arr.size());
  m.DiminuerClef(x, 1);
  cout << "array[" << x << "]: ";
  cout << arr[x];
  cout << endl;
  return 0;
}

void print(const long *arr, size_t N)
{
  cout << "[ ";
  for (size_t i = 0; i < N; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "]";
}

void print(const vector<long> &v)
{
  cout << "[ ";
  for (long l : v)
  {
    cout << l << " ";
  }
  cout << "]";
}
