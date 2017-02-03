/*
 * File containing main() function for scanner program.                           
 * James Wadsworth (0813414)
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "scanner.h"
#include "globals.h"
#include "util.h"
#include "tag.h"
#include "test.h"

// test if testing suite is enabled
#ifdef TEST_SUITE
#endif

int STATE;  // STATE, a global variable that keeps track of RELEVANT vs IGNORED content
                // 1 RELEVANT
                // 2 IGNORED

// flex global variables
extern FILE * yyin;
extern FILE * yyout;


/*
 * main() function
 *     Entry point to the program.
 */
main( int argc, char * argv[] ) {
    yyin = stdin;
    yyout = stdout;
    TOKEN token;

    STATE = 1;

// code for test_suite, ignore...
#ifdef TEST_SUITE
    run_tests();
    return 0;
#endif

    // parse document
    while( (token = getToken()) != END_FILE ) {
        if (token == OPEN_TAG) {
            parseTag(1);
        } else if (token == CLOSE_TAG) {
            parseTag(2);
            handleClosedTag();
        }
        if (STATE){ // if STATE == RELEVANT
            handleToken(token);
        }
    }
    // print any unmatched open tags to user
    while (!tagStack.empty()) {
        cout << tagStack.top() << " was unmatched" << endl;
        tagStack.pop();
    }

    return 0;
}