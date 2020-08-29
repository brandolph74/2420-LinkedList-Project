#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;
using std::vector;

DynamicString::DynamicString(){
    cstr = new char[1];
    this->cstr[0] = '\0';
    //creates empty cstring with the first character being null
}

DynamicString::DynamicString(const char* str){
    int lengthOfString  = 0;        //get the length of the string
    while (str[lengthOfString] != '\0')                  //gets the length of the string for the for loop below, can't use len() function yet
    {
        lengthOfString++;
    }
    cstr = new char[lengthOfString + 1];
    for (int i = 0; i < lengthOfString; i++)           //initiate the loop to put the str values into cstr
    {
        cstr[i] = str[i];
    }
    cstr[lengthOfString] = '\0';

    //cstr = const_cast<char*>(str);
    /*i = 0;
    while (i <= length)
    {
        if (i == length)                  //catches if i is past the last character, puts null
        {
            char temp = '\0';
            this->cstr[i] = temp;
            break;
        }

        char temp = str[i];
        this->cstr[i] = temp;
        i++;
    }
       */     //found on stack overflow, 5 hours trying to solve this for one line
}

int DynamicString::len() const{

    int count = 0;
    while (this->cstr[count] != '\0')               //gets the length of the object's c string
    {
       count++;
    }
    return count;


}

const char* DynamicString::c_str() const{

    return cstr;                         //returns cstr, deleted the stuff required by the commment
}

char DynamicString::char_at(int position) const{
    return this->cstr[position];                     //returns the character that is at the position of the index
}

char& DynamicString::operator[](int position){

    return cstr[position];
}

bool DynamicString::startsWith(const DynamicString& other) const{

    for(int i = 0; i < other.len() && i <= this->len(); i++)
    {
        if (this->len() == 0)                //check if the length of the c string being tested by other is 0, false if true
        {
            return false;
        }
        if(other.cstr[i] != '\0' && other.cstr[i] == this->cstr[i])        //continues the loop, should be removed since it does nothing
        {

        }
        if (other.cstr[i] != this->cstr[i] || other.len() > this->len())         //catches if the character does not equal other's character and checks if other's length is greater than this length
        {
            return false;
            break;
        }
    }
         return true;


    /* int count = 0;
    if (other.cstr[count] != '\0')
    {
        while (other.cstr[count] != '\0')
        {
            if (other.cstr[count] = this->cstr[count])                          // old formula, scrapped it
            {
                 count++;
            }
        }

    }
    return true;
     */
return true;
}
bool DynamicString::endsWith(const DynamicString& other) const{
    if (other.len() > this->len())     //checks if ending string is bigger than base string
    {
       return false;
    }
    if (other.len() == 0)          //checks if ending string's length is nothing, which means true
    {
        return true;
    }
    int countOther = other.len() - 1;          //holds the index for the suffixx string, will itterate through
    int countThis = this->len() - 1;          //holds the index for the object string, will itterate through
    while(countOther >= 0)                    //loop that tests the suffix
    {
        if (this->cstr[countThis] != other.cstr[countOther])           //checks if they are not equal
        {
            return false;
        }
        if (this->cstr[countThis] == other.cstr[countOther])           //checks if chars are equal
        {
            countThis--;
            countOther--;
        }

    }
    return true;
}

int DynamicString::compare(const DynamicString& other) const{
    int thisLength = this->len() - 1;                             //set variables for the lengths of the two strings being compared to avoid using len() function a million times for debugger
    int otherLength = other.len() - 1;
    if (thisLength < 0)          //checks if the original string is 0, will return 1 due to it being empty
    {
        return -1;
    }
    if (otherLength < 0)
    {
        return 1;
    }
    for (int i = 0; i <= thisLength && i <= otherLength;  i++)             //initiate the loop checking each character and how they stack up to each other , kept the len() function in this one
    {
        if (this->cstr[i] == other.cstr[i])                      //checks to see if characters are equal
        {
            if (i == thisLength || i == otherLength)         //checks to see if at the end of a string, from here the longer string will come later
            {
                if (thisLength > otherLength)               //compared string is smaller than this, so we return 1;
                {
                    return 1;
                }
                if (thisLength < otherLength)             //compared string is bigger than this, so we return -1;
                {
                    return -1;
                }
                if (thisLength = otherLength)           //if equal, passes test
                {
                    return 0;
                }
            }
        }
        else
        {
            if (this->cstr[i] > other.cstr[i])
            {
                return 1;
            }
            if (this->cstr[i] < other.cstr[i])
            {
                return -1;
            }
        }
    }
    return 0;
}

