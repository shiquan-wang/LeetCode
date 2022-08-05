#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;

    for(unsigned int i = 0; i < 10000; i++){
        vec1.push_back(rand() % 1024);
    }
    vec2 = vec1;
    sort(vec1.begin(), vec1.end());

    // time_t start, end;
    // time(&start);
    double start, end;
    // start = clock();
    // long long int sum1 = 0;
    // for(unsigned i = 0; i < 100000; ++i){
    //     for(unsigned j = 0; j < 10000; ++j){
    //         if(vec1[j] >= 512){
    //             sum1 += vec1[j];
    //         }
    //     }
    // }
    // // time(&end);
    // end = clock();
    // cout<<sum1<<endl<<end - start<<endl;
    // cout<<difftime(end, start);

    // time_t start2, end2;
    // time(&start2);
    start = clock();
    long long int sum2 = 0;
    for(unsigned i = 0; i < 100000; ++i){
        for(unsigned j = 0; j < 1000; ++j){
            if(vec2[j] >= 512){
                sum2 += vec2[j];
            }
        }
    }
    end = clock();
    // time(&end2);
    cout<<sum2<<endl<<end - start;
    // cout<<difftime(end2, start2);
}