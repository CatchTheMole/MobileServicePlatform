#include "MainScene.h"
#include "HelloWorldScene.h"
#include "Ranking.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

MainScene::~MainScene() {
}

CCScene* MainScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	MainScene *layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}

	createGameScene();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
			listener, this);

	this->setTouchEnabled(true);

	return true;
}

void MainScene::createGameScene(void) {
	_screenSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* MainSceneImage = CCSprite::create("gameback.png");
	MainSceneImage->setPosition(
			ccp(_screenSize.width / 2, _screenSize.height / 2));
	MainSceneImage->setScale(
			_screenSize.width / MainSceneImage->getContentSize().width);
	this->addChild(MainSceneImage);

	CCSprite* mole0 = CCSprite::create("mole_01.png");
	mole0->setPosition(
			ccp(_screenSize.width * 0.7f, _screenSize.height * 0.25f));
	mole0->setScale(0.8f);
	this->addChild(mole0);

	CCSprite* mole1 = CCSprite::create("mole_02.png");
	mole1->setPosition(
			ccp(_screenSize.width * 0.72f, _screenSize.height * 0.5f));
	this->addChild(mole1);

	CCSprite* mole2 = CCSprite::create("mole_01.png");
	mole2->setPosition(
			ccp(_screenSize.width * 0.7f, _screenSize.height * 0.75f));
	mole2->setScale(0.8f);
	this->addChild(mole2);

	Label* label_gamestart = Label::createWithTTF("Game Start!",
			"fonts/arial.ttf", 28);
	label_gamestart->setAnchorPoint(ccp(0.5f, 0.5f));
	label_gamestart->setPosition(
			ccp(_screenSize.width * 0.5f, _screenSize.height * 0.5f));
	label_gamestart->setRotation(90.0f);
	this->addChild(label_gamestart);

	Blink* blinkLabel = Blink::create(300, 300);
	label_gamestart->runAction(blinkLabel);

	rankingButton = CCSprite::create("green button.png");
	rankingButton->setPosition(
			ccp(_screenSize.width * 0.34f, _screenSize.height * 0.5f));
	rankingButton->setScale(0.25f);
	rankingButton->setRotation(90.0f);
	this->addChild(rankingButton);

	Label* teamName = Label::createWithTTF("Team Thumb",
			"fonts/Marker Felt.ttf", 25);
	teamName->setPosition(
			ccp(_screenSize.width * 0.19f, _screenSize.height * 0.5f));
	teamName->setRotation(90.0f);
	teamName->setTextColor(Color4B::MAGENTA);
	this->addChild(teamName);

	Label* teamPeople = Label::createWithTTF(
			"Nakhyun Kim     Jusu Kim     Daehyun Yoon",
			"fonts/Marker Felt.ttf", 17);
	teamPeople->setPosition(
			ccp(_screenSize.width * 0.1f, _screenSize.height * 0.5f));
	teamPeople->setRotation(90.0f);
	teamPeople->setTextColor(Color4B::ORANGE);
	this->addChild(teamPeople);

	Label* teamPeople2 = Label::createWithTTF("&                & ",
			"fonts/Marker Felt.ttf", 17);
	teamPeople2->setPosition(
			ccp(_screenSize.width * 0.1f, _screenSize.height * 0.5f));
	teamPeople2->setRotation(90.0f);
	teamPeople2->setTextColor(Color4B::MAGENTA);
	this->addChild(teamPeople2);
}

bool MainScene::onTouchBegan(Touch *touch, Event *unused_event) {

	Vec2 location = touch->getLocation();
	Rect rect = rankingButton->getBoundingBox();

	//터치 이벤트가 Rect안(랭킹 버튼)에서 발생하면 랭킹화면으로, 그 외의 부분을 터치했으면 게임 start
	if (rect.containsPoint(location))
		Director::getInstance()->replaceScene(Ranking::scene());
	else
		Director::getInstance()->replaceScene(HelloWorld::scene());

	return true;
}
