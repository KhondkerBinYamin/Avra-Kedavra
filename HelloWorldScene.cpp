/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include"GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;



Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleSize();
 
	auto menuitem1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
	auto menuitem2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(HelloWorld::Highscores, this));
	auto menuitem3 = MenuItemFont::create("Settings", CC_CALLBACK_1(HelloWorld::Settings, this));
	menuitem1->setPosition(Point(visiblesize.width/2, visiblesize.height/4*3));
	menuitem2->setPosition(Point(visiblesize.width / 2, visiblesize.height / 4 * 2));
	menuitem3->setPosition(Point(visiblesize.width / 2, visiblesize.height / 4 * 1));
	menuitem1->setScale(0.25);
	menuitem2->setScale(0.25);
	menuitem3->setScale(0.25);
	auto *menu = Menu::create(menuitem1, menuitem2, menuitem3, NULL);
	menu->setPosition(Point(0, 0));
	
	
	
	this->addChild(menu);
	
	/*
    box1 = Sprite::create("chest1.png");
	box1->setScale(0.5);
	box1->setPosition(Point(200, 200));
	
    box2 = Sprite::create("chest1.png");
	box2->setScale(0.5);
	box2->setPosition(Point(400, 200));
    
    this->addChild(box1, 0);
	this->addChild(box2, 0);

    

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	*/
	
	return true;

    
}

void HelloWorld::Play(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);

}
void HelloWorld::Highscores(Ref *pSender)
{
	
}
void HelloWorld::Settings(Ref *pSender)
{
	
}

/*bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 location = touch->getLocation();
	Vec2 contentsize1 = box1->getContentSize();
	Vec2 contentsize2 = box2->getContentSize();
	if (location.x >= 200 - contentsize1.x / 2 && location.x <= 200 + contentsize1.x/2 && location.y >= 200 - contentsize1.y / 2 && location.y <= 200 + contentsize1.y/2)
	{
		boxkhul(box1);
	}
	else if (location.x >= 400 - contentsize2.x / 2 && location.x <= 400 + contentsize2.x/2 && location.y >= 200 - contentsize2.y / 2 && location.y <= 200 + contentsize2.y/2)
	{
		boxkhul(box2);
	}
	else
	{
		auto scene = HelloWorld::createScene();
		Director::getInstance()->pushScene(scene);
	}
	return true;
}

*/


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
