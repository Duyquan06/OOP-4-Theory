#include"Time.h"
#include<ctime>

Time :: Time()
{
    const std::time_t now = std::time(nullptr) ; // get the current time point

    // convert it to (local) calendar time
    const std::tm calendar_time = *std::localtime( std::addressof(now) ) ;

    m_h = calendar_time.tm_hour;
    m_mi = calendar_time.tm_min;
    m_sec = calendar_time.tm_sec;
}

Time :: Time( int h, int min, int sec )
{
    m_h = h;
    m_mi = min;
    m_sec = sec;
}


