//
//  SelectScene.h
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//

#ifndef __StarLost_SelectScene_H__
#define __StarLost_SelectScene_H__

#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
#include "XmlParse.h"
#include "MyMenu.h"
class StartScnene;
class SelectScene : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    
    void docparse();
    void ajustContentOffSet();
    void Systemeffect();
    void selectModle(CCMenuItemImage * itemImage1);
    void addleftButton();
    void addrightButton();
    void leftButonfunc();
    void rightButonfunc();
    void goBack();
    void update(float fDelta);
    CREATE_FUNC(SelectScene);
    
public:
    virtual void onEnter();
    virtual void onExit();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

    
    
private:
    XmlParse * xmlparse;
    MyMenu * menu;
    CCArray * ItemImageArray;
    CCMenuItemImage * ItemImage;
    CCScrollView *scrollView;
    float offSet;
    CCControlButton * buttonright;
    CCControlButton * buttonleft;
    
    
};


#endif