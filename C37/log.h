/**************************************************
 * FileName: code.h
 * Usage: Declare Classes & Functions
 * Description: ...
 * Dependency: ...
 * Author: Lynn <lynn840429@gmail.com>
 * Version: ...
 **************************************************/
/*** Include Packages ***/
#ifndef _CODE_H
#define _CODE_H
#include <iostream>



/*** Function Declaration ***/



/*** Class Definition ***/
class Printable
{
	/***
	 * Class Info: 
	 ***/
    public:
        virtual std::string GetClassName() = 0;
};


class Entity: public Printable
{
	/***
	 * Class Info: 
	 ***/
    private:
        std::string m_Name;
        mutable int m_DubugCount = 0;
        int m_Score;
    
    protected:
        void Print() {}

    public:
        //virtual std::string GetName() { return "Entity"; }
        //std::string GetName() { return "Entity"; }
        std::string GetClassName() override { return "Entity"; }

        Entity(): m_Name("Unknown"), m_Score(0)
        {
            Print();
            //m_Name = "Unknown";
            std::cout << "Entity(): m_Name(Unknown)" << std::endl;
        }

        Entity(const std::string &name): m_Name(name)
        {
            //m_Name = name;
            std::cout << "Entity(const std::string &name)" << std::endl;
        }

        const std::string &GetName() const
        {
            m_DubugCount++;
            return m_Name;
        }
};


class Player: public Entity
{
	/***
	 * Class Info: 
	 ***/
    private:
        std::string m_Name;

    public:
        Player(const std::string &name): m_Name(name) {}

        std::string GetName() { return m_Name; }
        std::string GetClassName() override { return "Player"; }

        Player()
        {
            Print();
        }
};


class A: public Printable
{
    public:
        std::string GetClassName() /*override*/ { return "A"; }
};


void PrintName(Entity *en)
{
    std::cout << en->GetName() << std::endl;
}


void Print(Printable *obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

void PrintString(const std::string &string)
{
    std::cout << string << std::endl;
}



#endif