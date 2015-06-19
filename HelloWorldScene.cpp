#include "HelloWorldScene.h"
#include "Score.h"
#include "Ranking.h"
#include "AppMacros.h"
#include "C:\Users\Jusu\workspace\cocos2d-x-3.5-tizen\cocos\audio\include\SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::scene() {

	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
	static int num = 0;

	if (!Layer::init()) {
		return false;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
			"Kalimba.mp3");

	_gameTime = 60;
	_score = 0;

	createGameScene();

	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto positionListener = EventListenerTouchOneByOne::create();
	positionListener->setSwallowTouches(true);
	positionListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan,
			this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
			positionListener, this);
	this->setTouchEnabled(true);
	this->schedule(schedule_selector(HelloWorld::timeCount), 1.0f);
	this->schedule(schedule_selector(HelloWorld::AddMole), 1.1f);

	return true;
}

void HelloWorld::createGameScene() {
	_screenSize = Director::sharedDirector()->getWinSize();

	CCSprite* background = CCSprite::create("gameback.png");
	background->setPosition(ccp(_screenSize.width / 2, _screenSize.height / 2));
	background->setScale(
			_screenSize.width / background->getContentSize().width); //화면에 꽉차게 배경화면 띄우기
	this->addChild(background);

	TimeBar();
	InitScore();

}

void HelloWorld::TimeBar() {
	_screenSize = Director::sharedDirector()->getWinSize();
	Sprite* timeOutline = Sprite::create("timebar.png");
	timeOutline->setScale(1);
	timeOutline->setRotation(90);
	timeOutline->setPosition(
			ccp(_screenSize.width * 0.1f, _screenSize.height * 0.5f));
	timeOutline->setColor(Color3B::GRAY);
	timeOutline->setVisible(true);
	this->addChild(timeOutline);

	Sprite* timerBar = Sprite::create("timebar.png");
	_progressTimeBar = ProgressTimer::create(timerBar);
	_progressTimeBar->setPercentage(100.0f);
	_progressTimeBar->setScale(1);
	_progressTimeBar->setRotation(90);
	_progressTimeBar->setPosition(
			ccp(_screenSize.width * 0.1f, _screenSize.height * 0.5f));
	_progressTimeBar->setMidpoint(ccp(0, 0.5f));
	_progressTimeBar->setBarChangeRate(ccp(1, 0));
	_progressTimeBar->setType(kCCProgressTimerTypeBar);
	this->addChild(_progressTimeBar);
	ProgressFromTo* progressFromToZero = ProgressFromTo::create(60, 100, 0);
	_progressTimeBar->runAction(progressFromToZero);

}

void HelloWorld::InitScore() {
	auto labelScore = Label::createWithSystemFont("", "", 18);
	labelScore->setPosition(
			ccp(_screenSize.width * 0.92f, _screenSize.height * 0.1f));
	labelScore->setTag(TAG_LABEL_SCORE);
	labelScore->setRotation(90);
	this->addChild(labelScore);
	AddScore(0);
}
void HelloWorld::AddScore(int add) {
	_score += add;

	auto labelScore = (Label*) this->getChildByTag(TAG_LABEL_SCORE);
	labelScore->setString(StringUtils::format("%d", _score));

}

void HelloWorld::AddMole(float time) {

	Vec2 _position;
	_screenSize = Director::sharedDirector()->getWinSize();
	int num = rand() % 9;

	if (num == 0) {
		_position = ccp(_screenSize.width * 0.75f, _screenSize.height * 0.75f);
	} else if (num == 1) {
		_position = ccp(_screenSize.width * 0.75f, _screenSize.height * 0.5f);
	} else if (num == 2) {
		_position = ccp(_screenSize.width * 0.75f, _screenSize.height * 0.25f);
	} else if (num == 3) {
		_position = ccp(_screenSize.width * 0.5f, _screenSize.height * 0.75f);
	} else if (num == 4) {
		_position = ccp(_screenSize.width * 0.5f, _screenSize.height * 0.5f);
	} else if (num == 5) {
		_position = ccp(_screenSize.width * 0.5f, _screenSize.height * 0.25f);
	} else if (num == 6) {
		_position = ccp(_screenSize.width * 0.25f, _screenSize.height * 0.75f);
	} else if (num == 7) {
		_position = ccp(_screenSize.width * 0.25f, _screenSize.height * 0.5f);
	} else {
		_position = ccp(_screenSize.width * 0.25f, _screenSize.height * 0.25f);
	}

	VariableMole(_position);

}

