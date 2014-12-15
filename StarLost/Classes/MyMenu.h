//
//  MyMenu.h
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//
#ifndef StarLost_MyMenu_H
#define StarLost_MyMenu_H
#include"cocos2d.h"
USING_NS_CC;
class MyMenu:public CCMenu
{
public:
    MyMenu()
    {
    }
    
    ~MyMenu()
    {
        
    }
    
    bool move;
    
    CCPoint TouchBegan;
    
    static MyMenu * create();
    
public:
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    

    
    
    
};



#endif
