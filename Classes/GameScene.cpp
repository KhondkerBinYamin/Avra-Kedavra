#include "GameScene.h"
#include "HelloWorldScene.h"
#include "FightScene.h"
#include "DeathScene.h"
#include "CrossScene.h"
#include "SimpleAudioEngine.h"
#include  "Settings.h"

USING_NS_CC;

void boxkhul(Sprite* mysprite)
{
	Vec2 contentsize = mysprite->getContentSize();
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("boxopen.png", Rect(0, 0, contentsize.x+45, contentsize.y+50)));
	animFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, contentsize.x, contentsize.y)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 4.0f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(animate);
}

void fakabox(Sprite* mysprite)
{
	Vec2 contentsize = mysprite->getContentSize();
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, contentsize.x, contentsize.y)));
	animFrames.pushBack(SpriteFrame::create("boxopen.png", Rect(0, 0, contentsize.x + 45, contentsize.y + 50)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(animate);
}




Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}


bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	int var;
	sp = fopen("soundfile.txt", "r");
	fscanf(sp, "%d", &var);
	fclose(sp);
	/*
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Hedwigs_theme.mp3");
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Hedwigs_theme.mp3", true);
	*/

    //background
	auto sprite = Sprite::create("Gryff.png");
	sprite->setPosition(0,0);
	this->addChild(sprite, 0);
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(0, 0);
	// buttons 
	auto next = MenuItemFont::create("Next", CC_CALLBACK_1(GameScene::Next, this));
	auto back_korar_item = MenuItemFont::create("Back", CC_CALLBACK_1(GameScene::Back, this));
	next->setPosition(Point(50,700));
	back_korar_item->setPosition(Point(150, 700));
	auto *menu = Menu::create(next,back_korar_item, NULL);
	menu->setPosition(Point(0, 0));
	sprite->addChild(menu);

	auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "Your Text");
	//box boshano
	int i, j, k = 0;

	auto box1 = Sprite::create("boxclosered.png");
    boxes.push_back(box1);   
	box1->setPosition(Point(500, 200));
	auto box2 = Sprite::create("boxclosered.png");
	boxes.push_back(box2);
	box2->setPosition(Point(700, 200));
	auto box3 = Sprite::create("boxclosered.png");
	boxes.push_back(box3);
	box3->setPosition(Point(900, 200));
	auto box4 = Sprite::create("boxclosered.png");
	boxes.push_back(box4);
	box4->setPosition(Point(500,400));
	auto box5 = Sprite::create("boxclosered.png");
	boxes.push_back(box5);
	box5->setPosition(Point(700, 400));
	auto box6 = Sprite::create("boxclosered.png");
	boxes.push_back(box6);
	box6->setPosition(Point(900, 400));
	auto box7 = Sprite::create("boxclosered.png");
	boxes.push_back(box7);
	box7->setPosition(Point(500, 600));
	auto box8= Sprite::create("boxclosered.png");
	boxes.push_back(box8);
	box8->setPosition(Point(700, 600));
	auto box9 = Sprite::create("boxclosered.png");
	boxes.push_back(box9);
	box9->setPosition(Point(900, 600));
	// sequence boshano
	auto sequence = Sprite::create("sequencelist.png");
	sequence->setPosition(Point(1150, 400));
	sprite->addChild(sequence);


   for(i = 0; i < 9; i++)
	{
		auto boxplacing = boxes.at(i);
		sprite->addChild(boxplacing);
	}
	//boxkhula 
      
	   int rand = cocos2d::RandomHelper::random_int(0, 13);
	   store = rand;
	   int rand1= cocos2d::RandomHelper::random_int(0, 13);
	   int rand2 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand3 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand4 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand5 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand6 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand7 = cocos2d::RandomHelper::random_int(0, 13);
	   int rand8 = cocos2d::RandomHelper::random_int(0, 13);
	   

	   c = 0;
	   for (i = 0; i < 9; i++)
	   {

		  
		   auto boxkhulbe = boxes.at(i);
		   if (i != rand && i!=rand1 && i!=rand2 && i!= rand3 && i!= rand4 && i != rand5 && i!= rand6 && i!= rand7 && i!=rand8)
		   {
			   boxkhul(boxkhulbe);
		   }

		   else
		   {

			   auto spriteBatch = SpriteBatchNode::create("allboxes.png", 200);
			   auto spriteFrameCache = SpriteFrameCache::getInstance();
			   spriteFrameCache->addSpriteFramesWithFile("allboxes.plist");
			   sprite->addChild(spriteBatch);
			   SpriteFrameCache* cache = SpriteFrameCache::getInstance();
			   Vector<SpriteFrame*> moveAnimFrames(4); // parameter = number of frames I  have for this animation
			   moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			   char str[100] = { 0 };
			   int box_name = (i + rand) % 13;
			   sprintf(str, "potionbox%d.png", box_name);
			   SpriteFrame* frame = cache->getSpriteFrameByName(str);
			   moveAnimFrames.pushBack(frame);
			   moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
			   Animation* moveAnimation = Animation::createWithSpriteFrames(moveAnimFrames, 4);
			   moveAnimation->setLoops(1);
			   Animate* moveAnimate = Animate::create(moveAnimation);
			   moveAnimate->retain();
			   boxkhulbe->runAction(moveAnimate); //animation choltese
			   index[c] = box_name;
			   c++;
		   }

	   }

	   //box move

	   int xra[10] = { 500,700,900,500,700,900,500,700,900 };
	   //one eternity later, If I forget about this, Just remember xra holo x er coordinate ra)
	   int yra[10] = { 200,200,200,400,400,400,600,600,600 };
	   int boxara[] = { 0,1,2,3,4,5,6,7,8 };//hudai;
	  

	   int shuffle_rand = cocos2d::RandomHelper::random_int(100, 995);
	   
	   for (i = 0; i < 9; i++)
	   {
		   int ind = (i + shuffle_rand) % 9;
		   int notun_box_x = xra[ind];
		   int notun_box_y = yra[ind];
		   auto boxmoving = boxes.at(i);
		   auto moveTo = MoveTo::create(0.8, Vec2(notun_box_x, notun_box_y));
		   auto delay = DelayTime::create(10);
		   auto seq = Sequence::create(delay, moveTo, nullptr);
		   boxmoving->runAction(seq);
		  
	   }
	   fp = fopen("points.txt", "r");
	   fscanf(fp, "%d", &point);
	  
	   __String *tempscore = __String::createWithFormat("%d", point);
	    PointInfo = Label::createWithSystemFont(tempscore->getCString(), "Arial", 30);
	   PointInfo->setPosition(Vec2(1000,700));
	    sprite->addChild(PointInfo);
	
	     fclose(fp);

		  auto touchListener = EventListenerTouchOneByOne::create();
		  touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
		 _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
	
}

