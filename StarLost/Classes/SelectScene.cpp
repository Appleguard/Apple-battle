//
//  SelectScene.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//

#include <stdio.h>
#include "SelectScene.h"
#include "StartScnene.h"
#include "Data.h"
#include "SelectGame.h"

CCScene* SelectScene::scene()
{
    
    CCScene *scene = CCScene::create();
    
    SelectScene *layer = SelectScene::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}


bool SelectScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
     CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("themescene1-hd.plist");
    
    
    CCSprite * Bgsp=CCSprite::create("selectBg.png");
    Bgsp->setPosition(ccp(Visible_Center.x, Visible_Center.y));
    addChild(Bgsp);
    CCMenuItemImage *item=CCMenuItemImage::create("home1.png", "home1.png");
   
    item->setScale(0.1);
    item->setOpacity(200);
    item->setTarget(this, menu_selector(SelectScene::goBack));
    CCMenu *menuitem=CCMenu::create(item,NULL);
    menuitem->setPosition(ccp(Visible_Origin.x+20, Visible_Origin.y+Visible_Size.height-20));
    addChild(menuitem);
    
    this->addleftButton();
    
    this->addrightButton();
    
    buttonright->setEnabled(false);
    buttonright->setVisible(false);
    this->docparse();
    
    
    this->Systemeffect();
    this->scheduleUpdate();
    
    return true;
    
    


}

void SelectScene:: goBack()
{
    CCLog("返回上一个界面");
    CCDirector::sharedDirector()->replaceScene(StartScnene::scene());
}
void SelectScene::update(float fDelta)
{
    offSet=scrollView->getContentOffset().x;
    if(offSet>-230)
    {
        buttonleft->setEnabled(true);
        buttonleft->setVisible(true);
        buttonright->setVisible(false);
        buttonright->setEnabled(false);
        
    }
    else if (offSet<-1000)
    {
        buttonright->setEnabled(true);
        buttonright->setVisible(true);
        buttonleft->setVisible(false);
        buttonleft->setEnabled(false);
        
    }
   
    else if (offSet<-100&&offSet>-1222)
    {
        buttonleft->setEnabled(true);
        buttonleft->setVisible(true);
        buttonright->setEnabled(true);
        buttonright->setVisible(true);
    }
}

void SelectScene::addleftButton()
{
    
    CCScale9Sprite * nomalleft=CCScale9Sprite::createWithSpriteFrameName("theme_pointleft_normal.png");
    nomalleft->setScale(0.4);
      CCScale9Sprite * selectleft=CCScale9Sprite::createWithSpriteFrameName("theme_pointleft_pressed.png");
    selectleft->setScale(0.4);
    buttonleft=CCControlButton::create(nomalleft);
    
    buttonleft->setPreferredSize(CCSizeMake(100, 100));
    buttonleft->setBackgroundSpriteForState(selectleft, CCControlStateSelected);
    buttonleft->addTargetWithActionForControlEvents(this, cccontrol_selector(SelectScene::leftButonfunc), CCControlEventTouchUpInside);
    buttonleft->setPosition(ccp(Visible_Origin.x+50, Visible_Center.y));
    buttonleft->setTouchPriority(-130);
    addChild(buttonleft);
    
    
}

void SelectScene::leftButonfunc()
{
    CCLog("左边的按钮");
    float ajustX=0.0,duration;
    offSet=scrollView->getContentOffset().x;
    ajustX=offSet-374;
   
    
    duration=64/500.0;
    scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
    
    
}

void SelectScene::addrightButton()
{
    
    CCScale9Sprite * nomalright=CCScale9Sprite::createWithSpriteFrameName("theme_pointright_normal.png");
    nomalright->setScale(0.4);
    CCScale9Sprite * selectright=CCScale9Sprite::createWithSpriteFrameName("theme_pointright_pressed.png");
    selectright->setScale(0.4);
     buttonright=CCControlButton::create(nomalright);
    
    buttonright->setPreferredSize(CCSizeMake(100, 100));
    buttonright->setBackgroundSpriteForState(selectright, CCControlStateSelected);
    buttonright->addTargetWithActionForControlEvents(this, cccontrol_selector(SelectScene::rightButonfunc), CCControlEventTouchUpInside);
    buttonright->setPosition(ccp(Visible_Center.x+180, Visible_Center.y));
    buttonright->setTouchPriority(-130);
    addChild(buttonright);
    
}
void SelectScene::rightButonfunc()
{
    float ajustX=0.0,duration;
    offSet=scrollView->getContentOffset().x;
    ajustX=offSet+374;
    

    
    duration=64/500.0;
    scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
    
    
}





