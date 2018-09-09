#include <fstream>
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main(){
   std::string directoryName;

  path p = boost::filesystem::current_path();
  std::cout << p.filename() << std::endl;
  std::string line = "add_executable(" + p.filename().string() + " ${SOURCES})";
  std::ofstream myfile;
  if ( boost::filesystem::exists( "CMakeLists.txt" ) ){
    return 0;
  }
  myfile.open ("CMakeLists.txt");

  myfile << "cmake_minimum_required (VERSION 3.0)\n";
  myfile << "project(" << p.filename().string() << ")\n\n";

  myfile << "file(GLOB SOURCES \"*.cpp\")\n";

  myfile << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)\n";
  myfile << line;

  myfile.close();

  return 0;
}

