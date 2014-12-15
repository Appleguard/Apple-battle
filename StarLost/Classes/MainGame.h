//
//  MainGame.h
//  StarLost
//
//  Created by Gmeng on 14-12-14.
//
//

#include"cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;
class MainGame:CCLayer
{
public:
    static CCScene * scene();
    virtual bool init();
    void addNavigation();
    void pauseButtonFun();
    void menuButtonFun();
    void speedButtonFun();
    CREATE_FUNC(MainGame);
    

    
};
