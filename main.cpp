#include <iostream>      
#include <chrono>
#define MATRIX_SIZE 31000
using namespace std;

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

int main()
{
int* matrix = new int [MATRIX_SIZE*MATRIX_SIZE];
for (int i=0; i<MATRIX_SIZE; i++){
	for (int j=0; j<MATRIX_SIZE; j++) matrix[i*MATRIX_SIZE+j]=i*MATRIX_SIZE+j;
}
{
    Timer T1;
    long int sum1=0;
    for (int i=0; i<MATRIX_SIZE; i++){
        for (int j=0; j<MATRIX_SIZE; j++) sum1+=matrix[i*MATRIX_SIZE+j];
    }
cout<<sum1<<endl;
}
{
    Timer T2;
    long int sum2=0;
    for (int i=0; i<MATRIX_SIZE; i++){
        for (int j=0; j<MATRIX_SIZE; j++) sum2+=matrix[j*MATRIX_SIZE+i];
    }
cout<<sum2<<endl;
}
return 0;
}
