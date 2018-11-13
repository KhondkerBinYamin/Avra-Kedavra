#include "HelloWorldScene.h"
#include"GameScene.h"
#include "SimpleAudioEngine.h"
#include "FightScene.h"
#include "Settings.h"
#include  "Instruction.h"
USING_NS_CC;
Scene*  instructionScene::createScene()
{
	auto scene = Scene::create();
	auto layer = instructionScene::create();
	scene->addChild(layer);
	return scene;
}


bool instructionScene::init()
{

	 if (!Layer::init())
	 {
		return false;
	 }
	 Size visiblesize = Director::getInstance()->getVisibleSize();
	 auto sprite = Sprite::create("instruction.png");
	 sprite->setPosition(100,100);
	 sprite->setAnchorPoint(Vec2(0,0));
	 this->addChild(sprite, 0);
	 // menu creating
	   auto Instruction_holder = MenuItemFont::create("Back To Menu", CC_CALLBACK_1(instructionScene::BackToMenu, this));
	   Instruction_holder->setPosition(Point(200,150));
	   Instruction_holder->setScale(0.8);
		auto *menu = Menu::create(Instruction_holder, NULL);
		menu->setPosition(Point(0, 0));
		this->addChild(menu);
	

	  //soundplaying
		/*
	  CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
	  CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	  */
	  return true;

}


void instructionScene::BackToMenu(cocos2d::Ref *pSender)
{
	auto scene = GraphicsScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void instructionScene::MenuCloseCallback(Ref* pSender)
{
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WP8)||(CC_TARGET_PLATFORM==CC_PLATFORM_WINRT)
		MessageBox("You pressed the close button. Windows store apps do not implement a close button.", "Alert");
		return;
#endif 
		Director::getInstance()->end();
#if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
		exit(0);
#endif

}
