#include <iostream>
#include <string>
#include "forum.h"
#include <cstdlib>
#include <ctime> 

using namespace std;

int main()
{
  srand(0);
  Forum e("Antikeimenostrafhs programmatismos");
  cout<<endl;
  e.print_sorted();
  return 0;
}

