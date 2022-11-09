#include"Time.h"
#include<ctime>
#include<math.h>
#include<iomanip>

//constructors
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

Time :: Time ( unsigned int sec )
{
    m_h = sec / 3600;
    sec = sec % 3600;

    m_mi = sec / 60;
    m_sec = sec % 60; 
}

Time :: Time ( const Time &t)
{
    m_h = t.m_h;
    m_mi = t.m_mi;
    m_sec = t.m_sec;
}

//Getter & setter
int Time :: getHour()
{
    return m_h;
}

int Time :: getMin()
{
    return m_mi;
}

int Time :: getSec()
{
    return m_sec;
}

void Time :: setHour( int h )
{
    m_h = h;
}

void Time :: setMin( int min )
{
    m_mi = min;
}

void Time :: setSec( int sec )
{
    m_sec = sec;
}

unsigned int Time :: get_Abs_Sec()
{
    return m_h * 3600 + m_mi * 60 + m_sec;
}

void Time :: set_Abs_Sec( unsigned int sec )
{
    m_h = sec / 3600;
    sec = sec % 3600;

    m_mi = sec / 60;
    m_sec = sec % 60; 
}

int Time :: compare ( const Time&  t)
{
    //return 1 nếu Time trái > Time phải
    // return -1 nếu Time trái < Time phải
    //return 0 nếu 2 time bằng nhau.

    if( m_h != t.m_h )
        return m_h > t.m_h ? 1 : -1;

    if( m_mi != t.m_mi )
        return m_mi > t.m_mi ? 1 : -1;

    if( m_sec != t.m_sec )
        return m_sec > t.m_sec ? 1 : -1;
    
    return 0;
}

unsigned int Time :: dis( const Time& t )
{
    return abs( ( m_h * 3600 + m_mi * 60 + m_sec ) - ( t.m_h * 3600 + t.m_mi * 60 + t.m_sec ) );
}

Time Time :: add_Sec ( unsigned int sec )
{
    Time tmp( sec );
    int remain = 0;
    
    m_sec += tmp.m_sec; //Lấy tổng của 2 sec
    remain = m_sec / 60; // Tìm phần dư để sec trong khoảng [0 - 59]
    m_sec %= 60;    // tìm sec trong khoảng [0 - 59]

    m_mi += tmp.m_mi + remain; //Lấy tổng của 2 min và + remain ở sec
    remain = m_mi / 60; // Tìm phần dư để min trong [0 - 59]
    m_mi %= 60;     // tìm min trong [0 - 59]

    m_h += tmp.m_h + remain;    //lấy tổng của 2 hour và + remain ở min
    m_h %= 24;  // tìm hour trong [0 - 24]

    return (*this);
}

bool Time :: operator > ( const Time& t )
{
    return compare( t ) == 1;
}

bool Time :: operator < ( const Time& t )
{
    return compare( t ) == -1;
}

bool Time :: operator >= ( const Time& t )
{
    int cmp = compare ( t );
    return cmp == 1 || cmp == 0;
}

bool Time :: operator <= ( const Time& t )
{
    int cmp = compare ( t );
    return cmp == -1 || cmp == 0;
}

bool Time :: operator == ( const Time& t )
{
    return compare ( t ) == 0;
}

bool Time :: operator != ( const Time& t )
{
    return ! ( *this == t);
}

Time& Time :: operator + ( unsigned int sec )
{
    this->add_Sec( sec );
    return (*this);
}

Time& Time :: operator ++ ()
{
    this->add_Sec ( 1 );
    return (*this);
}

Time Time :: operator ++ ( int x )
{
    Time tmp = (*this);
    ++(*this);
    return tmp;
}

std::ostream& operator << (std::ostream &out, const Time& t)
{
    out << std::setw(2) << std::setfill('0') << t.m_h;
    out << ":";
    out << std::setw(2) << std::setfill('0') << t.m_mi;
    out << ":";
    out << std::setw(2) << std::setfill('0') << t.m_sec;

    return out;
}

std::istream& operator >> ( std::istream &in, Time& t)
{
    std::cout << "Enter hour: ";
    in >> t.m_h;
    std::cout << "Enter minute: ";
    in >> t.m_mi;
    std::cout << "Enter second: ";
    in >> t.m_sec;

    return in;
}