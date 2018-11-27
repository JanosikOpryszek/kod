//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ticks.hpp>
/// @ingroup     <rte>
/// @brief       <counting time sleep using cpu ticks>


#ifndef TICKS_HPP
#define TICKS_HPP

#include <iostream>
#include <time.h>
#include<stdint.h>

namespace rte
{

    class Ticks
    {
        public:
        Ticks(uint16_t a_ratio)        //proper ratio for PI = 1000
        {
            m_u16Time=0;
            m_u16Ratio=a_ratio;
        }

        void ticks(uint16_t a_milisec)   // INLINE definition (for time efficiency)
        {
            m_u16Time=0;
            m_u16Times=static_cast<uint16_t>(clock());  //START TICK
            while(m_u16Time<(a_milisec*m_u16Ratio))
            {

                m_u16Timed=static_cast<uint16_t>(clock());
                m_u16Time=m_u16Timed-m_u16Times;
            }
        }

        private:
        uint16_t m_u16Time;
        uint16_t m_u16Times;
        uint16_t m_u16Timed;
        uint16_t m_u16Ratio;

    };

}  //namespace
#endif //TICKS_HPP
