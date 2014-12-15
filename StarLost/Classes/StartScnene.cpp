//
//  StartScnene.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//

#include <stdio.h>
#include "StartScnene.h"
#include "SelectScene.h"
#include "Data.h"
CCScene* StartScnene::scene()
{
    
    CCScene *scene = CCScene::create();
    
    StartScnene *layer = StartScnene::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}


bool StartScnene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSprite * StartBg=CCSprite::create("bg3.png");
    StartBg->setPosition(ccp(Visible_Center.x, Visible_Center.y));
    addChild(StartBg);
    
    this->addSprite();
    
    return true;

}

//音乐按钮
void StartScnene::addMusicItem()
{
    
}


//开始按钮
void StartScnene::addSprite()
{
   
   CCScale9Sprite *spnomal=CCScale9Sprite::create("button.png");
     CCScale9Sprite *spselect=CCScale9Sprite::create("button.png");
    
    CCControlButton * button=CCControlButton::create(spnomal);
    
    button->setPreferredSize(CCSizeMake(170,68));
    button->setBackgroundSpriteForState(spselect, CCControlStateSelected);
    button->addTargetWithActionForControlEvents(this, cccontrol_selector(StartScnene::replaceScene), CCControlEventTouchUpInside);
    button->setPosition(ccp(Visible_Center.x, Visible_Center.y-100));
    addChild(button);
    
    
}

void StartScnene:: replaceScene()
{
    CCLog("跳转选择场景界面");
    
    CCDirector::sharedDirector()->replaceScene(SelectScene::scene());
}