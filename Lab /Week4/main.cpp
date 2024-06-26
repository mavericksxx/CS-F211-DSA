#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

int linear_search(std::vector<int> v, int a)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == a)
      return i;
  }
  return -1;
}

int binary_search(std::vector<int> v, int a)
{
  int maximum = (v.size()) - 1;
  int minimum = 0;
  int mean;

  while (maximum > minimum)
  {
    mean = (maximum + minimum) / 2;
    if (v[mean] == a)
    {
      return mean;
    }
    else if (v[mean] > a)
    {
      maximum = (mean - 1);
    }
    else
    {
      minimum = (mean + 1);
    }
  }
  return -1;
}

int main()
{

  std::ifstream testSizeFile;
  int testSize;
  testSizeFile.open("testCaseSize.txt");

  int num;
  std::cin >> num;
  std::vector<int> nums;

  while (testSizeFile >> testSize)
  {
    nums.push_back(testSize);
  }

  std::cout << "Test Size: " << testSize << std::endl;
  int arr;

  std::ifstream file("searchTestCase.txt");

  std::vector<int> numbers; 
  int number;

  while (file >> number)
  {
    numbers.push_back(number);
  }

  file.close(); 
  int ele;
  std::cin >> ele;

  clock_t tStart = clock();
  int rL = linear_search(numbers, ele);
  double tEnd = (double)(clock() - tStart);

  tStart = clock();
  int rB = binary_search(numbers, ele);
  tEnd = (double)(clock() - tStart);

  std::cout << "L/B Input Pos Time (s)" << std::endl;
  std::cout << "L   " << ele << " " << rL << " " << tEnd << std::endl;
  std::cout << "B   " << ele << " " << rB << " " << tEnd << std::endl;

  std::ofstream linearFile("linearSearchResult.txt");
  linearFile << "Input Pos Time (s)" << std::endl;
  for (int i; i < nums.size(); i++)
  {
    clock_t tStart = clock();
    int j = linear_search(numbers, nums[i]);
    double tEnd = (double)(clock() - tStart);
    linearFile << nums[i] << " " << j << " " << tEnd << std::endl;
  }

  std::ofstream binaryFile("binarySearchResult.txt");
  binaryFile << "Input Pos Time (s)" << std::endl;
  for (int i; i < nums.size(); i++)
  {
    clock_t tStart = clock();
    int j = binary_search(numbers, nums[i]);
    double tEnd = (double)(clock() - tStart);
    binaryFile << nums[i] << " " << j << " " << tEnd << std::endl;
  }
}
