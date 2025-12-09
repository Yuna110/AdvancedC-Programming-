#include <iostream>
#include <cctype>   // for islower, isupper, tolower, toupper
using namespace std;

int main() {
    string message;
   cout << "Enter a message: "; 
    cin >> message;   // input: AbbeF

    string result = "";
    
    for (char ch : message) {
        if (islower(ch)) {
            result += toupper(ch);   // convert to UPPER
        }
        else if (isupper(ch)) {
            result += tolower(ch);   // convert to lower
        }
        else {
            result += ch;            // keep other characters
        }
    }

    cout << result;   // output: aBBEf
    return 0;
}