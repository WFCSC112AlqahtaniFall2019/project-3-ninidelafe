/*Alexa(Nini) de la Fe
 * Project 3
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main(int argc, char * argv[]) {
    // gets input from terminal: first is random seed, second is vector length
   if (argc!= 3){
       cout<<"Usage: ./BubblesSort <seed> <length>\n";
       exit(1);
   }

   int seed, length;
   //takes input from the terminal instead of run
   seed= atoi(argv[1]);
   length=atoi(argv[2]);

    srand(seed);
//for (int j = 0; j < 10000; j = j + 100) { for loop allows for a constant run of 100 different numbers to print for the graph
   // length = j;
    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace
    int *a = new int[length]; //defines an integer pointer dynamically allocate an array of integers

    //Start of mergeSort calling of functions
    // initialize and prints vector with random numbers
   cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // copies the random list of integers from vector to array to be able to use in bubbleSort
    for (int i = 0; i < length; i++) {
        a[i] = v.at(i);
    }
    //times how long it takes when the mergeSort function is called
    clock_t start_mergeSort = clock();
    mergeSort(v, t, 0, v.size() - 1); // sorts a vector using mergeSort
    clock_t end_mergeSort = clock();

    // checks output, make sure vector is sorted after mergeSort
    for (int i = 1; i < v.size(); i++) {
        assert(v.at(i - 1) <= v.at(i));
    }

    // print sorted vector after mergeSort
   cout << "Sorted(mergeSort): " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    //Start of bubbleSort calling of functions

    //Unit Test for Swap
    int test1 = 10;
    int test2 = 4;
    int *unitTest1 = &test1;
    int *unitTest2 = &test2;
   cout << "Before Unit Test of Swap: " << test1 << " " << test2 << endl;
    swap(unitTest1, unitTest2);
   cout << "After Unit Test of Swap: " << test1 << " " << test2 << endl;
    assert(test1 < test2);

    //times how long it takes when the bubbleSort function is called
    clock_t start_bubbleSort = clock();
    bubbleSort(a, length); // sorts array using bubbleSort
    clock_t end_bubbleSort = clock();

    // check output, make sure array is sorted after bubbleSort
        for (int i = 1; i < length; i++) {
            assert(a[i - 1] <= a[i]);
    }

    // print sorted array after bubbleSort
    cout << "Sorted(bubbleSort): " << endl;
    for (int i = 0; i < length; i++) {
        cout << a[i] << '\t';
    }
    cout << endl;

    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;
    cout << "Seconds for mergeSort: "<<elapsed_mergeSort << " Seconds for bubbleSort: " << elapsed_bubbleSort << endl;

    //deallocates memory block for a
    delete[] a;
    a = nullptr;
//} end bracket for the for loop above

    return 0;
}

//mergeSortedLists is a function that sorts a list and was provided by instructor
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

//mergeSortedLists is a function that sorts a list, recursive part of mergeSortedLists and was provided by instructor
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function; swaps the two inputs using a temp variable
void swap(int *a, int *b) {
    int temp= *a;
    *a= *b;
    *b=temp;
}

// BubbleSort function; created following the pseudocode given in project instructions
void bubbleSort(int *a, int n) {

   bool sort= false;
    while (!sort) {
        for (int j = 0; j <n ; j++) {
            for (int i = 1; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    swap(&a[i - 1], &a[i]);
                }
            }
        }
        sort = true;
    }

}
