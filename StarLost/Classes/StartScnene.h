//
//  StartScnene.h
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//

#ifndef __StarLost_StartScnene_H__
#define __StarLost_StartScnene_H__

#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
class StartScnene : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void addSprite();
    void  replaceScene();
    void  addMusicItem();
    
    CREATE_FUNC(StartScnene);
    
    
    


};


#endif