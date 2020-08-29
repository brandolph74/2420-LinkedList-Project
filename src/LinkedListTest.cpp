#include "LinkedList.h"
#include "MemberDO.h"

#include<iostream>
#include<string>
#include<stdexcept>
#include<sstream>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::out_of_range;


template <typename elemType>
bool checkTest(string testName, elemType whatItShouldBe, elemType whatItIs);
bool testConstructor();
bool testInsert();
bool testOutput();
bool testGets();
bool testFind();
bool testRemove();
bool testClear();
bool testDeepCopy();
bool testTemplate();
void testOther();

int main()
{
   int passed = 0;
   passed += testConstructor();
   passed += testInsert();
   passed += testGets();
   passed += testFind();
   passed += testRemove();
   passed += testClear();
   passed += testDeepCopy();
   passed += testTemplate();

   if(passed < 8){
      cout << "You have passed " << passed << "/8 required tests" << endl;
      cout << "Please go back and fix your code so that it passes all required tests" << endl;
      cout << "Score: 0/60" << endl;
      exit(1);
   }
   else{
      cout << "Congratulations! You have passed all required test cases" << endl;
      cout << "Score: 60/60" << endl;
   }

   testOther();

   return 0;
}

bool testConstructor(){
   bool passed = true;
   cout << "-------------Test Constructor--------------" << endl;
   OrderedLinkedList<int> intList;
   passed &= checkTest("Constructor 1", intList.size(), 0);
   passed &= checkTest("Constructor 2", intList.empty(), true);
   OrderedLinkedList<char> charList;
   passed &= checkTest("Constructor 3", charList.size(), 0);
   passed &= checkTest("Constructor 4", charList.empty(), true);
   return passed;
}

bool testInsert(){
   bool passed = true;
   cout << "-------------Test Insert--------------" << endl;
   OrderedLinkedList<int> intList;
   //insert - empty list
   intList.insert(100);
   passed &= checkTest("Insert 1", intList.size(), 1);
   passed &= checkTest("Insert 2", intList.get(0), 100);
   passed &= checkTest("Insert 3", intList.empty(), false);
   //insert - first
   intList.insert(28);
   passed &= checkTest("Insert 4", intList.size(), 2);
   passed &= checkTest("Insert 5", intList.get(0), 28);
   passed &= checkTest("Insert 6", intList.get(1), 100);
   //insert - last
   intList.insert(395);
   passed &= checkTest("Insert 7", intList.size(), 3);
   passed &= checkTest("Insert 8", intList.get(0), 28);
   passed &= checkTest("Insert 9", intList.get(1), 100);
   passed &= checkTest("Insert 10", intList.get(2), 395);
   //insert - middle
   intList.insert(35);
   passed &= checkTest("Insert 11", intList.get(1), 35);
   passed &= checkTest("Insert 12", intList.get(2), 100);
   passed &= checkTest("Insert 13", intList.get(3), 395);
   passed &= checkTest("Insert 14", intList.get(0), 28);
   passed &= checkTest("Insert 15", intList.empty(), false);
   OrderedLinkedList<char> charList;
   charList.insert('w');
   charList.insert('i');
   charList.insert('n');
   charList.insert('z');
   passed &= checkTest("Insert 16", charList.get(0), 'i');
   passed &= checkTest("Insert 17", charList.get(3), 'z');
   passed &= checkTest("Insert 18", charList.get(2), 'w');
   passed &= checkTest("Insert 19", charList.get(1), 'n');
   return passed;
}

bool testGets(){
   bool passed = true;
   cout << "-------------Test Gets--------------" << endl;
   OrderedLinkedList<int> intList;
   intList.insert(100);
   passed &= checkTest("Get 2", intList.getFirst(), 100);
   passed &= checkTest("Get 3", intList.getLast(), 100);
   intList.insert(28);
   passed &= checkTest("Get 4", intList.getFirst(), 28);
   passed &= checkTest("Get 5", intList.getLast(), 100);
   intList.insert(395);
   passed &= checkTest("Get 6", intList.getFirst(), 28);
   passed &= checkTest("Get 7", intList.getLast(), 395);
   intList.insert(35);
   passed &= checkTest("Get 8", intList.getFirst(), 28);
   passed &= checkTest("Get 9", intList.getLast(), 395);
   return passed;
}

