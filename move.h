#pragma once
#include <iostream>

class Move
{
public:
    Move(){};
    Move(int x,int y) {m_x=x; m_y=y;}
    void set_x(int x) {m_x=x;}
    void set_y(int y) {m_y=y;}
    int get_x()const {return m_x;}
    int get_y()const {return m_y;}
    

private:
    int m_x;
    int m_y;

};

