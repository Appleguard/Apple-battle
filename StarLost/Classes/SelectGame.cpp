//
//  SelectGame.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-13.
//
//

#include <stdio.h>
#include "SelectGame.h"
#include "Data.h"
#include "MainGame.h"
#include "SelectScene.h"
CCScene * SelectGame::scene()
{
    CCScene *scene=CCScene::create();
    
    SelectGame * layer=SelectGame::create();
    
    
   scene->addChild(layer);
    
    return  scene;
    
    
    
    
}
bool SelectGame::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSprite * spBg=CCSprite::create("bgGame1.png");
    spBg->setPosition(ccp(Visible_Center.x, Visible_Center.y));
    addChild(spBg);
    this->addButtonItem();
    
    return true;
}

void SelectGame::GoBack()
{
    CCLog("返回");
    CCDirector::sharedDirector()->replaceScene(SelectScene::scene());
}

void SelectGame::addButtonItem()
{
    CCScale9Sprite * nomalsp=CCScale9Sprite::create("back.png");
    nomalsp->setScale(0.7);
    CCScale9Sprite * selectsp=CCScale9Sprite::create("back.png");
    selectsp->setScale(0.7);
    CCControlButton * button=CCControlButton::create(nomalsp);
    button->setPreferredSize(CCSizeMake(50, 50));
    button->setBackgroundSpriteForState(selectsp, CCControlStateSelected);
    button->addTargetWithActionForControlEvents(this, cccontrol_selector(SelectGame::GoBack), CCControlEventTouchUpInside);
    button->setPosition(ccp(20,Visible_Origin.x+Visible_Size.height-20));
    addChild(button);
    
    
    
    
    int sceneNumber= CCUserDefault::sharedUserDefault()->getIntegerForKey("sNumber");
    CCLog("%d",sceneNumber);
    xmlParser=new XmlParse();
    xmlParser->xmlParseChapter(sceneNumber);
    CCMenu * menu=CCMenu::create();

    for (int i=0; i<xmlParser->ChapterArray->count(); i++)
    {
        CCDictionary * dic=(CCDictionary *) xmlParser->ChapterArray->objectAtIndex(i);
        
        int  lock=((CCString *)dic->valueForKey("ChapterUnlock"))->intValue();
        int starNumber=((CCString *)dic->valueForKey("ChapterSatrNum"))->intValue();
        CCString * chapterNumber=((CCString *)dic->valueForKey("ChapterNumber"));
        CCLog("%d",lock);
        
        if (lock==0) {
            itemImage=CCMenuItemImage::create("apple.png", "apple.png");
            itemImage->setEnabled(true);
            
            CCLabelBMFont * font=CCLabelBMFont::create(chapterNumber->getCString(), "font-issue1343-hd.fnt");
            font->setPosition(ccp(50, 60));
            font->setOpacity(230);
            itemImage->addChild(font);
            
           char starNum[50];
            
            sprintf(starNum, "star%d.png",starNumber);
            
            CCMenuItemImage * starimage=CCMenuItemImage::create(starNum, starNum);
            
            starimage->setScale(0.5);
            starimage->setPosition(ccp(50, -20));
            itemImage->addChild(starimage);
            
      
            
            
            
            
          
        }
        else if (lock==1)
        {

            itemImage=CCMenuItemImage::create("lock_apple.png", "lock_apple.png");
            itemImage->setEnabled(false);

           

        }
        
        itemImage->setTarget(this, menu_selector(SelectGame::replaceScene));
        itemImage->setScale(0.5);
        menu->addChild(itemImage);
        
       
    }
    
    menu->alignItemsInColumns(3,3,NULL);

    menu->setPosition(ccp(Visible_Center.x, Visible_Center.y-20));
    
    addChild(menu);
    
    
    
}

void SelectGame:: replaceScene()
{
    CCLog("主游戏场景");
    CCDirector::sharedDirector()->replaceScene(MainGame::scene());
    
}