bool testFind(){
   bool passed = true;
   cout << "-------------Test Find--------------" << endl;
   OrderedLinkedList<int> intList;
   intList.insert(6);
   intList.insert(1);
   intList.insert(3);
   intList.insert(7);
   passed &= checkTest("Find 1", intList.find(7), 3);
   passed &= checkTest("Find 2", intList.find(6), 2);
   passed &= checkTest("Find 3", intList.find(2), -1);
   passed &= checkTest("Find 4", intList.find(1), 0);
   passed &= checkTest("Find 5", intList.find(4), -1);
   OrderedLinkedList<char> charList;
   charList.insert('d');
   charList.insert('o');
   charList.insert('n');
   charList.insert('e');
   passed &= checkTest("Find 6", charList.find('d'), 0);
   passed &= checkTest("Find 7", charList.find('e'), 1);
   passed &= checkTest("Find 8", charList.find('2'), -1);
   passed &= checkTest("Find 9", charList.find('o'), 3);
   passed &= checkTest("Find 10", charList.find('a'), -1);
   OrderedLinkedList<double> dList;
   passed &= checkTest("Find 11", dList.find(2.5), -1);
   dList.insert(2.5);
   passed &= checkTest("Find 11", dList.find(2.5), 0);
   return passed;

}

bool testOutput(){
   bool passed = true;
   cout << "-------------Test Output--------------" << endl;
   OrderedLinkedList<int> intList;
   ostringstream output;
   output << intList;
   passed &= checkTest("Output 1", output.str(), string(""));
   output.str("");
   output.clear();
   intList.insert(4);
   output << intList;
   passed &= checkTest("Output 2", output.str(), string("4"));
   output.str("");
   output.clear();
   intList.insert(8);
   output << intList;
   passed &= checkTest("Output 3", output.str(), string("4->8"));
   output.str("");
   output.clear();
   intList.insert(2);
   output << intList;
   passed &= checkTest("Output 4", output.str(), string("2->4->8"));
   output.str("");
   output.clear();
   intList.insert(5);
   output << intList;
   passed &= checkTest("Output 5", output.str(), string("2->4->5->8"));
   output.str("");
   output.clear();
   return passed;
}

bool testRemove(){
   bool passed = true;
   cout << "-------------Test Remove--------------" << endl;
   OrderedLinkedList<int> intList;
   intList.insert(6);
   intList.remove(6);
   passed &= checkTest("Remove 1", intList.find(6), -1);
   passed &= checkTest("Remove 2", intList.size(), 0);
   passed &= checkTest("Remove 3", intList.empty(), true);
   intList.insert(2);
   passed &= checkTest("Remove 4", intList.find(2), 0);
   passed &= checkTest("Remove 5", intList.get(0), 2);
   passed &= checkTest("Remove 6", intList.getFirst(), 2);
   passed &= checkTest("Remove 7", intList.getLast(), 2);
   intList.insert(6);
   intList.insert(1);
   intList.insert(3);
   intList.insert(7);
   intList.remove(1);
   passed &= checkTest("Remove 8", intList.find(1), -1);
   passed &= checkTest("Remove 9", intList.size(), 4);
   passed &= checkTest("Remove 10", intList.empty(), false);
   passed &= checkTest("Remove 11", intList.get(0), 2);
   passed &= checkTest("Remove 12", intList.get(2), 6);
   passed &= checkTest("Remove 13", intList.getFirst(), 2);
   passed &= checkTest("Remove 14", intList.getLast(), 7);
   ostringstream output;
   output << intList;
   passed &= checkTest("Remove 15", output.str(), string("2->3->6->7"));
   output.str("");
   output.clear();
   intList.remove(3);
   passed &= checkTest("Remove 16", intList.find(3), -1);
   passed &= checkTest("Remove 17", intList.size(), 3);
   passed &= checkTest("Remove 18", intList.get(1), 6);
   output << intList;
   passed &= checkTest("Remove 19", output.str(), string("2->6->7"));
   output.str("");
   output.clear();
   passed &= checkTest("Remove 20", intList.getFirst(), 2);
   passed &= checkTest("Remove 21", intList.getLast(), 7);
   intList.remove(7);
   passed &= checkTest("Remove 22", intList.find(7), -1);
   passed &= checkTest("Remove 23", intList.size(), 2);
   output << intList;
   passed &= checkTest("Remove 24", output.str(), string("2->6"));
   output.str("");
   output.clear();
   passed &= checkTest("Remove 25", intList.get(1), 6);
   passed &= checkTest("Remove 26", intList.getFirst(), 2);
   passed &= checkTest("Remove 27", intList.getLast(), 6);
   intList.remove(6);
   passed &= checkTest("Remove 28", intList.find(6), -1);
   passed &= checkTest("Remove 29", intList.get(0), 2);
   passed &= checkTest("Remove 30", intList.getFirst(), 2);
   passed &= checkTest("Remove 31", intList.getLast(), 2);
   output << intList;
   passed &= checkTest("Remove 32", output.str(), string("2"));
   output.str("");
   output.clear();
   intList.remove(2);
   passed &= checkTest("Remove 33", intList.find(2), -1);
   passed &= checkTest("Remove 34", intList.size(), 0);
   passed &= checkTest("Remove 35", intList.empty(), true);
   output << intList;
   passed &= checkTest("Remove 36", output.str(), string(""));
   output.str("");
   output.clear();
   return passed;
}

