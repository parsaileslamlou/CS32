#include "sorts.h"
#include <algorithm>

// TODO: Implement stable insertion sort on vector<ItemHandle>
void insertionSortItems(std::vector<ItemHandle>& a, bool ascending) {
   //  (void)a; (void)ascending; // STUB: no-op
    for(int i = 1; i< a.size(); i++){
        ItemHandle key = a[i];
        int j = i - 1;
        if(ascending){
            while(j>=0 && key < a[j]){
                a[j+1] = a[j];
                j--;
            }
        }
        else{
            while(j>=0 && a[j] < key){
                a[j+1] = a[j];
                j--;
            }
        }
        a[j+1] = key;
    }
}

// TODO: Implement stable merge sort on vector<ItemHandle>
void mergeSortItems(std::vector<ItemHandle>& a, bool ascending) {
    (void)a; (void)ascending; // STUB: no-op
    }

void sortItems(std::vector<ItemHandle>& a, SortAlgo algo, bool ascending) {
    switch (algo) {
        case SortAlgo::Insertion: insertionSortItems(a, ascending); break;
        case SortAlgo::Merge:     mergeSortItems(a,     ascending); break;
    }
}
