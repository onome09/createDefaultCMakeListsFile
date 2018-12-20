#include <fstream>
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main(){
   std::string directoryName;
  system( "mkdir build && mkdir src && mkdir include && touch CMakeLists.txt" ) ;
  path p = boost::filesystem::current_path();
  std::cout << p.filename() << std::endl;
  std::string line = "add_executable(" + p.filename().string() + " ${SOURCES})";
  std::ofstream myfile;
  myfile.open ("CMakeLists.txt");

  myfile << "cmake_minimum_required (VERSION 3.0)\n";
  myfile << "project(" << p.filename().string() << ")\n\n";

  myfile << "file(GLOB SOURCES \"src/*.cpp\")\n";

  myfile << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)\n";
  myfile << line;

  myfile.close();

  return 0;
}

