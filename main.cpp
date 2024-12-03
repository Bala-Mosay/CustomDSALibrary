#include "dsa_library.h"
#include<vector>>
int main(){
    vector<int>x = {5,3,6,4,7,2,8,1};
    DSA::Sorting::mergesort(x);
    for(int i:x){
        cout << i <<" ";
    }
    
    cout << endl;
    vector<int>y = {5,3,6,4,7,2,8,1};
    DSA::Sorting::quicksort(y);
    for(int i:y){
        cout << i <<" ";
    }
    vector<int>z = {5,3,6,4,7,2,8,1};
    DSA::BST a;
    a.insert(x);
    a.deletion(5);
    cout << a.search(5);
    a.inorder();

    

}