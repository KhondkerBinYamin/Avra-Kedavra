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
#include "FightScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//void spellmaar(Sprite* mysprite)
//{
//	Vec2 contentsize = mysprite->getContentSize();
//	Vector<SpriteFrame*> animFrames;
//	animFrames.reserve(3);
//	animFrames.pushBack(SpriteFrame::create("HarryPotter.png", Rect(0, 0, contentsize.x, contentsize.y)));
//	animFrames.pushBack(SpriteFrame::create("HarryPotter1.png", Rect(0, 0, contentsize.x, contentsize.y)));
//	animFrames.pushBack(SpriteFrame::create("HarryPotter.png", Rect(0, 0, contentsize.x, contentsize.y)));
//	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
//	Animate* animate = Animate::create(animation);
//	mysprite->runAction(animate);
//
//}

//void maarEnemy(Sprite* mysprite)
//{
//	Vec2 contentsize = mysprite->getContentSize();
//	Vector<SpriteFrame*> animFrames;
//	animFrames.reserve(3);
//	animFrames.pushBack(SpriteFrame::create("Voldemort1.png", Rect(0, 0, contentsize.x, contentsize.y)));
//	animFrames.pushBack(SpriteFrame::create("Voldemort.png", Rect(0, 0, contentsize.x, contentsize.y)));
//	animFrames.pushBack(SpriteFrame::create("Voldemort1", Rect(0, 0, contentsize.x, contentsize.y)));
//	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
//	Animate* animate = Animate::create(animation);
//	mysprite->runAction(animate);
//
//}

Scene* FightScene::createScene()
{
    return FightScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool FightScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	Size visiblesize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleSize();
    
	enemy.character = Sprite::create("Voldemort1.png");
	enemy.character->setPosition(Point(200, visiblesize.height - 20));
	this->addChild(enemy.character);
	harry.health = fopen("hp.txt", "r");
	fscanf(harry.health, " %f ", &harry.healthlength);
	enemy.health = fopen("hp1.txt", "r");
	fscanf(enemy.health, " %f ", &enemy.healthlength);
	
	auto delay = DelayTime::create(2);

	auto progress = ProgressTimer::create(Sprite::create("hp.png"));
	auto progress1 = ProgressTimer::create(Sprite::create("hp.png"));

	if (progress1 != NULL)
	{
		progress1->setType(ProgressTimer::Type::BAR);
		progress1->setMidpoint(Vec2(0, 0));
		progress1->setBarChangeRate(Vec2(1, 0));
		progress1->setPosition(Vec2(220, visiblesize.height - 20));
		progress1->setPercentage(enemy.healthlength);

		this->addChild(progress1, 1);
	}
	
	if (progress != NULL)
	{
		progress->setType(ProgressTimer::Type::BAR);
		progress->setMidpoint(Vec2(0, 0));
		progress->setBarChangeRate(Vec2(1, 0));
		progress->setPosition(Vec2(200,50));
		progress->setPercentage(harry.healthlength);
		
		this->addChild(progress, 1);

		/*
		//This error.//
		auto flip = FlipX::create(true);
		progress->runAction(flip);
		*/
    
		auto *progressTo = ProgressTo::create(1, harry.healthlength - 20);
		
		auto seq = Sequence::create(delay, progressTo, NULL);
		progress->runAction(seq);
	}

		/*
		//This error.//
		auto flip = FlipX::create(true);
		progress->runAction(flip);
		*/

		
	
	
	
	

	

	
	harry.character = Sprite::create("HarryPotter.png");
	harry.character->setPosition(Point(200, 65));
	
	

	this->addChild(harry.character);

	/*Vec2 contentsize = enemy.character->getContentSize();
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(3);
	animFrames.pushBack(SpriteFrame::create("Voldemort1.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("Voldemort.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("Voldemort1", Rect(0, 0, contentsize.x, contentsize.y)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	Animate* animate = Animate::create(animation);
	enemy.character->runAction(animate);*/
	

	/*if (flag == 0)
	{*/
	//	Rect rect1 = harry.character->getBoundingBox();
	//	Rect rect2 = Espell->getBoundingBox();
	//	if (rect1.intersectsRect(rect2))
	//	{
	//		this->removeChild(Espell);
	//	}
	/*this->schedule(schedule_selector(FightScene::CheckSpell), 1);
	}*/
	fclose(harry.health);
	float a = harry.healthlength-10;
	harry.health = fopen("hp.txt", "w");
	fprintf(harry.health, "%f", a);

	auto spell = Sprite::create("spell2.png");
	spell->setPosition(Point(200, visiblesize.height - 20));
	this->addChild(spell);

	auto move = MoveTo::create(2, Point(200,65));
	auto scale = ScaleTo::create(1, 0.0);
	auto seq1 = Sequence::create(move, scale, NULL);
	spell->runAction(seq1);
	
	auto fadeout = FadeOut::create(0.1);
	auto fadein = FadeIn::create(0.1);
	auto seq3 = Sequence::create(delay, fadeout, fadein, fadeout, fadein, fadeout, fadein, NULL);
	harry.character->runAction(seq3);




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
//}

//void FightScene::CheckSpell(float dt)
//{
//	Rect rect1 = harry.character->getBoundingBox();
//	Rect rect2 = Espell->getBoundingBox();
//	if (rect1.intersectsRect(rect2))
//	{
//		this->removeChild(Espell);
//		flag = 1;
//	}
//
//}



void FightScene::menuCloseCallback(Ref* pSender)
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
