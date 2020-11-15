#include <iostream>
#include "Session.h"

using namespace std;

int main(int argc, char** argv)
{
     if(argc != 2) // input json file was not given as argument in terminal
     {
         return 0;
     }
     else // input json file was given as argument in terminal
     {
         Session sess(argv[1]);
         sess.simulate();
     }
    cout<< "Finished Main" << endl;
    return 0;
}