//解析
void SelectScene::docparse()
{
    ItemImageArray=CCArray::create();
    ItemImageArray->retain();
    xmlparse=new XmlParse();
    xmlparse->xmlParseScene();
    char selectImageNumber[50];
    
    menu=MyMenu::create();
     CCLog("%d",xmlparse->SceneArray->count());
    for (int i=0; i<xmlparse->SceneArray->count(); i++)
    {
        CCDictionary *dic=(CCDictionary *)xmlparse->SceneArray->objectAtIndex(i);
        //SceneNumber   SceneUnlock
        
        int lock=((CCString *)dic->valueForKey("SceneUnlock"))->intValue();
        CCLog("%d",xmlparse->SceneArray->count());
        CCLog("%d",lock);
        sprintf(selectImageNumber, "Scene_0%d.png",i+1);
        
        ItemImage=CCMenuItemImage::create(selectImageNumber, selectImageNumber);
        ItemImage->setTarget(this, menu_selector(SelectScene::selectModle));
        
        ItemImage->setScale(0.7);
        
        CCMenuItemImage * lockimage;
        if (lock==0)
        {
            ItemImage->setEnabled(true);
        }
        else
        {
            lockimage=CCMenuItemImage::create("levelLocked.png", "levelLocked.png");
            ItemImage->cocos2d::CCMenuItem::setEnabled(false);
            lockimage->setAnchorPoint(CCPointZero);
            lockimage->setScale(1.5);
            lockimage->setPosition(ccp(120, 10));
            ItemImage->addChild(lockimage);
        }
        
        menu->addChild(ItemImage);
        ItemImageArray->addObject(ItemImage);
        
        
        
    }
    
    
  
    
    
    menu->alignItemsHorizontally();
    menu->alignItemsHorizontallyWithPadding(150);
    menu->setPosition(ccp(1800/2, Visible_Center.y));

    CCLayer *menulayer=CCLayer::create();
    menulayer->setContentSize(CCSizeMake(1800, ItemImage->getContentSize().height));
    menulayer->setPositionX(-100);
  
    menulayer->addChild(menu);
    
    scrollView=CCScrollView::create();
    scrollView->setBounceable(false);
    scrollView->setViewSize(CCSizeMake(480, 304));
    scrollView->setContainer(menulayer);
    scrollView->setDirection(kCCScrollViewDirectionHorizontal);
    addChild(scrollView);
    
    
    
    
    
    
}

void SelectScene::selectModle(CCMenuItemImage * itemImage1)
{
    CCLog("写入缓存，或是搞个单例来存数数据,然后跳转选择关卡界面");
    //暂且先是先场景的搭建，单例的数组存储等小组在一块进行分工把
    int index=ItemImageArray->indexOfObject(itemImage1);
    CCDictionary *dic=(CCDictionary *)xmlparse->SceneArray->objectAtIndex(index);
    
    CCUserDefault * defauler=CCUserDefault::sharedUserDefault();
    for (int i=0; i<xmlparse->SceneArray->count(); i++)
    {
        
        /*
         "SceneName"
         "SceneNumber"
         "SceneChapter"
         "SceneUnlock"*/
        if (i==index)
        {
            defauler->setStringForKey("sName",((CCString *) dic->valueForKey("SceneName"))->getCString());
            defauler->setIntegerForKey("sNumber", ((CCString *)dic->valueForKey("SceneNumber"))->intValue());
            defauler->setIntegerForKey("sChapter", ((CCString *)dic->valueForKey("SceneChapter"))->intValue());
            defauler->setIntegerForKey("sUnlock", ((CCString *)dic->valueForKey("SceneUnlock"))->intValue());
            
        }
    }
    
    CCDirector::sharedDirector()->replaceScene(SelectGame::scene());
    
    
    
}
void SelectScene:: Systemeffect()
{
    
    CCParticleSnow* sy=CCParticleSnow::create();
    //设置单个粒子的纹理
    sy->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("hua.png")  ,CCRectMake(0,0,250,250));
    sy->setBlendAdditive(true);//这个调用必不可少
    sy->setPosition(ccp(200,320));//设置位置
    addChild(sy);//添加粒子效果
    sy->setAutoRemoveOnFinish(true);//播放完之后自动移除
    
}

//滚动视图的偏移设置
void SelectScene::ajustContentOffSet()
{
    CCLog("设置偏移量");
    offSet=scrollView->getContentOffset().x;//总偏移量
    int x=((int)offSet+100)%374;
    CCLog("x=%d",x);
       float ajustX=0.0,duration;
    CCLog("offSet=%f",offSet);
    
    if (offSet>-100)
    {
       

        ajustX=-100;
        
        duration=64/500.0;
        scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
    }

    
    
    
    
    if (offSet<=-1222)
    {
       
        ajustX=-1222;
        duration=64/500.0;
        scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
    }
    
    if (offSet<-100&&offSet>-1222)
    {
       
        if(x<=-150)
        {
            ajustX=offSet-155;
            duration=64/500.0;
            scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
        }
        else
        {
            ajustX=offSet-x;
            duration=64/500.0;
            scrollView->setContentOffsetInDuration(ccp(ajustX, 0), duration);
            
        }
        
        
    }
    
 
    
    
    
   
    
}
//触摸事件



bool SelectScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("TouchBegan:(%f,%f)",pTouch->getLocation().x,pTouch->getLocation().y);
    return true;
}
void SelectScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
//     CCLog("TouchMoved");
}
void SelectScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("TouchEnded:(%f,%f)",pTouch->getLocation().x,pTouch->getLocation().y);
    this->ajustContentOffSet();
}
void SelectScene::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

void SelectScene::onEnter()
{
    CCLayer::onEnter();
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, false);
    
}
void SelectScene::onExit()
{
    
    this->unscheduleAllSelectors();
    CCLayer::onExit();
    
    
    
}




