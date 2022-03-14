#include <memory>

using namespace std;

class MinHeap
{
private:
  size_t N;
  long* S;
public:
  MinHeap();
  MinHeap(long* S, size_t N);
  ~MinHeap();
  void Creer(long* S);
  void Insertion();
  long Minimum();
  long ExtraireMin();
  long DiminuerClef(size_t x, long k);
  bool EstVide();
};
