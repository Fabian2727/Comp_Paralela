#include <iostream>    
#include <chrono>   
#include <ctime>
using namespace std;

int main() {

  const int max = 100;
  int A[max][max];
  int x[max];
  int y[max] = {0};
  
  auto start = std::chrono::system_clock::now();
  
  for (int i = 0; i<max; i++)
    {
      for (int j = 0; j < max; j++)
        {
          y[i] += A[i][j] * x[j];
        }
    }
  auto end = std::chrono::system_clock::now();
  
  std::chrono::duration<float,std::milli> duration = end - start;

  std::cout << duration.count() << "s " << std::endl;


  const int max2 = 100;
  int B[max2][max2];
  int a[max2];
  int b[max2] = {0};
  
  auto start2 = std::chrono::system_clock::now();

  for (int j = 0; j<max2; j++)
    {
      for (int i = 0; i < max2; i++)
        {
          b[i] += B[i][j] * a[j];
        }
    }
  auto end2 = std::chrono::system_clock::now();

  std::chrono::duration<float,std::milli> duration2 = end2 - start2;

  std::cout << duration2.count() << "s " << std::endl;
}