#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
float calculate_a_i(float *array_a,float *array_c,int i) {
    return (array_a[i - 1] + array_a[i + 1]) /2 - array_c[i];
}
int main() 
{
    float *array_a; 
    float *array_c;
    int n;//amount
    ifstream infile;//open the file ,and initialize the two arrays.
    infile.open("test");
    if(!infile) {
        cerr << "error :unable to open input file:"
             << infile << endl;
        return -1;
    }
    string line;// a line of the file 
    int count = 0;
    int i = 1;//count for array c
    while(getline(infile,line)) {
        count++;
        istringstream stream(line);
        if(count == 1) {
            stream >> n;//the first line
            array_a = new float[n + 2];
            array_c = new float[n + 1];
        } else if(count == 2){
            stream >> array_a[0];
            printf("%.2f \n",array_a[0]);
        } else if(count == 3) {
            stream >> array_a[n + 1];
            printf("%.2f \n",array_a[n + 1]);
        } else {
            stream >> array_c[i];
            printf("%.2f \n",array_c[i]);
            i++;
        }
    }
    float result = calculate_a_i(array_a,array_c,1);
    printf("%.2f \n",result);
}