bool testClear(){
   bool passed = true;
   cout << "-------------Test Clear--------------" << endl;
   OrderedLinkedList<int> intList;
   intList.insert(5);
   intList.clear();
   passed &= checkTest("Clear 1", intList.size(), 0);
   passed &= checkTest("Clear 2", intList.empty(), true);
   passed &= checkTest("Clear 3", intList.find(5), -1);
   ostringstream output;
   output << intList;
   passed &= checkTest("Clear 4", output.str(), string(""));
   output.str("");
   output.clear();
   intList.insert(4);
   intList.insert(374);
   intList.insert(234);
   intList.clear();
   passed &= checkTest("Clear 5", intList.size(), 0);
   passed &= checkTest("Clear 6", intList.empty(), true);
   passed &= checkTest("Clear 7", intList.find(234), -1);
   output << intList;
   passed &= checkTest("Clear 8", output.str(), string(""));
   output.str("");
   output.clear();
   return passed;
}

bool testDeepCopy(){
   bool passed = true;
   cout << "-------------Test Deep Copy--------------" << endl;
   OrderedLinkedList<int> intList;
   intList.insert(12);
   intList.insert(2);
   intList.insert(15);
   OrderedLinkedList<int> copiedList(intList);
   passed &= checkTest("Deep Copy 1", intList.size(), 3);
   passed &= checkTest("Deep Copy 2", copiedList.size(), 3);
   ostringstream output;
   output << intList;
   passed &= checkTest("Deep Copy 3", output.str(), string("2->12->15"));
   output.str("");
   output.clear();
   output << copiedList;
   passed &= checkTest("Deep Copy 4", output.str(), string("2->12->15"));
   output.str("");
   output.clear();
   intList.insert(8);
   output << intList;
   passed &= checkTest("Deep Copy 5", output.str(), string("2->8->12->15"));
   output.str("");
   output.clear();
   output << copiedList;
   passed &= checkTest("Deep Copy 6", output.str(), string("2->12->15"));
   output.str("");
   output.clear();
   copiedList = intList;
   passed &= checkTest("Deep Copy 7", intList.size(), 4);
   passed &= checkTest("Deep Copy 8", copiedList.size(), 4);
   copiedList.remove(15);
   output << intList;
   passed &= checkTest("Deep Copy 9", output.str(), string("2->8->12->15"));
   output.str("");
   output.clear();
   output << copiedList;
   passed &= checkTest("Deep Copy 10", output.str(), string("2->8->12"));
   output.str("");
   output.clear();
   return passed;
}

