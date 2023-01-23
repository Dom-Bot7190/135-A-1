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

/*
PART 1
Question 1
*/

// Adds quotes if they do not already surround the string
string quote(string s){
    // Set string variable to 0 indexing to match how characters are labeled
    int strLength=s.length()-1;
    // Add double quotes if input does not already have them
    if(!(strLength > 0 && s[0]=='"' && s[strLength]=='"')){
        s.insert(s.begin(), '"');
        s.push_back('"');
    }
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

/*
Question 2
*/

string to_string(const vector<string>& v){
    string output = "{";

    if(v.size()>0){

        for(int i=0; i<v.size(); i++){
            output.push_back('"');
            output.append(v[i]);
            output.push_back('"');

            if(i<(v.size()-1)){
                output.append(", ");
            }
        }
    }
    output.push_back('}');
    return output;
}


ostream& operator<<(ostream& out, const vector<string>& v){
    return out << to_string(v);
}

void test_to_string(){
    cout << "testing to_string ... ";
    assert(to_string(vector<string>{})              == "{}");
    assert(to_string(vector<string>{"a"})           == "{\"a\"}");
    assert(to_string(vector<string>{"a", "b"})      == "{\"a\", \"b\"}");
    assert(to_string(vector<string>{"a", "b", "c"}) == "{\"a\", \"b\", \"c\"}");
    cout << "all tests passed\n";
}

int main(int argc, char *argv[]){
    cout << "Welcome to assignment 1! Here's what you typed:\n";

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << "\n";

    test_quote();
    test_to_string();


    return 0;
} // main
