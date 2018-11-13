
#include "HelloWorldScene.h"
#include"GameScene.h"
#include "DeathScene.h"
#include "SimpleAudioEngine.h"
#include "Gameover.h"
#include "Gamewin.h"


USING_NS_CC;
Scene* DeathScene::createScene()
{
	return DeathScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool DeathScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	/*
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	*/

	//next button add
	auto menuitem1 = MenuItemFont::create("Next", CC_CALLBACK_1(DeathScene::Next, this));
	menuitem1->setPosition(Point(50, 700));
	auto *menu = Menu::create(menuitem1, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);

	Size visiblesize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleSize();

	enemy.character = Sprite::create("Voldemort1.png");
	enemy.character->setPosition(Point(visiblesize.width / 2, visiblesize.height - 100));
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
		progress1->setPosition(Vec2(220, visiblesize.height - 10));
		progress1->setPercentage(enemy.healthlength);

		this->addChild(progress1, 1);

		auto *progressTo = ProgressTo::create(1, enemy.healthlength - 20);

		auto seq = Sequence::create(delay, progressTo, NULL);
		progress1->runAction(seq);
	}

	if (progress != NULL)
	{
		progress->setType(ProgressTimer::Type::BAR);
		progress->setMidpoint(Vec2(0, 0));
		progress->setBarChangeRate(Vec2(1, 0));
		progress->setPosition(Vec2(200, 100));
		progress->setPercentage(harry.healthlength);

		this->addChild(progress, 1);
		
	}


	harry.character = Sprite::create("HarryPotter.png");
	harry.character->setPosition(Point(visiblesize.width / 2, 100));
	this->addChild(harry.character);


	fclose(harry.health);
	fclose(enemy.health);
    a = enemy.healthlength - 10;
	enemy.health = fopen("hp1.txt", "w");
	fprintf(enemy.health, "%f", a);
	fclose(enemy.health);

	auto spell = Sprite::create("spell2.png");
	spell->setPosition(Point(visiblesize.width / 2, 100));
	this->addChild(spell);

	auto move = MoveTo::create(2, Point(visiblesize.width / 2, visiblesize.height - 100));
	auto scale = ScaleTo::create(1, 0.0);
	auto seq1 = Sequence::create(move, scale, NULL);
	spell->runAction(seq1);

	auto fadeout = FadeOut::create(0.1);
	auto fadein = FadeIn::create(0.1);
	auto seq3 = Sequence::create(delay, fadeout, fadein, fadeout, fadein, fadeout, fadein, NULL);
	enemy.character->runAction(seq3);




	return true;


}
void DeathScene::Next(cocos2d::Ref *pSender)
{         
	    
	if (a >= 0)
	{
		auto scene = GameScene::createScene();
		Director::getInstance()->pushScene(scene);
	}
	// winning condition 

	else
	{
		auto scene = WinScene::createScene();
		Director::getInstance()->pushScene(scene);
	}

	
}
void DeathScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);

#endif


}
