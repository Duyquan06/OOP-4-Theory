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

        unsigned int get_Abs_Sec();
        void set_Abs_Sec( unsigned int );

        int compare( const Time &);
        unsigned int dis( const Time &);
        Time add_Sec( unsigned int );

        bool operator >  ( const Time & );
        bool operator <  ( const Time & );
        bool operator == ( const Time & );
        bool operator >= ( const Time & );
        bool operator <= ( const Time & );
        bool operator != ( const Time & );

        Time& operator + ( unsigned int );
        Time& operator ++ ();
        Time operator ++ ( int );

       friend std::ostream& operator << ( std::ostream &out, const Time & );
       friend std::istream& operator >> ( std::istream &in, Time & );

};