void GameScene::Next(Ref *pSender)
{
	/*if (scene_num < 0)
	{
		auto scene = FightScene::createScene();
		Director::getInstance()->pushScene(scene);
	}*/
	if(scene_num>=0 && scene_num<8)
	{
		auto scene = DeathScene::createScene();
		Director::getInstance()->pushScene(scene);
	}
	else
	{
		auto scene = CrossScene::createScene();
		Director::getInstance()->pushScene(scene);
	}


}
void GameScene::Back(Ref *pSender)
{
		auto scene = GraphicsScene::createScene();
		Director::getInstance()->pushScene(scene);
}

// click er kaj

	bool GameScene::onTouchBegan(Touch* touch, Event* event)
	{
		    
			int flag = 0;
			Vec2 location = touch->getLocation();
			for (int i = 0; i < 9; i++)
			{


				Vec2 box1location = boxes.at(i)->getPosition();
				Vec2 contentsize1 = boxes.at(i)->getContentSize();
				if (location.x >= box1location.x - contentsize1.x / 4 && location.x <= box1location.x + contentsize1.x / 4 && location.y >= box1location.y - contentsize1.y / 4 && location.y <= box1location.y + contentsize1.y / 4)
				{
					for (int j = 0; j < c; j++)
					{
						if (((i+store)%13) == index[j])
						{
							flag = 1;
							break;
						}
						else
						{
							flag = 0;
						}

					}
					auto khulbo_ami_dekhbe_desh = boxes.at(i);
					if (flag == 0)
					{
					      fakabox(khulbo_ami_dekhbe_desh);

						   scene_num = -1;

					}
					else 
					{

                        
						auto spriteBatch = SpriteBatchNode::create("allboxes.png", 200);
						auto spriteFrameCache = SpriteFrameCache::getInstance();
						spriteFrameCache->addSpriteFramesWithFile("allboxes.plist");
						this->addChild(spriteBatch);
						SpriteFrameCache* cache = SpriteFrameCache::getInstance();
						Vector<SpriteFrame*> moveAnimFrames(4); // parameter = number of frames you have for this anim
						moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
						char str[100] = { 0 };
						sprintf(str, "potionbox%d.png", (i+store)%13);
						SpriteFrame* frame = cache->getSpriteFrameByName(str);
						moveAnimFrames.pushBack(frame);
						//moveAnimFrames.pushBack(SpriteFrame::create("boxclosered.png", Rect(0, 0, 200, 150)));
						Animation* moveAnimation = Animation::createWithSpriteFrames(moveAnimFrames, 0.05);
						moveAnimation->setLoops(1);
						Animate* moveAnimate = Animate::create(moveAnimation);
						moveAnimate->retain(); // retain so you can use it again
						khulbo_ami_dekhbe_desh->runAction(moveAnimate); // run the animation

						if((i+store)%13<=7)
						{
						point = point + (i + 1) * 100;
						}
						else
						{
							point = point -(((i + store) % 13) * 50);
						}

						__String *tempscore = __String::createWithFormat("%d", point);
						PointInfo->setString(tempscore->getCString());
						fp = fopen("points.txt", "w");
						fprintf(fp, "%d", point);
						fclose(fp);
						scene_num = (i + store) % 13;
					}

				}

			}
			return true;
		
	}
	

void GameScene::MenuCloseCallback(Ref* pSender)
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
