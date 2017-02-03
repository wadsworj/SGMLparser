/*
 * File containing functions for handling of tags/tokens.                           
 * James Wadsworth (0813414)
 */
#include "tag.h"

/*
 * parseTag(const int startPos)
 *     Parse the top string on the stack.
 *
 * int startPos:    1 for OPEN_TAG
 *                  2 for END_TAG
 */
void parseTag(const int startPos) {
    string temp;
    string original = tagStack.top();
    temp = original.substr(startPos, original.length() - (startPos + 1) );  // get rid of <(/) and >
    tagStack.pop();     // remove from stack
    
    if (startPos == 1 && !STATE) {   // only push token back if not between irrelavant tags
        return;
    }

    tagStack.push(toUpperCase(temp));   // push normalized token back to stack
    
    // if we aren't in IRRELANT state, then handle tag
    if (STATE) {
        handleTag(startPos);
    }
}


/*
 * handleTag(const int startPos)
 *     Given a tag, determine if output is to be printed
 *         to stdout
 *
 * int startPos:    1 for OPEN_TAG
 *                  2 for END_TAG
 */
void handleTag(const int startPos) {
    stringstream format;
    string original = tagStack.top();

    // startPos 1 == OPEN_TAG,  startPos 2 == CLOSED_TAG
    if (startPos == 1) {
        format << "OPEN-";
    } else {
        format << "CLOSE-";
    }

    // Test for which tag
    if (original.compare("DOC") == 0) {
        cout << format.str() << "DOC" << endl;
    } else if (original.compare("TEXT") == 0) {
        cout << format.str() << "TEXT" << endl;
    } else if (original.compare("DOCNO") == 0) {
        cout << format.str() << "DOCNO" << endl;
    } else if (original.compare("DATE") == 0) {
        cout << format.str() << "DATE" << endl;
    } else if (original.compare("P") == 0) {
        cout << format.str() << "P" << endl;
    } else if (original.compare("LENGTH") == 0) {
        cout << format.str() << "LENGTH" << endl;
    } else if (original.compare("HEADLINE") == 0) {
        cout << format.str() << "HEADLINE" << endl;
    } else {
        if(startPos == 1) { // ignore tag, enter ignore state
            STATE = 0;
        }
    }
}



/*
 * handleClosedTag()
 *     Special logic needed for closed tags,
 *         such as determining if tags match
 *         and if we are at the end of 'ignored'
 *         content
 */
void handleClosedTag() {
    string open, closed;

    if (!tagStack.empty()) {
        closed = tagStack.top();
        tagStack.pop();
    }

    if (!tagStack.empty()) {
        open = tagStack.top();
    }

    // test if open and closed match
    if (closed.compare(open) == 0) {
        tagStack.pop();

        if (STATE == 0) {
            STATE = 1;
        }
    } else {
        // if we are not ignoring the current opening tag, print
        if (STATE) {
            cout << "ERROR! CLOSED tag does not match OPEN tag!" << endl;
        }
    }
}

/*
 * handleToken(const TOKEN token)
 *     For non OPEN_TAG and CLOSED_TAG tokens,
 *         print to stdout required content
 */
void handleToken(const TOKEN token) {

    switch(token) {
        case END_FILE:
            break;
        case OPEN_TAG:
            break;
        case CLOSE_TAG:
            break;
        case WORD:
            cout << "WORD(" << dataStack.top() << ")" << endl;
            dataStack.pop();
            break;
        case NUMBER:
            cout << "NUMBER(" << dataStack.top() << ")" << endl;
            dataStack.pop();
            break;
        case PUNCTUATION:
            cout << "PUNCTUATION(" << dataStack.top() << ")" << endl;
            dataStack.pop();
            break;
        case APOSTROPHIZED:
            cout << "APOSTROPHIZED(" << dataStack.top() << ")" << endl;
            dataStack.pop();
            break;
        case HYPHENATED:
            cout << "HYPHENATED(" << dataStack.top() << ")" << endl;
            dataStack.pop();
            break;
        default:        // do nothing
            break;
    }
}

