//
//  LodingScenen.h
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//

#ifndef __StarLost_LodingScenen_H__
#define __StarLost_LodingScenen_H__

#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
class LodingScenen : public cocos2d::CCLayer
{
    public:
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();

    void  action();
    void update(float fDelta);
    
    void replaceScene();
    
    CREATE_FUNC(LodingScenen);
    
    
    
    
private:
    CCSprite * sp;
    CCControlSlider * slider;
    int num;
};


#endif