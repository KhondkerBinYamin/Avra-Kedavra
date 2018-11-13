#include "HelloWorldScene.h"
#include"GameScene.h"
#include "SimpleAudioEngine.h"
#include "FightScene.h"
#include "Settings.h"
#include "Gameover.h"
#include "Gamewin.h"

USING_NS_CC;

Scene* WinScene::createScene()
{
	auto scene = Scene::create();
	auto layer = WinScene::create();
	scene->addChild(layer);
	return scene;
}


bool WinScene::init()
{

	if (!Scene::init())
	{
		return false;
	}
	Size visiblesize = Director::getInstance()->getVisibleSize();
	auto sprite = Sprite::create("gamewin.png");
	sprite->setPosition(0,0);
	sprite->setAnchorPoint(Vec2(0,0));
	this->addChild(sprite, 0);


	//soundplaying
	/*
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	 */
	return true;

}

/*
cocos2d::Scene * OverScene::createScene()
{
	return nullptr;
}*/
