#ifndef _TMOTION_H_
#define _TMOTION_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include "../../Database.h"
//#include "StrategyStatus.h"
//#include "StrategyModule.h"

namespace SKS_VC2013
{
class TMotion //: public StrategyModule
{
private:
    //static Motion* m_UniqueInstance;

    const double mAngle1Sin;
    const double mAngle2Sin;
    const double mAngle3Sin;

    const double mAngle1Cos;
    const double mAngle2Cos;
    const double mAngle3Cos;
public:
//     static Motion* GetInstance() {
//         return m_UniqueInstance;
//     }

    TMotion();
    ~TMotion();

    void Motion_Initialize();
    void Motion_Main();
};
}

#endif