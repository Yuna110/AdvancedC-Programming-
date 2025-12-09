#include <iostream>
#include <cctype>  
using namespace std;

int main() {
    string message;
   cout << "Enter a message: "; 
    cin >> message;  

    string result = "";
    
    for (char ch : message) {
        if (islower(ch)) {
            result += toupper(ch);
        }
        else if (isupper(ch)) {
            result += tolower(ch);  
        }
        else {
            result += ch;            
        }
    }

    cout << result;  
    return 0;

}
