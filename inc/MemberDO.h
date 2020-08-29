#ifndef MEMBERDO
#define MEMBERDO

#include "LinkedList.h"
#include <string>

class MemberDO
{
	private:
		int key;
		std::string lastName;
		char firstInit;
		double dues;
	public:
		MemberDO();
		MemberDO(int, std::string, char, double);

		int getKey() const;
		void setKey(int);
		std::string getLastName() const;
		void setLastName(std::string);
		char getFirstInitial() const;
		void setFirstInitial(char);
		double getDues() const;
		void setDues(double);


	bool operator<(const MemberDO &other)               //comparison operator for comparing MemberDO objects
    {
        if (this->getKey() < other.getKey())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const MemberDO& other)              //comparison operator for comparing MemberDO objects
    {
	    if (this->getKey() == other.getKey())
        {
	        return true;
        }
	    else
        {
	        return false;
        }

    }

};

#endif
