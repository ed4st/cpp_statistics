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
    //----------------------statistics----------------------
    //mean
    double mean(vector v){
        double sum = 0;
        for (int  i = 0; i < v.len; i++)
        {
            sum += v.arr[i];
        }
        
        return (sum / v.len);
    }

    //mode
    int mode(vector v){
        int number = v.arr[0];
        int mode = number;
        int count = 1;
        int countMode = 1;

        for (int i = 1; i < v.len; i++)
        {
            if (array[i] == number) 
            { // count occurrences of the current number
                ++count;
            }
            else
            { // now this is a different number
                    if (count > countMode) 
                    {
                        countMode = count; // mode is the biggest ocurrences
                        mode = number;
                    }
                count = 1; // reset count for the new number
                number = array[i];
            }
        }
    }
}

using namespace stats;

int main(){
    vector v = random_vector();
    print(v);
    cout << "mean: "<< mean(v) << endl;
    return 0;
}