void HelloWorld::VariableMole(Vec2 position) {

	int variable_num = rand() % 5;
	_flag = true;

	if (variable_num == 0) {
		CCSprite* normal_mole = CCSprite::create("mole_01.png");
		normal_mole->setAnchorPoint(ccp(0.5, 0.5)); //그림의 중심점 기준
		normal_mole->setPosition(position);
		normal_mole->setTag(TAG_SPRITE_IMAGE);
		_type = 0;
		this->addChild(normal_mole);
		auto action_1 = DelayTime::create(1.0f);
		auto action_2 = RemoveSelf::create(false);
		auto cb = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeFlag, this));
		auto seq = Sequence::create(action_1, action_2, cb, NULL);
		normal_mole->runAction(seq);

	} else if (variable_num == 1) {
		CCSprite* king_mole = CCSprite::create("mole_02.png");
		king_mole->setAnchorPoint(ccp(0.5, 0.5)); //그림의 중심점 기준
		king_mole->setPosition(position);
		king_mole->setTag(TAG_SPRITE_IMAGE);
		_type = 1;
		this->addChild(king_mole);
		auto action_1 = DelayTime::create(1.0f);
		auto action_2 = RemoveSelf::create(false);
		auto cb = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeFlag, this));
		auto seq = Sequence::create(action_1, action_2, cb, NULL);
		king_mole->runAction(seq);
	} else if (variable_num == 2) {
		CCSprite* red_mole = CCSprite::create("mole_03.png");
		red_mole->setAnchorPoint(ccp(0.5, 0.5)); //그림의 중심점 기준
		red_mole->setPosition(position);
		red_mole->setTag(TAG_SPRITE_IMAGE);
		_type = 2;
		this->addChild(red_mole);
		auto action_1 = DelayTime::create(0.5f);
		auto action_2 = RemoveSelf::create(false);
		auto cb = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeFlag, this));
		auto seq = Sequence::create(action_1, action_2, cb, NULL);
		red_mole->runAction(seq);
	} else if (variable_num == 3) {
		CCSprite* green_mole = CCSprite::create("mole_04.png");
		green_mole->setAnchorPoint(ccp(0.5, 0.5)); //그림의 중심점 기준
		green_mole->setPosition(position);
		green_mole->setTag(TAG_SPRITE_IMAGE);
		_type = 3;
		this->addChild(green_mole);
		auto action_1 = DelayTime::create(0.75f);
		auto action_2 = RemoveSelf::create(false);
		auto cb = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeFlag, this));
		auto seq = Sequence::create(action_1, action_2, cb, NULL);
		green_mole->runAction(seq);
	} else {
		CCSprite* rabbit = CCSprite::create("rabbit.png");
		rabbit->setAnchorPoint(ccp(0.5, 0.5)); //그림의 중심점 기준
		rabbit->setPosition(position);
		rabbit->setTag(TAG_SPRITE_IMAGE);
		_type = 4;
		this->addChild(rabbit);
		auto action_1 = DelayTime::create(1.0f);
		auto action_2 = RemoveSelf::create(false);
		auto cb = CallFunc::create(CC_CALLBACK_0(HelloWorld::changeFlag, this));
		auto seq = Sequence::create(action_1, action_2, cb, NULL);
		rabbit->runAction(seq);
	}

}

void HelloWorld::changeFlag() {
	_flag = false;
}

void HelloWorld::compareImage(Vec2 onTouchBeganLocation) {

	Score* sc = new Score();
	Vec2 location = onTouchBeganLocation;
	int scoreTmp;
	auto spr1 = (Sprite*) this->getChildByTag(TAG_SPRITE_IMAGE);
	Rect rect1 = spr1->boundingBox();

	if (rect1.containsPoint(location)) {
		scoreTmp = sc->scoring(_type);
		AddScore(scoreTmp);
		if (_type == 4) {
			Sprite *change = Sprite::create("deadRabbit.png");
			spr1->setTexture(change->getTexture());
		} else {
			Sprite *change = Sprite::create("deadMole_01.png");
			spr1->setTexture(change->getTexture());
		}
		_flag = false;
	} else {

	}
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event) {

	Vec2 location = touch->getLocation();

	if (_flag == true)
		compareImage(location);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(
			"pew-pew-lei.wav");

	return true;
}

void HelloWorld::timeCount(float time) {
	if (--_gameTime == 0) {

		Director::getInstance()->replaceScene(Ranking::scene());

	}
}
