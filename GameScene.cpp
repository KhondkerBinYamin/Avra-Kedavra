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

#include "GameScene.h"
#include"HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "FightScene.h"

USING_NS_CC;

int flag=0,point = 10;
char spoint[100];

void boxkhul(Sprite* mysprite)
{
	Vec2 contentsize = mysprite->getContentSize();

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("chest1.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("chest2.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("chest3.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("chest4.png", Rect(0, 0, contentsize.x + 13, contentsize.y)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(animate);


}


Scene* GameScene::createScene()
{
	
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleSize();

	auto menuitem1 = MenuItemFont::create("Next", CC_CALLBACK_1(GameScene::Next, this));
	menuitem1->setPosition(Point(visiblesize.width / 2, visiblesize.height / 4 * 3));

	auto *menu = Menu::create(menuitem1,  NULL);
	menu->setPosition(Point(0, 0));

	this->addChild(menu);
 /*
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
	*/


	
	int i, j, k = 0;
	auto box1 = Sprite::create("boxclosered.png");
	boxes.push_back(box1);
	box1->setPosition(Point(400, 200));
	box1->setScale(0.5);
	auto box2 = Sprite::create("boxclosered.png");
	boxes.push_back(box2);
	box2->setPosition(Point(250, 200));
	box2->setScale(0.5);
	auto box3 = Sprite::create("boxclosered.png");
	boxes.push_back(box3);
	box3->setPosition(Point(100, 200));
	box3->setScale(0.5);
	
	for (i = 0; i < 3; i++)
	{
		auto boxplacing = boxes.at(i);
		this->addChild(boxplacing);
	}


	//int rand = cocos2d::RandomHelper::random_int(1, 3);
	for (i = 0; i < 3; i++)
	{
		auto khulbo_ami_dekhbe_desh = boxes.at(i);
		
		
		

			auto spriteBatch = SpriteBatchNode::create("potionbox.png", 200);
			auto spriteFrameCache = SpriteFrameCache::getInstance();
			spriteFrameCache->addSpriteFramesWithFile("potionbox.plist");
			this->addChild(spriteBatch);
			SpriteFrameCache* cache = SpriteFrameCache::getInstance();
			Vector<SpriteFrame*> moveAnimFrames(4); // parameter = number of frames you have for this anim
			moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			char str[100] = { 0 };
			sprintf(str, "potionbox%d.png", i+1);
			SpriteFrame* frame = cache->getSpriteFrameByName(str);
			moveAnimFrames.pushBack(frame);
			moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			Animation* moveAnimation = Animation::createWithSpriteFrames(moveAnimFrames, 7);
			moveAnimation->setLoops(-1);
			Animate* moveAnimate = Animate::create(moveAnimation);
			moveAnimate->retain(); // retain so you can use it again
			khulbo_ami_dekhbe_desh->runAction(moveAnimate); // run the animation
			

	}
	

	/*__String *tempscore = __String::createWithFormat("%d", point);
	labelTouchInfo = Label::createWithSystemFont(tempscore->getCString(), "Arial", 30);
	labelTouchInfo->setPosition(Vec2(250, 100));
	this->addChild(labelTouchInfo);
	
	time = 5;
	__String *timecount = __String::createWithFormat("%d", time);
	timeremaining = Label::createWithSystemFont(timecount->getCString(), "Arial", 10);
	timeremaining->setPosition(Vec2(150, 150));
	this->addChild(timeremaining);
*/
	


	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	//this->schedule(schedule_selector(GameScene::TimeUpdate), 1);
	
	return true;

    
}

void GameScene::Next(Ref *pSender)
{
	auto scene = FightScene::createScene();
	Director::getInstance()->pushScene(scene);

}

/*
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
*/
bool GameScene::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 location = touch->getLocation();

	for (int i = 0; i < 3; i++)
	{
		Vec2 box1location = boxes.at(i)->getPosition();

		Vec2 contentsize1 = boxes.at(i)->getContentSize();
		
		if (location.x >= box1location.x - contentsize1.x / 4 && location.x <= box1location.x + contentsize1.x / 4 && location.y >= box1location.y - contentsize1.y / 4 && location.y <= box1location.y + contentsize1.y / 4)
		{
			auto khulbo_ami_dekhbe_desh = boxes.at(i);




			auto spriteBatch = SpriteBatchNode::create("potionbox.png", 200);
			auto spriteFrameCache = SpriteFrameCache::getInstance();
			spriteFrameCache->addSpriteFramesWithFile("potionbox.plist");
			this->addChild(spriteBatch);
			SpriteFrameCache* cache = SpriteFrameCache::getInstance();
			Vector<SpriteFrame*> moveAnimFrames(4); // parameter = number of frames you have for this anim
			moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			char str[100] = { 0 };
			sprintf(str, "potionbox%d.png", i + 1);
			SpriteFrame* frame = cache->getSpriteFrameByName(str);
			moveAnimFrames.pushBack(frame);
			moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			Animation* moveAnimation = Animation::createWithSpriteFrames(moveAnimFrames, 2);
			moveAnimation->setLoops(1);
			Animate* moveAnimate = Animate::create(moveAnimation);
			moveAnimate->retain(); // retain so you can use it again
			khulbo_ami_dekhbe_desh->runAction(moveAnimate); // run the animation

			
		}
	}

			/*point += 100;
			__String *tempscore = __String::createWithFormat("%d", point);

			labelTouchInfo->setString(tempscore->getCString());
			this->unschedule(schedule_selector(GameScene::TimeUpdate));*/
		
		/*
		else if (time == 4)
		{
			boxkhul(box1);


			point += 80;
			__String *tempscore = __String::createWithFormat("%d", point);

			labelTouchInfo->setString(tempscore->getCString());
			this->unschedule(schedule_selector(GameScene::TimeUpdate));
		}
		else
		{
			boxkhul(box1);


			point += 50;
			__String *tempscore = __String::createWithFormat("%d", point);

			labelTouchInfo->setString(tempscore->getCString());
			this->unschedule(schedule_selector(GameScene::TimeUpdate));
		}

	}
	else if (location.x >= 400 - contentsize2.x / 4 && location.x <= 400 + contentsize2.x/4 && location.y >= 200 - contentsize2.y / 4 && location.y <= 200 + contentsize2.y/4)
	{
		boxkhul(box2);
	}
	else
	{
		auto scene = FightScene::createScene();
		Director::getInstance()->pushScene(scene);
	}*/
	
	return true;
}
//void GameScene::TimeUpdate(float dt)
//{
//	if (time > 0)
//	{
//		time -= dt;
//		__String *timecount = __String::createWithFormat("%d", time);
//
//		timeremaining->setString(timecount->getCString());
//	}
//
//}




void GameScene::menuCloseCallback(Ref* pSender)
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
