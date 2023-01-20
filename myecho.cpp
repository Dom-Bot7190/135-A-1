// myecho.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name         : Dominic Neil Compton Botelho
// Student ID # : 301393131 
// SFU Email    : dbotelho@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
//
// Notes to the Marker
// -------------------
//
// Tell us something about the assignment you're submitting, for example:
// - are there are any known bugs?
// - are there any missing features?
// - were there any parts you found particularly challenging?
// - did you use any outside sources of help (fully cite them if you did)?
// - what editor and programming tools did you use?
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>    // Do not #include any other files.
#include <vector>      //
#include <string>      // You do not need to use functions from all these
#include <algorithm>   // #includes.
#include <cassert>     //

using namespace std;

// Adds quotes if they do not already surround the string
string quote(string s){
    int strLength=0;
    
    for(int i=0; s[i]; i++){
        strLength = i;
    }
    
    if(s[1]=='"' && s[strLength]=='"'){
        return s;
    } 
    
    for(int i=strLength; i>=0; i--){
        s[i] = s[i++];
    }

    strLength++;
    s[strLength+1] = '"';
    s[0] = '"';

    return s;
}

void test_quote(){
    cout << "testing quote ... ";
    assert(quote("a"      ) == "\"a\""   );
    assert(quote("ab"     ) == "\"ab\""  );
    assert(quote("\"a\""  ) == "\"a\""   );
    assert(quote("\"ab\"" ) == "\"ab\""  );
    assert(quote("a\"b"   ) == "\"a\"b\"");
    assert(quote("\"a"    ) == "\"\"a\"" );
    assert(quote("a\""    ) == "\"a\"\"" );
    assert(quote(""       ) == "\"\""    );
    assert(quote("\""     ) == "\"\"\""  );
    cout << "all tests passed\n";
}

int main(int argc, char *argv[]) {
    cout << "Welcome to assignment 1! Here's what you typed:\n";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << "\n";
} // main
