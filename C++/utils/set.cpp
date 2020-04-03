#include <set>
#include <stdio.h>
#include <stdlib.h>

int main(){

    std::set<int> test_set;
    const int A_Len = 7;
    const int B_Len = 8;

    int a[A_Len] = {5, 1, 4, 8, 10, 1, 3};
    int b[B_Len] = {2, 7, 6, 3, 1, 6, 0, 1};

    for(int i = 0; i < A_Len; i++){
        test_set.insert(a[i]);
    }
    for(int i = 0; i < B_Len; i++){
        if(test_set.find(b[i]) != test_set.end()){
            printf("b[%d] = %d in array A.\n", i, b[i]);
        }
    }
    system("pause");
    return 0;
}