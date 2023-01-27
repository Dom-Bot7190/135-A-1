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

void helpMsg(){
    cout << "Usage: ./myecho [-runtests|-(hrs)] [string ...]\n"
         << "   -runtests: run the tests\n"
         << "              over-rides single-character flags\n"
         << "          -h: print this help message\n"
         << "              over-rides other single-character flags\n"
         << "          -r: print the strings in reverse order\n"
         << "          -s: no space between arguments\n"
         << "          -q: quote the printed results\n"
         << "    -rs, -sr: no space between arguments, in reverse order\n"
         << "\n"
         << "   Repeated single-character flags are allowed (and are ignored).\n"
         << "   Unknown flags cause an error.\n"
         << "\n" << "\n"
         << "Examples:\n"
         << "   ❯ ./myecho -q\n"
         << "   \"\"\n"
         << "   ❯ ./myecho x y z\n"
         << "   x y z\n"
         << "   ❯ ./myecho -q x y z\n"
         << "   \"x y z\"\n"
         << "   ❯ ./myecho -sr x y z\n"
         << "   zyx\n"
         << "   ❯ ./myecho -h\n";
}

void runTests(){
    test_quote();
    test_to_string();
}

void printStr(int strCount, char *strArray[], int firstStrPos, bool sFlag, bool rFlag){
    bool firstStr = true;
    if(rFlag){
        for (int i = (strCount-1); i > 1; i--) {
            if((i<(strCount-1))&&(!sFlag)){
                cout << " ";
            }
            cout << strArray[i];
        }
    } else {
        for (int i = firstStrPos; i < strCount; i++) {
            if((!firstStr)&&(!sFlag)){
                cout << " ";
            }
            cout << strArray[i];
            firstStr = false;
        }
    }
}

int main(int argc, char *argv[]){
    bool qFlag = false;
    bool sFlag = false;
    bool rFlag = false;
    int firstStrPos = 1;    
    
    // Don't run if no input is given
    if(!argv[1]){
        return 0;
    }

    // Check the first character to see if a flag has been entered
    string flag = argv[1]; 
    if(flag[0] == '-'){
        firstStrPos++;

        // Highest prescedence flags
        if(flag == "-runtests"){
            runTests();
            return 0;
        } else if(flag.find('h')<flag.length()){
            helpMsg();
            return 0;
        } else {
            // Lower prescedence flags
            qFlag = (flag.find('q')<flag.length());
            sFlag = (flag.find('s')<flag.length());
            rFlag = (flag.find('r')<flag.length());
        }
    }
    
    if(qFlag){
        cout << '"';
    }

    printStr(argc, argv, firstStrPos, sFlag, rFlag);

    if(qFlag){
        cout << '"';
    }
    cout << "\n";

    return 0;
} // main