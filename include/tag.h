#ifndef TAG_H
#define TAG_H

using namespace std;

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

#include "globals.h"
#include "tokenType.h"
#include "util.h"


void parseTag(const int startPos);
void handleTag(const int startPos);
void handleClosedTag();

void handleToken(const TOKEN token);


#endif