#include "MemberDO.h"
#include <iostream>
#include <fstream>

using namespace std;

MemberDO::MemberDO()
{
   key = 0;
   lastName = "";
   firstInit = '\0';
   dues = 0;
}


MemberDO::MemberDO(int k, string ln, char fi, double d)
{
   key = k;
   lastName = ln;
   firstInit = fi;
   dues = d;
}

int MemberDO::getKey() const
{
return key;
}

void MemberDO::setKey(int k)
{
   key = k;
}

string MemberDO::getLastName() const
{
return lastName;
}

void MemberDO::setLastName(string ln)
{
   lastName = ln;
}

char MemberDO::getFirstInitial() const
{
return firstInit;
}

void MemberDO::setFirstInitial(char fi)
{
   firstInit = fi;
}

double MemberDO::getDues() const
{
return dues;
}

void MemberDO::setDues(double d)
{
   dues = d;
}
