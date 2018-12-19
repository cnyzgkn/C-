// stdMinMax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include "iostream"


const double DOUBLE_EPS = 0.000001;
const double LENGTH_EPS = 1E-2;

enum ValueRelationship
{
    //! 大于
    vrGreaterThan = 1,
    //! 等于
    vrEqual = 0,
    //! 小于
    vrLessThan = -1
};

inline ValueRelationship CompareValue(double dVal1, double dVal2, double dEpsilon)
{
    if (dEpsilon == 0.0)
    {
        dEpsilon = dVal1 * DOUBLE_EPS;
        if (dEpsilon < 0.0)
        {
            dEpsilon = -dEpsilon;
        }
        if (dEpsilon < DOUBLE_EPS)
        {
            dEpsilon = DOUBLE_EPS;
        }
    }

    return dVal1 > dVal2
        ? (dVal1 - dVal2 <= dEpsilon ? vrEqual : vrGreaterThan)
        : (dVal2 - dVal1 <= dEpsilon ? vrEqual : vrLessThan);
}

int main()
{
    double alignPoint = 0;
    double startPt = 10145.067439;
    double endPt = 10945.067439;
    
    if (CompareValue(startPt, 10395.067439, LENGTH_EPS) == vrLessThan && CompareValue(endPt, 10395.067439, LENGTH_EPS) == vrLessThan)
    {
        alignPoint = std::max(startPt, endPt);
    }
    else if (CompareValue(startPt, 0.000000, LENGTH_EPS) == vrGreaterThan && CompareValue(endPt, 0.000000, LENGTH_EPS) == vrGreaterThan)
    {
        alignPoint = std::min(startPt, endPt);
    }
    else
    {
        return false;
    }

    std::cout << alignPoint << std::endl;

    return 0;
}

