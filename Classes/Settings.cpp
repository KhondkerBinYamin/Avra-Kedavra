#include "HelloWorldScene.h"
#include"GameScene.h"
#include "SimpleAudioEngine.h"
#include "FightScene.h"
#include "Settings.h"
USING_NS_CC;
Scene* SettingsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingsScene::create();
	scene->addChild(layer);
	return scene;
}


bool SettingsScene::init()
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




	// menu creating
	auto menu_item_1 = MenuItemFont::create("Resume", CC_CALLBACK_1(SettingsScene::Resume, this));
	auto menu_item_2 = MenuItemFont::create("Reset", CC_CALLBACK_1(SettingsScene::Reset, this));
	auto menu_item_3= MenuItemFont::create("Go Back To Menu", CC_CALLBACK_1(SettingsScene::GoBack, this));
	

	menu_item_1->setPosition(Point(500, 300));
	menu_item_2->setPosition(Point(500, 400));
	menu_item_3->setPosition(Point(500, 500));
	

	menu_item_1->setScale(0.8);
	menu_item_2->setScale(0.8);
	menu_item_3->setScale(0.8);
   
	
	
        auto *menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
		menu->setPosition(Point(0, 0));
		this->addChild(menu);
	

	//soundplaying
		/*
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	*/

   
	return true;

}
void SettingsScene::Reset(cocos2d::Ref *pSender)
{
	//making scores zero

	int p = 0;// ekhane point 0 korbo
	fp = fopen("points.txt", "w");
	fprintf(fp, "%d", p);
	fclose(fp);
	
   // making healthbars full

	float harryhealth = 100.000000;
	hp = fopen("hp.txt", "w");
	fprintf(hp, "%f", harryhealth);
	fclose(hp);
	//
	float enemyhealth = 100.00000000;
	hp1 = fopen("hp1.txt", "w");
	fprintf(hp1, "%f", harryhealth);
	fclose(hp1);



	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);

}

void SettingsScene::GoBack(cocos2d::Ref *pSender)
{
	auto scene = GraphicsScene::createScene();
	Director::getInstance()->pushScene(scene);
}


void SettingsScene::Resume(cocos2d::Ref *pSender)
{

	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);
	
}


void SettingsScene::MenuCloseCallback(Ref* pSender)
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
