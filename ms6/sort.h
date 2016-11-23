#ifndef SICT_SORT_H__
#define SICT_SORT_H__
namespace sict{
  template <typename Type>
  void swap(Type* a, Type* b){
    Type temp = *a;
    *a = *b;
    *b = temp;
  }
  template <typename Type>
  void sort(Type a[], int size){
    int i;
    int j;
    for (i = 0; i < (size - 1); i++){
      for (j = 0; j < size - i - 1; j++){
        if (*a[j] > *a[j + 1]){
          swap(&a[j], &a[j + 1]);
        }
      }
    }
  }
}
#endif
