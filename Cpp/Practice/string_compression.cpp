// String Compression
#include <iostream>
#include <string>
using namespace std;

string string_compression(string& str) {
  char alph = str[0];
  int alph_len = 0;
  string result = "";

  for (int i=0; i<=str.length(); i++){
    if (str[i] == alph)
      alph_len += 1;
    else{
      result += alph;
      result += to_string(alph_len);
      alph = str[i];
      alph_len = 1;
    }
  }
  if (str.length() <= result.length())
    return str;
  else
    return result;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        cout<<"Correct usage: [exec file] [string]"<<endl;
        return 1;
    }
    else if (argc == 2){
      string input = argv[1];
      cout << string_compression(input) << endl;
      return 0;
    }
    else{
      while(true){
        string input;
        cin >> input;
        if (input == "Q" || input == "q") break;
        else cout << string_compression(input) << endl;
      }
      return 0;
    }
}
