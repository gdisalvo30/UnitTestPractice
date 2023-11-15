#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

  /*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
  */
bool Password::has_mixed_case(string phrase) {
  int index = 0;
  bool uppercheck = false;
  bool lowercheck = false;

  while( index < phrase.length()){
    if (isupper(phrase[index])) {
      uppercheck = true;
    }
    if (islower(phrase[index])) {
      lowercheck = true;
    }
    index++;
  }

  if(uppercheck == true && lowercheck == true) {
    return true;
  } else {
    return false;
  }

}

  Password::Password() {
    pass_history.push_back("ChicoCA-95929");
  }

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string pw) {
    if (pw.size() < 8) {
      return false;
    } 
    if (pw[0] == pw[1] && pw[1] == pw[2] && pw[0] == pw[2]) {
      return false;
    }
    if (!has_mixed_case(pw)) {
      return false;
    }
    for (int i = 0; i < pass_history.size(); i++) {
      if (pw == pass_history[i]) {
        return false;
      }
    }
    return true;
  }

    /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string pw) {
  if (authenticate(pw)) {
    pass_history.push_back(pw);
  }

  }

