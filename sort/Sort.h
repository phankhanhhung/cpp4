
#pragma once    // include guard to protect it from being included 
                //more than once then it will be skipped by the compiler in subsequent inclusions

                //Try to remove the #pragma once and compile the code to see what happens


class ISort
{
public:
    virtual void doSort() = 0;      // pure virtual function (set to 0)
    virtual ~ISort() {}
};

