//=============================================================================
// Project      <<CAA4>>
//
// Copyright <2018> GlobalLogic
//
//=============================================================================
/// @file        <ISwC.h>
/// @ingroup     <pub>
/// @brief       <interface for SwC>

#ifndef ISWC_H
#define ISWC_H

namespace pub
{
    class ISwC
    {
        public:
        virtual ~ISwC();
        //========================================
        /// @brief     <helper for runnin  work method in pthread in c++98>
        /// @param     [IN]  <void>
        /// @param     [OUT] <void>
        /// @return    <void>
        //========================================l
        static void* run (void *context)
        {
            return (static_cast<ISwC*>(context))->work();
        }

        private:
        //========================================
        /// @brief     <run main part of SwC, this method will be runned every 100ms>
        /// @param     [IN]  <void>
        /// @param     [OUT] <void>
        /// @return    <void>
        //========================================
        virtual void* work() = 0;
    };


} //namespace pub
#endif // ISWC_H