int DynamicString::iCompare(const DynamicString& other) const{
    int thisLength = this->len() - 1;                             //set variables for the lengths of the two strings being compared to avoid using len() function a million times for debugger
    int otherLength = other.len() - 1;
    char thisChar;                            //added character variables for iCompare
    char otherChar;

    if (thisLength < 0)          //checks if the original string is 0, will return 1 due to it being empty
    {
        return -1;
    }
    if (otherLength < 0)
    {
        return 1;
    }
    for (int i = 0; i <= thisLength && i <= otherLength;  i++)             //initiate the loop checking each character and how they stack up to each other , kept the len() function in this one
    {
        thisChar = this->cstr[i];                                         //adding the characters to the character variables
        otherChar = other.cstr[i];

        if ((thisChar <= 'z' && thisChar >= 'a') || (thisChar <= 'Z' && thisChar >= 'A'))            //if thisChar is part of the alphabet, send to lowercase
        {
            thisChar = tolower(thisChar);
        }
        if ((otherChar <= 'z' && otherChar >= 'a') || (otherChar <= 'Z' && otherChar >= 'A'))            //if otherChar is part of the alphabet, send to lowercase
        {
            otherChar = tolower(otherChar);
        }

        if (thisChar == otherChar)                      //checks to see if characters are equal
        {
            if (i == thisLength || i == otherLength)         //checks to see if at the end of a string, from here the longer string will come later
            {
                if (thisLength > otherLength)               //compared string is smaller than this, so we return 1;
                {
                    return 1;
                }
                if (thisLength < otherLength)             //compared string is bigger than this, so we return -1;
                {
                    return -1;
                }
                if (thisLength == otherLength)           //if equal, passes test
                {
                    return 0;
                }
            }
        }
        else
        {
            if (thisChar > otherChar)
            {
                return 1;
            }
            if (thisChar < otherChar)
            {
                return -1;
            }
        }
    }
    return 0;;
}

DynamicString& DynamicString::toLower(){
   for (int i = 0; i < this->len(); i++)                     //loop for iterating through the c string and converting characters that are letters into lowercase
   {
       if (cstr[i] == '\0')                                     //checks if character at the position is null
       {
           return *this;
       }
       char replace = cstr[i];
       if ((replace <= 'z' && replace >= 'a') || (replace <= 'Z' && replace >= 'A'))                           //checks if character is a letter before smacking it into lowercase
       {
           replace = tolower(replace);
           cstr[i] = (replace);
       }


   }

    return (*this);
}


DynamicString& DynamicString::toUpper(){               //just copied over from to lower
    for (int i = 0; i < this->len(); i++)                     //loop for iterating through the c string and converting characters that are letters into lowercase
    {
        if (cstr[i] == '\0')                                     //checks if character at the position is null
        {
            return *this;
        }
        char replace = cstr[i];
        if ((replace <= 'z' && replace >= 'a') || (replace <= 'Z' && replace >= 'A'))                           //checks if character is a letter before smacking it into lowercase
        {
            replace = toupper(replace);
            cstr[i] = (replace);
        }


    }return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
    int length = this->len();
    if (length == 0)                        //returns the c string if it is shown to be empty
   {
       return *this;
   }
    int i = 0;
    while (i < length)
    {
        if (this->cstr[i] == old)
        {
            this->cstr[i] = newCh;
        }

        i++;
    }

    return *this;
}

int DynamicString::find(char c, int start) const{
    int position = 0;       //holder for any found positions, defaults to -1
    if (this->len() <= 1 || start > this->len() -1 )      //checks if the first position is 0, returns -1;
        {
            return -1;
        }
    for (int i = start; i <= this->len() - 1; i++)         //initialize the loop to go through the c string contents
    {
        char cTemp = cstr[i];                    //create that temporary string to hold the value, most likely unneccessary
        if (cTemp == c)                          //checking
        {
            position = i;                       //scrapped
            return i;
        }
    }

   return -1;
}

int DynamicString::reverseFind(char c, int start) const{
    int position = 0;       //holder for any found positions, defaults to -1
    if (this->len() <= 1 || start > this->len() -1 )      //checks if the first position is 0, returns -1;
    {
        return -1;
    }
    for (int i = start; i >= 0; i--)         //initialize the loop to go through the c string contents
    {
        char cTemp = cstr[i];                    //create that temporary string to hold the value, most likely unneccessary
        if (cTemp == c)                          //checking
        {
            position = i;                       //scrapped
            return i;
        }
    }

    return -1;
}

int DynamicString::reverseFind(char c) const{
    int position = 0;       //holder for any found positions, defaults to -1
    if (this->len() <= 1)      //checks if the first position is 0, returns -1;
    {
        return -1;
    }
    for (int i = this->len()-1; i >= 0; i--)         //initialize the loop to go through the c string contents
    {
        char cTemp = cstr[i];                    //create that temporary string to hold the value, most likely unneccessary
        if (cTemp == c)                          //checking
        {
            position = i;                       //scrapped
            return i;
        }
    }

    return -1;;
}

ostream& operator<<(ostream& out, const DynamicString& str){


    out << str.cstr;
    return out;
}
