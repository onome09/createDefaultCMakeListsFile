#include <fstream>

using boost::filesystem;

int main(){
  ofstream myfile;
  myfile.open ("CMakeLists.txt");

  myfile << "cmake_minimum_required (VERSION 3.0)\n";
  myfile << "project()\n\n";
    
  return 0;
}

cmake_minimum_required (VERSION 2.6)
project (insertionSort)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(insertionSort insertionSort.cpp)
