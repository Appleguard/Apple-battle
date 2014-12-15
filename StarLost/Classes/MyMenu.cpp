//
//  MyMenu.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//

#include <stdio.h>
#include"MyMenu.h"

MyMenu * MyMenu::create()
{
    MyMenu *pRet=new MyMenu();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    
    return NULL;
    
}
void MyMenu::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, false);
    
}
bool MyMenu::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    TouchBegan=pTouch->getLocation();
    move=false;
    return CCMenu::ccTouchBegan(pTouch, pEvent);
}
void MyMenu::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    int x=pTouch->getLocation().x-TouchBegan.x;
    if(abs(x)>3)
    {
        move=true;
        
    }
    
    CCMenu::ccTouchMoved(pTouch, pEvent);
}
void MyMenu::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!move)
    {
        CCMenu::ccTouchEnded(pTouch, pEvent);
    }
    else
    {
        m_eState=kCCMenuStateWaiting;
    }
    
}
void MyMenu::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}