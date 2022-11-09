#pragma once
#include<iostream>
class Time
{
    private:
        int m_h, m_mi, m_sec;
    
    public:
        Time();
        Time( int, int, int );
        Time( unsigned int );
        Time( const Time & );

        int getHour();
        int getMin();
        int getSec();

        void setHour( int );
        void setMin( int );
        void setSec( int );

        int get_Abs_Sec();
        void set_Abs_Sec();

        int compare( const Time &);
        Time dis( const Time &);
        void add_Sec( int );

        bool operator >  ( const Time & );
        bool operator <  ( const Time & );
        bool operator == ( const Time & );
        bool operator >= ( const Time & );
        bool operator <= ( const Time & );
        bool operator != ( const Time & );

        Time& operator + ( int );
        Time& operator ++ ();

       friend std::ostream& operator << ( std::ostream &out, const Time & );
       friend std::istream& operator >> ( std::istream &in, Time & );

};