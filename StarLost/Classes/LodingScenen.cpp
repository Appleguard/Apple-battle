//
//  LodingScenen.cpp
//  StarLost
//
//  Created by Gmeng on 14-12-12.
//
//


#include "LodingScenen.h"
#include "StartScnene.h"
#include "Data.h"
USING_NS_CC;

CCScene* LodingScenen::scene()
{
    
    CCScene *scene = CCScene::create();
    
    LodingScenen *layer = LodingScenen::create();
    
    
    scene->addChild(layer);
    
    
    return scene;
}


bool LodingScenen::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    num=0;
    
    CCSprite * BgSP=CCSprite::create("BgCat.png");
    
   BgSP->setPosition(ccp(Visible_Center.x, Visible_Center.y));
    
    addChild(BgSP);
    
    //添加虫子的动画效果

    this->action();
    
    slider=CCControlSlider::create(CCSprite::create("slider_bar.png"), CCSprite::create("silder_progressBar.png"), sp);
    slider->setMaximumValue(100);
    //设置滑块的最小值
    slider->setMinimumValue(0);
    
    
    //设置slider的当前值
    slider->setValue(0);
   
    slider->setPosition(ccp(Visible_Center.x,Visible_Center.y-100));
    
    slider->setScale(0.6);
    slider->setTouchEnabled(false);
    addChild(slider);
    
    CCSprite * loadSp=CCSprite::create("loading_1_1.png");
    loadSp->setPosition(ccp(Visible_Center.x, Visible_Center.y-130));
    loadSp->setTag(10);
    loadSp->setScale(0.5);
    addChild(loadSp);
  
    
    this->scheduleUpdate();
    
    
    
    return true;
}

void LodingScenen::update(float fDelta)
{
    num=num+1;
    slider->setValue(num);
    if (slider->getValue()>=100)
    {
        CCSprite *sp1=(CCSprite *)this->getChildByTag(10);
        sp1->removeFromParent();
        sp1=CCSprite::create("loading_1_2.png");
       sp1->setPosition(ccp(Visible_Center.x, Visible_Center.y-130));
        sp1->setScale(0.5);
        addChild(sp1);
        this->unscheduleAllSelectors();
       
        
        
        this->runAction(CCSequence::create(CCDelayTime::create(0.5),CCCallFunc::create(this,callfunc_selector(LodingScenen::replaceScene))));
        CCLog("跳转界面");
//        this->replaceScene();
    }
    
}

void LodingScenen::replaceScene()
{
    
    CCDirector::sharedDirector()->replaceScene(StartScnene::scene());
    
}


void LodingScenen:: action()
{
   
    //我加了一个动画  对于缓存哪里还是挺重要的   精灵动起来基本上都是靠它
    //先加plist文件里面的图片添加到缓存里面
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("worm.plist");
    //创建一个精灵  是要让后这个精灵运行一个动画
   sp=CCSprite::createWithSpriteFrameName("1.png");
    //设置一下位置
//    sp->setAnchorPoint(ccp(0, 0));
    sp->setPosition(ccp(-100, 200));
    sp->setScale(0.5);

//    addChild(sp);
    //将plist文件的内容读取出来  放到一个数组里面
    CCDictionary *DIC=CCDictionary::createWithContentsOfFile("worm.plist");
    //在通过key值来读取frames里面的图片
    CCDictionary *frameDic=(CCDictionary *)DIC->objectForKey("frames");
    //这个数组就是装每一个精灵
    CCArray *array=CCArray::create();
    array->retain();
    
    for(int i=1;i<=frameDic->count();i++)
    {
        //让人物动起来
        char str[30];
        sprintf(str, "%d.png",i);
        
        CCSpriteFrame *Freme=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        if(Freme)
        {
            array->addObject(Freme);
        }
        
        CCAnimation *Animation=CCAnimation::createWithSpriteFrames(array,0.2f);
        CCAnimate *Animate=CCAnimate::create(Animation);
        CCRepeatForever *forever=CCRepeatForever::create(Animate);
        sp->runAction(forever);
        
        
    }
    
}
