//
//  SelectGame.h
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//

#ifndef StarLost_SelectGame_H
#define StarLost_SelectGame_H

#include"cocos2d.h"
#include "cocos-ext.h"
#include "XmlParse.h"
USING_NS_CC_EXT;
USING_NS_CC;
class SelectScene;
class SelectGame:CCLayer
{
public:
    static CCScene * scene();
    virtual bool init();
    void addButtonItem();
    void replaceScene();
    void GoBack();
    CREATE_FUNC(SelectGame);
    
private:
    XmlParse * xmlParser;
    CCMenuItemImage * itemImage;
    
};





#endif