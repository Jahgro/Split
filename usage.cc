#include <iostream>

void usage()
{
  std::cout << "Usage: filesplit [-b, -k, -m or -g] [size] file\n";
  std::cout << "       b:  bytes\n";
  std::cout << "       k:  kilobytes\n";
  std::cout << "       m:  megabytes\n";
  std::cout << "       g:  gigabytes\n";
  return;
}
