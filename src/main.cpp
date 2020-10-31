#include <iostream>
#include "Session.h"
#include "Graph.h"
#include "Agent.h"
#include "Tree.h"
#include <nlohmann/json.hpp>

using namespace std;


int main(int argc, char** argv)
{
     if(argc != 2) // json file for testing was given
     {
         cout << "usage cTrace <config_path>" << endl;
         return 0;
     }
    // Session sess(argv[1]);
    // sess.simulate();
    cout<< "Hello World!" << endl;

    return 0;
}