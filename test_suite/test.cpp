#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>


#include "test.h"

void run_tests(){
    ifstream input_stream;

    cout << "We are running our tests" << endl;

    stringstream format;

    for (int i = 0; ; i++) {
        format << "files/test_file_" << i << endl;
        input_stream.open(format.str().c_str(), ios::in);

        if (!input_stream) {
            cout << "File not found!" << endl;
            break;
        }
        cout << "Opened file!" << format.str() << endl;
        // open file
        format.str("");
        input_stream.close();
    }
}
