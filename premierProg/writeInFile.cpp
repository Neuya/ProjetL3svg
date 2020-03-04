// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  int val;
  myfile.open ("example.svg");
  <svg width="100" height="100">
  <g id="sol">
  <rect x="0" y="80" width="100" height="20" fill="green"/>
  </g>
  </svg>

  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
