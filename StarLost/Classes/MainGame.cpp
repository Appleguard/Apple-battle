//
//  MainGame.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-14.
//
//

#include "MainGame.h"
#include "Data.h"
CCScene * MainGame:: scene()
{
    CCScene *scene=CCScene::create();
    
    MainGame * layer=MainGame::create();
    
    scene->addChild(layer);
    
    return scene;
    
}
 bool MainGame:: init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    
    CCSprite *BgSp=CCSprite::create("BgGame4.png");
    
    BgSp->setPosition(ccp(Visible_Center.x, Visible_Center.y));
    addChild(BgSp);
    this->addNavigation();
    return true;
    
}

void MainGame:: addNavigation()
{
    
    CCScale9Sprite * pauseNomal=CCScale9Sprite::create("Pause.png");
    pauseNomal->setScale(0.5);
    CCScale9Sprite * pauseSelect=CCScale9Sprite::create("Pause2.png");
    pauseSelect->setScale(0.5);
    CCControlButton * pauseButton=CCControlButton::create(pauseNomal);
    pauseButton->setPreferredSize(CCSizeMake(60, 60));
    pauseButton->setBackgroundSpriteForState(pauseSelect, CCControlStateSelected);
    pauseButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainGame::pauseButtonFun), CCControlEventTouchUpInside);
    
    pauseButton->setPosition(ccp(Visible_Origin.x+Visible_Size.width-100, Visible_Origin.y+Visible_Size.height-15));
    addChild(pauseButton);
    
    
    
    
    
    CCScale9Sprite * menuNomal=CCScale9Sprite::create("menu.png");
    menuNomal->setScale(0.5);
    CCScale9Sprite * menuSelect=CCScale9Sprite::create("menu2.png");
    menuSelect->setScale(0.5);
    CCControlButton * menuButton=CCControlButton::create(menuNomal);
    menuButton->setPreferredSize(CCSizeMake(60, 60));
    menuButton->setBackgroundSpriteForState(menuSelect, CCControlStateSelected);
    menuButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainGame::menuButtonFun), CCControlEventTouchUpInside);
    
    menuButton->setPosition(ccp(Visible_Origin.x+Visible_Size.width-50, Visible_Origin.y+Visible_Size.height-15));
    addChild(menuButton);
    
    

    
    CCScale9Sprite * speedNomal=CCScale9Sprite::create("speed1.png");
    speedNomal->setScale(0.5);
    CCScale9Sprite * speedSelect=CCScale9Sprite::create("speed2.png");
    speedSelect->setScale(0.5);
    CCControlButton * speedButton=CCControlButton::create(speedNomal);
    speedButton->setPreferredSize(CCSizeMake(110, 60));
    speedButton->setBackgroundSpriteForState(speedSelect, CCControlStateSelected);
    speedButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainGame::speedButtonFun), CCControlEventTouchUpInside);
    
    speedButton->setPosition(ccp(Visible_Origin.x+Visible_Size.width-150, Visible_Origin.y+Visible_Size.height-15));
    addChild(speedButton);
    
    
}
void MainGame::pauseButtonFun()
{
    CCLog("暂停按钮");
}

 void MainGame:: menuButtonFun()
{
    CCLog("菜单栏");
    
}

void MainGame:: speedButtonFun()
{
    CCLog("加速");
}
