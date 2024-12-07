#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int* Ptr = new int(123);
    cout << *Ptr << endl;

    string* sPtr = new string("Cats and Dogs");
    cout << *sPtr << endl;

    int* A = new int[5]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    vector<int>* vPtr = new vector<int>{10, 20, 30, 40, 50};
    for (auto i : *vPtr) {
        cout << i << " ";
    }
    cout << endl;

    string* sA = new string[3]{"Cat", "Dog", "Mouse"};
    for (int i = 0; i < 3; ++i) {
        cout << sA[i] << " ";
    }
    cout << endl;

    delete Ptr; delete sPtr; delete[] A; delete vPtr; delete[] sA;

    return 0;
}
