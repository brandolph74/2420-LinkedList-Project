#include "DynamicString.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstring>

using std::cout;
using std::endl;
using std::out_of_range;
using std::strcmp;
using std::ostringstream;

template <typename T>
void test(int testNum, int& correct, T actual, T expected){

   if(actual == expected){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      cout << "Actual: " << actual << " Expected: " << expected << endl;
   }
}

void testString(int testNum, int& correct, const char* actual, const char* expected){

   if(actual && expected && strcmp(actual, expected) == 0){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      if(actual && expected){
         cout << "Actual: " << actual << " Expected: " << expected << endl;
      }
   }
}

int main(){

   int testNum  = 1;
   int correct = 0;

   /*Basic initialization and accessor checks*/
   /*Checks len, capacity, c_str, char_at, []*/
   cout << "--------Accessor Tests--------" << endl;
   /*Simple string*/
   DynamicString s2("abc");
   test(testNum++, correct, s2.len(), 3);
   test(testNum++, correct, s2.char_at(0), 'a');
   test(testNum++, correct, s2[2], 'c');
   testString(testNum++, correct, s2.c_str(), "abc");

   /*Empty String*/
   DynamicString s1;
   test(testNum++, correct, s1.len(), 0);
   testString(testNum++, correct, s1.c_str(), "");

   /*Long string*/
   DynamicString s3("1234567890qwertyuiopasdfghjklzxcvbnm");
   test(testNum++, correct, s3.len(), 36);
   test(testNum++, correct, s3.char_at(7), '8');

   /*Symbols*/
   DynamicString s4("abc ;2420* Rocks!ABC");
   test(testNum++, correct, s4.len(), 20);
   test(testNum++, correct, s4.char_at(3), ' ');
   testString(testNum++, correct, s4.c_str(), "abc ;2420* Rocks!ABC");

   /*Really long string*/
   DynamicString s5("1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREabc");
   test(testNum++, correct, s5.len(), 63);
   test(testNum++, correct, s5.char_at(10), 'q');
   test(testNum++, correct, s5[61], 'b');
   testString(testNum++, correct, s5.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREabc");

   cout << "--------Output Operator Tests--------" << endl;
   ostringstream output;
   output << s2;
   testString(testNum++, correct, output.str().c_str(), "abc");
   output.str("");
   output.clear();
   output << s3;
   testString(testNum++, correct, output.str().c_str(), "1234567890qwertyuiopasdfghjklzxcvbnm");
   output.str("");
   output.clear();
   output << s4;
   testString(testNum++, correct, output.str().c_str(), "abc ;2420* Rocks!ABC");
   output.str("");
   output.clear();
   output << s1;
   testString(testNum++, correct, output.str().c_str(), "");
   output.str("");
   output.clear();
   output << s2 << s3;
   testString(testNum++, correct, output.str().c_str(), "abc1234567890qwertyuiopasdfghjklzxcvbnm");
   output.str("");
   output.clear();

   cout << "--------Comparison Tests--------" << endl;
   cout << "--------Prefix--------" << endl;
   /*Prefix*/
   test(testNum++, correct, s4.startsWith(s2), true);
   test(testNum++, correct, s2.startsWith(s4), false);
   test(testNum++, correct, s2.startsWith("ac"), false);
   test(testNum++, correct, s2.startsWith(s2), true);
   /*More Prefix tests*/
   test(testNum++, correct, s5.startsWith(s3), true);
   test(testNum++, correct, s3.startsWith(s5), false);
   test(testNum++, correct, s5.startsWith(s5), true);
   test(testNum++, correct, s3.startsWith("1234"), true);
   test(testNum++, correct, s3.startsWith("4321"), false);
   test(testNum++, correct, s3.startsWith("ABC"), false);
   /*Prefix with empty string*/
   test(testNum++, correct, s1.startsWith(s2), false);
   test(testNum++, correct, s2.startsWith(s1), true);

   /*Suffix*/
   cout << "--------Suffix--------" << endl;
   test(testNum++, correct, s5.endsWith(s2), true);
   test(testNum++, correct, s2.endsWith(s5), false);
   test(testNum++, correct, s2.endsWith(s2), true);
   test(testNum++, correct, s2.endsWith("dbc"), false);
   test(testNum++, correct, s2.endsWith("aabc"), false);
   test(testNum++, correct, s3.endsWith("zxcvbnm"), true);
   test(testNum++, correct, s4.endsWith("ABC"), true);
   test(testNum++, correct, s4.endsWith("BBC"), false);
   /*Suffix with empty string*/
   test(testNum++, correct, s1.endsWith(s2), false);
   test(testNum++, correct, s2.endsWith(s1), true);


   /*Comparisions*/
   cout << "--------Compare--------" << endl;
   test(testNum++, correct, s2.compare(s2)==0, true);
   test(testNum++, correct, s2.compare("abc")==0, true);
   test(testNum++, correct, s2.compare("ab")>0, true);
   test(testNum++, correct, s2.compare("bc")<0, true);
   test(testNum++, correct, s3.compare("1234567890qwertyuiopasdfghjklzxcvbnmabc")<0, true);
   test(testNum++, correct, s3.compare("1234567890qwertyuiopasdfghjklzxcvbnm")==0, true);
   test(testNum++, correct, s3.compare("1234567890aqwertyuiopasdfghjkl")>0, true);
   test(testNum++, correct, s4.compare("ABC ;2420* Rocks!ABC")>0, true);

   test(testNum++, correct, s1.compare(s2)<0, true);
   test(testNum++, correct, s2.compare(s1)>0, true);

   cout << "--------iCompare--------" << endl;
   test(testNum++, correct, s2.iCompare(s2)==0, true);
   test(testNum++, correct, s2.iCompare("ABC")==0, true);
   test(testNum++, correct, s2.iCompare("Ab")>0, true);
   test(testNum++, correct, s2.iCompare("Bc")<0, true);
   test(testNum++, correct, s3.iCompare("1234567890qwertyuiopasdfghjklzxcvbnmabc")<0, true);
   test(testNum++, correct, s3.iCompare("1234567890QWErtyuiopasdfghjklzxcvbnm")==0, true);
   test(testNum++, correct, s3.iCompare("1234567890QWEztyuiopasdfghjklzxcvbnm")<0, true);
   test(testNum++, correct, s4.iCompare("ABC ;2420* Rocks!ABC")==0, true);

   test(testNum++, correct, s1.iCompare(s2)<0, true);
   test(testNum++, correct, s2.iCompare(s2)==0, true);

   cout << "--------find--------" << endl;
   test(testNum++, correct, s2.find('a'), 0);
   test(testNum++, correct, s2.find('b'), 1);
   test(testNum++, correct, s2.find('c'), 2);
   test(testNum++, correct, s2.find('d'), -1);
   test(testNum++, correct, s5.find('a'), 20);
   test(testNum++, correct, s5.find('d'), 22);
   test(testNum++, correct, s5.find('a', 21), 60);
   test(testNum++, correct, s5.find('d', 23), -1);

   cout << "--------reverseFind--------" << endl;
   test(testNum++, correct, s2.reverseFind('a'), 0);
   test(testNum++, correct, s2.reverseFind('b'), 1);
   test(testNum++, correct, s2.reverseFind('c'), 2);
   test(testNum++, correct, s2.reverseFind('d'), -1);
   test(testNum++, correct, s5.reverseFind('a'), 60);
   test(testNum++, correct, s5.reverseFind('d'), 22);
   test(testNum++, correct, s5.reverseFind('a', 41), 20);
   test(testNum++, correct, s5.reverseFind('a', 60), 60);
   test(testNum++, correct, s5.reverseFind('d', 20), -1);

   cout << "--------Modification Tests--------" << endl;

   cout << "--------ToUpper--------" << endl;
   /*ToUpper*/
   s1.toUpper();
   test(testNum++, correct, s1.len(), 0);
   testString(testNum++, correct, s1.c_str(), "");

   s2.toUpper();
   test(testNum++, correct, s2.len(), 3);
   testString(testNum++, correct, s2.c_str(), "ABC");

   s4.toUpper();
   testString(testNum++, correct, s4.c_str(), "ABC ;2420* ROCKS!ABC");

   s5.toUpper();
   testString(testNum++, correct, s5.c_str(), "1234567890QWERTYUIOPASDFGHJKLZXCVBNMMNBVCXZLKJHGFDSAPOIUYTREABC");

   /*ToLower*/
   cout << "--------ToLower--------" << endl;
   s1.toLower();
   test(testNum++, correct, s1.len(), 0);
   testString(testNum++, correct, s1.c_str(), "");

   s4.toLower();
   testString(testNum++, correct, s4.c_str(), "abc ;2420* rocks!abc");

   s5.toLower();
   testString(testNum++, correct, s5.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmmnbvcxzlkjhgfdsapoiuytreabc");

   cout << "---------Replace----------" << endl;
   s2.replace('B', 'c');
   testString(testNum++, correct, s2.c_str(), "AcC");
   s2.replace('A', 'a');
   testString(testNum++, correct, s2.c_str(), "acC");
   s2.replace('C', 'c');
   testString(testNum++, correct, s2.c_str(), "acc");
   s2.replace('c', 'b');
   testString(testNum++, correct, s2.c_str(), "abb");
   s2.replace('a', 'b');
   testString(testNum++, correct, s2.c_str(), "bbb");
   s2.replace('b', 'd');
   testString(testNum++, correct, s2.c_str(), "ddd");

   /* Assignment */
   cout << "---------Assignment--------" << endl;
   s2[0] = 'b';
   test(testNum++, correct, s2[0], 'b');
   s3[3] = 'a';
   test(testNum++, correct, s3.char_at(3), 'a');
   s4[1] = 'q';
   test(testNum++, correct, s4.char_at(1), 'q');
   s2[0] = 'a';
   s2[1] = 'b';
   s2[2] = 'c';
   testString(testNum++, correct, s2.c_str(), "abc");


   if(correct != testNum-1){
      cout << "You have not passed all required tests" << endl;
      cout << "Passed " << correct << "/" << testNum-1 << " tests" << endl;
      cout << "Score: 0" << endl;
      exit(1);
   }

   /* Optional tests */
   /*Bounds checking*/
   cout << "---------Additional Tests----------" << endl;
   cout << "---------Bounds checking-----------" << endl;
   try{
      s1.char_at(1);//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      s2.char_at(-1);//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      s1[1];//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      s3[-2];//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      s2[4];//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      s2[6];//out_of_range
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }


   cout << "--------find-indexBounds--------" << endl;
   test(testNum++, correct, s1.find('a'), -1);
   test(testNum++, correct, s2.find('a', 3), -1);
   test(testNum++, correct, s2.find('a', 5), -1);
   test(testNum++, correct, s2.find('a', -1), 0);
   test(testNum++, correct, s1.reverseFind('a'), -1);
   test(testNum++, correct, s2.reverseFind('a', 4), 0);
   test(testNum++, correct, s2.reverseFind('b', 35), 1);
   test(testNum++, correct, s2.reverseFind('a', -1), -1);

   cout << "Passed " << correct << "/" << --testNum << " tests" << endl;
   cout << "Score: " << correct/float(testNum) << endl;
   cout << "Points: " << 60*correct/float(testNum) << endl;

}
