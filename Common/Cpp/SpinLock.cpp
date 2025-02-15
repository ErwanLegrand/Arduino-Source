/*  Spin Lock
 *
 *  From: https://github.com/PokemonAutomation/Arduino-Source
 *
 */

#include <emmintrin.h>
#if _WIN32
#include <intrin.h>
#endif

#include "SpinLock.h"

#include <iostream>
using std::cout;
using std::endl;

namespace PokemonAutomation{


void SpinLock::spin_acquire(){
    while (true){
        bool state = false;
        if (!m_locked.load(std::memory_order_acquire) && m_locked.compare_exchange_weak(state, true)){
            break;
        }
        _mm_pause();
    }
}

void SpinLock::spin_acquire(const char* label){
#if _WIN32
    uint64_t start = __rdtsc();
    while (true){
        bool state = false;
        if (!m_locked.load(std::memory_order_acquire) && m_locked.compare_exchange_weak(state, true)){
            break;
        }
        _mm_pause();

        if (__rdtsc() - start > 10000000000){
            cout << "Slow SpinLock: " << label << endl;
            start = __rdtsc();
        }
    }
#else
    spin_acquire();
#endif
}


}
