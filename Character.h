#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

class Character {
public:
    struct birthDate{
        int year;
        int month;
        int day;
        birthDate() {
            day = 0;
            month = 0;
            year = 0;
        }
        birthDate(const std::string& str)
        {
            int dot = str.find('.');
            int secondDot = str.substr(dot+1).find('.');
            day = std::stoi(str.substr(0,dot));
            month = std::stoi(str.substr(dot+1,secondDot));
            year = std::stoi(str.substr(dot+secondDot+2));
        }
        friend std::ostream& operator<< (std::ostream& os, const birthDate b)
        {
            return os << b.day << "." << b.month << "." << b.year;
        }
    };

    Character(std::string name, std::string strDate , int height, int weight)
    {
        m_name = name;
        m_birthDate = birthDate(strDate);
        m_height = height;
        m_weight = weight;
    }

private:

    std::string m_name;
    birthDate m_birthDate;
    int m_height;
    int m_weight;

    friend bool operator<(const Character& a, const Character& b)
    {
        if(a.m_name != b.m_name)
            return a.m_name < b.m_name;
        if( a.m_birthDate.year != b.m_birthDate.year)
            return a.m_birthDate.year < b.m_birthDate.year;
        if( a.m_birthDate.month != b.m_birthDate.month)
            return a.m_birthDate.month < b.m_birthDate.month;
        if( a.m_birthDate.month != b.m_birthDate.month)
            return a.m_birthDate.month < b.m_birthDate.month;
        if( a.m_birthDate.day != b.m_birthDate.day)
            return a.m_birthDate.day < b.m_birthDate.day;
        if(a.m_height != b.m_height)
            return a.m_height < b.m_height;
        return a.m_weight < b.m_weight;
    }
    friend std::ostream& operator<< (std::ostream& os, const Character& c)
    {
        return os << c.m_name << " " << c.m_birthDate << " " << c.m_height << " " << c.m_weight;
    }
};
#endif //CHARACTER_H
