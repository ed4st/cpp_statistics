#include <iostream>
#include <algorithm>    //sort
#include <stdlib.h>     /* srand, rand */
#include <math.h>       /* pow, sqrt */

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
        for (int i = 0; i < v.len; ++i)
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
        //first, we sort the array:
        std::sort(v.arr, v.arr + v.len);
        int number = v.arr[0];
        int mode = number;
        int count = 1;
        int countMode = 1;

        for (int i = 1; i < v.len; i++)
        {
            if (v.arr[i] == number) 
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
                number = v.arr[i];
            }
        }
        return mode;
    }

    //median 
    double median(vector v){
        //first, we sort the array
        std::sort(v.arr, v.arr + v.len);
        //cause we already know the size of vector (200) is even,
        //we compute the median as follows:
        int median1 = v.arr[v.len/2 - 1];
        int median2 = v.arr[v.len/2];
        return double(median1+median2)/2;
    }
    
    //variance 
    double variance(vector v){
        double sum = 0;
        int mean = stats::mean(v);
        for (int i = 0; i < v.len; i++)
        {
            sum += pow(v.arr[i]-mean, 2);
        }
        return sum/(v.len-1);
    }

    //standard deviation
    double sd(vector v){
        return sqrt(stats::variance(v));
    }
}

using namespace stats;

int main(){
    vector v = random_vector();
    cout << "random vector created:\n";
    print(v);
    
    cout << "mean: "<< stats::mean(v) << endl;
    cout << "mode: "<< stats::mode(v) << endl;
    cout << "median: "<< stats::median(v) << endl;
    cout << "variance: "<< stats::variance(v) << endl;
    cout << "standard deviation: "<< stats::sd(v) << endl;

    return 0;
}