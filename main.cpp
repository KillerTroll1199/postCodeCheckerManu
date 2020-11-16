#include <iostream>
using namespace std;

bool isNumber(char letter)
{
    bool isNum = false;
        if(letter>= '0' && letter <= '9')
        {
            isNum = true;
        }

        return isNum;
}
bool isLetter(char letter)
{
    bool isLetter = false;

    if(letter>= 'A' && letter <= 'Z')
    {
        isLetter = true;
    }
    else if(letter >= 'a' && letter <= 'z')
    {
      isLetter = true;
    }

    return isLetter;
}

bool isValidLastThreeChars(char first, char second, char third)
{
    bool isValid = false;

    if((isNumber(first) == true) && (isLetter(second) == true) && (isLetter(third) == true))
    {
        isValid = true;
    }
    if((second == 'C' || second == 'c') || (second == 'I' || second == 'i') || (second == 'K' || second == 'k') || (second == 'M' || second == 'm') || (second == 'O' || second == 'o') || (second == 'V' || second == 'v') || (third == 'C' || third == 'c') || (third == 'I' || third == 'i') || (third == 'K' || third == 'k') || (third == 'M' || third == 'm') || (third == 'O' || third == 'o') || (third == 'V' || third == 'v'))
    {
        isValid = false;
    }

    return isValid;
}

bool thirdPos(char letter)
{
  if((letter == 'A' || letter == 'a') || (letter == 'B'  || letter == 'b') || (letter == 'C'  || letter == 'c') || (letter == 'D' || letter == 'd') || (letter == 'E' || letter == 'e') || (letter == 'F' || letter == 'f') || (letter == 'G' || letter == 'g') || (letter == 'H' || letter == 'h') || (letter == 'J' || letter == 'j') || (letter == 'K' || letter == 'k') || (letter == 'S' || letter == 's') || (letter == 'T' || letter == 't') || (letter == 'U' || letter == 'u') || (letter == 'W' || letter == 'w'))
  {
      return true;
  }

  return false;
}

bool firstCharValid(char letter)
{
    if((isLetter(letter) == true) && (letter != 'Q' || letter != 'q') && (letter != 'V' || letter != 'v') && (letter != 'X'  || letter != 'x'))
    {
        return true;
    }
    return false;
}

bool secondCharValid(char letter)
{
    if((isLetter(letter) == true) && (letter != 'I'  || letter != 'i') && (letter != 'J' || letter != 'i') && (letter != 'Z' || letter != 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string postcode;

    while(1)
    {
        cout<<"Enter Postcode: ";
        getline(cin, postcode);
        if(postcode.length() == 8)
        {
            char first = postcode[0];
            char second = postcode[1];
            char third = postcode[2];
            char fourth = postcode[3];
            char fifth = postcode[5];
            char sixth = postcode[6];
            char seventh = postcode[7];

            if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNumber(third) == true) && (isNumber(fourth) == true) && (isValidLastThreeChars(fifth, sixth, seventh) == true))
            {
                cout<<"Postcode - Valid"<<endl;
            }
            else if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNumber(third) == true) && (isLetter(fourth) == true) && (isValidLastThreeChars(fifth, sixth, seventh) == true))
            {
                cout<<"Postcode - Valid"<<endl;
            }
            else
            {
                cout<<"Postcode - Invalid"<<endl;
            }
        }
        else if(postcode.length() == 7)
        {
            char first = postcode[0];
            char second = postcode[1];
            char third = postcode[2];
            char fourth = postcode[4];
            char fifth = postcode[5];
            char sixth = postcode[6];

            if((firstCharValid(first) == true) && (isNumber(second) == true) && (isNumber(third) == true) && (isValidLastThreeChars(fourth, fifth, sixth) == true))
            {
                cout<<"Postcode - Valid"<<endl;
            }
            else if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNumber(third) == true) && (isValidLastThreeChars(fourth, fifth, sixth) == true))
            {
                cout<<"Postcode - Valid"<<endl;
            }
            else if((firstCharValid(first) == true) && (isNumber(second) == true) && (thirdPos(third) == true) && (isValidLastThreeChars(fourth, fifth, sixth) == true))
            {
                cout<<"Postcode - Valid"<<endl;
            }
            else
            {
                cout<<"Postcode - Invalid"<<endl;
            }
        }
        else if(postcode.length() == 6)
        {
            char first = postcode[0];
            char second = postcode[1];
            char third = postcode[3];
            char fourth = postcode[4];
            char fifth = postcode[5];

            if((firstCharValid(first) == true) && (isNumber(second) == true) && (isValidLastThreeChars(third, fourth, fifth) == true))
            {
                cout<<"Postcode - Valid"<<endl;
                break;
            }
            else
            {
                cout<<"Postcode - Invalid"<<endl;
            }
        }
        else
        {
          cout<<"Postcode - Invalid"<<endl;
        }
    }
}