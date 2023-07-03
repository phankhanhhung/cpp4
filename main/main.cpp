#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "Another.h"

int main (){ 
    ISort *sort = new BubbleSort();
    sort->doSort();
    delete sort;
    sort = new QuickSort();
    sort->doSort();
    delete sort;
}