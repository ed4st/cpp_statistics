#include <iostream>
#include <stdlib.h>     /* srand, rand */

#define MIN 100
#define MAX 250

using namespace std;

namespace stats{
    //defining vector structure
    struct vector{
        int len; //array's length
        int arr[200];
    };

    vector random_vector(){
        //creating vector to compute statistics
        vector v;

        v.len = 200; //default

        //filling arr element of v with random numbers
        for (int i = 0; i < v.len; i++)
        {
            v.arr[i] = rand()%(MAX-MIN + 1) + MIN;
        }
        return v;
    }

    void print(vector v){
        cout << "[";
        for (int i = 0; i < v.len; i++)
        {
            cout << v.arr[i] << ", ";
        }
        cout << "]" << endl;
    }
}

using namespace stats;

int main(){
    vector v = random_vector();
    print(v);
    return 0;
}