bool testTemplate(){
   bool passed = true;
   cout << "-------------Test Template--------------" << endl;
   OrderedLinkedList<MemberDO> memberList;
   passed &= checkTest("Templates 1", memberList.size(), 0);
   MemberDO data;
   data.setKey(2555);
   data.setLastName("Smith");
   data.setFirstInitial('J');
   data.setDues(15.15);
   memberList.insert(data);
   passed &= checkTest("Templates 2", memberList.size(), 1);
   passed &= checkTest("Templates 3", memberList.get(0).getKey(), 2555);
   MemberDO data1(25, "Rogers", 'A', 17.50);
   memberList.insert(data1);
   passed &= checkTest("Templates 4", memberList.find(data1), 0);
   passed &= checkTest("Templates 5", memberList.get(0).getLastName(), string("Rogers"));
   memberList.insert(MemberDO(3100, "Jackson", 'M', 250.00));
   passed &= checkTest("Templates 6", memberList.get(2).getKey(), 3100);
   memberList.insert(MemberDO(2660, "Franklin", 'F', 20.00));
   passed &= checkTest("Templates 7", memberList.get(2).getFirstInitial(), 'F');
   passed &= checkTest("Templates 8", memberList.get(0).getDues(), 17.50);
   data = MemberDO(3100, "Jackson", 'M', 250.00);
   passed &= checkTest("Templates 9", memberList.find(data), 3);
   memberList.remove(data);
   passed &= checkTest("Templates 10", memberList.find(data), -1);
   return passed;
}

void testOther(){
   int passed = 0;
   cout << "-------------Test Other--------------" << endl;
   OrderedLinkedList<int> intList;
   OrderedLinkedList<int> odd;
   OrderedLinkedList<int> even;
   intList.insert(9);
   odd = intList.everyOtherOdd();
   passed += checkTest("Other 1", odd.size(), 1);
   ostringstream output;
   output << odd;
   passed += checkTest("Other 2", output.str(), string("9"));
   output.str("");
   output.clear();
   intList.insert(4);
   even = intList.everyOtherEven();
   passed += checkTest("Other 3", even.size(), 1);
   output << even;
   passed += checkTest("Other 4", output.str(), string("9"));
   output.str("");
   output.clear();
   intList.insert(15);
   intList.insert(23);
   intList.insert(32);
   intList.insert(99);
   odd = intList.everyOtherOdd();
   output << odd;
   passed += checkTest("Other 5", output.str(), string("4->15->32"));
   output.str("");
   output.clear();
   even = intList.everyOtherEven();
   output << even;
   passed += checkTest("Other 6", output.str(), string("9->23->99"));
   output.str("");
   output.clear();

   //Boundary cases
   intList.clear();
   intList.clear(); //clear an empty list
   passed += checkTest("Other 7", string("No errors"), string("No errors"));
   intList.remove(10);
   passed += checkTest("Other 8", string("No errors"), string("No errors"));
   odd = intList.everyOtherOdd();
   passed += checkTest("Other 9", odd.size(), 0);
   odd.insert(1);
   intList.remove(10);
   passed += checkTest("Other 10", string("No errors"), string("No errors"));
   even = odd.everyOtherEven();
   passed += checkTest("Other 11", even.size(), 0);
   try{
      intList.get(0);
      passed += checkTest("Other 12", string("No error"), string("out_of_range error"));
   }
   catch(out_of_range& e){
      passed += checkTest("Other 12", string("out_of_range error"), string("out_of_range error"));
   }
   try{
      intList.get(-1);
      passed += checkTest("Other 13", string("No error"), string("out_of_range error"));
   }
   catch(out_of_range& e){
      passed += checkTest("Other 13", string("out_of_range error"), string("out_of_range error"));
   }
   try{
      intList.getFirst();
      passed += checkTest("Other 14", string("No error"), string("out_of_range error"));
   }
   catch(out_of_range& e){
      passed += checkTest("Other 14", string("out_of_range error"), string("out_of_range error"));
   }
   try{
      intList.getLast();
      passed += checkTest("Other 15", string("No error"), string("out_of_range error"));
   }
   catch(out_of_range& e){
      passed += checkTest("Other 15", string("out_of_range error"), string("out_of_range error"));
   }

   cout << "Passed " << passed << "/15 optional tests" << endl;
   cout << "Score: " << passed/15.0*20 << endl;
}

//This helps with testing, do not modify.
template<class elemType>
bool checkTest(string testName, elemType actual, elemType expected) {

	if (actual == expected) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " ** " << endl << "   Output was "<< actual << endl << "   Output should have been " << expected << endl;
		return false;
	}
}
