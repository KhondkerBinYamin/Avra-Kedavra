#include "HelloWorldScene.h"
#include"GameScene.h"
#include "SimpleAudioEngine.h"
#include "FightScene.h"
#include "Settings.h"
#include "Instruction.h"
#include "CrossScene.h"

USING_NS_CC;
Scene* GraphicsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GraphicsScene::create();
	scene->addChild(layer);
	return scene;
}


bool GraphicsScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visiblesize = Director::getInstance()->getVisibleSize();
	auto sprite = Sprite::create("menubackground.png");
	sprite->setPosition(0,0);
	sprite->setAnchorPoint(Vec2(0,0));
	this->addChild(sprite, 0);


	// making the file input zero;
	int p = 0;// ekhane point 0 korbo
	fp = fopen("points.txt", "w");
	fprintf(fp, "%d", p);
	fclose(fp);
	//
	
	float harryhealth = 100.000000;
	hp = fopen("hp.txt", "w");
	fprintf(hp,  "%f", harryhealth);
	fclose(hp);

	//


	float enemyhealth = 100.00000000;
	hp1 = fopen("hp1.txt", "w");
	fprintf(hp1, "%f", harryhealth);
	fclose(hp1);


	


	// menu creating

	auto menu_item_1 = MenuItemFont::create("Settings", CC_CALLBACK_1(GraphicsScene::Settings, this));
	auto menu_item_2 = MenuItemFont::create("Instruction", CC_CALLBACK_1(GraphicsScene::Instruction, this));
	auto menu_item_3 = MenuItemFont::create("Play", CC_CALLBACK_1(GraphicsScene::Play, this));



	menu_item_1->setPosition(Point(500, 300));
	menu_item_2->setPosition(Point(500, 400));
	menu_item_3->setPosition(Point(500, 500));

	menu_item_1->setScale(0.8);
	menu_item_2->setScale(0.8);
	menu_item_3->setScale(0.8);




	auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
	menu->setPosition(Point(0, 0));
	this->addChild(menu);
	int var;
	sp = fopen("soundfile.txt", "r");
	fscanf(sp, "%d", &var);
	fclose(sp);
	/*
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	*/
   
	return true;

}
void GraphicsScene::Play(cocos2d::Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void GraphicsScene::Settings(cocos2d::Ref *pSender)
{
	auto scene = SettingsScene::createScene();
	Director::getInstance()->pushScene(scene);
	
}
void GraphicsScene::Instruction(cocos2d::Ref *pSender)
{
	auto scene = instructionScene::createScene();
	Director::getInstance()->pushScene(scene);

}


void GraphicsScene::MenuCloseCallback(Ref* pSender)
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
