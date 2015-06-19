#include "Ranking.h"
#include "HelloWorldScene.h"
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

USING_NS_CC;

CCScene* Ranking::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	Ranking *layer = Ranking::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Ranking::init() {
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}
	int myScore = 0;
	createGameScene();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Ranking::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
			listener, this);

	this->setTouchEnabled(true);

	return true;
}

void Ranking::createGameScene(void) {
	_screenSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* RankingImage = CCSprite::create("gameback no title.png");
	RankingImage->setPosition(
			ccp(_screenSize.width / 2, _screenSize.height / 2));
	RankingImage->setScale(
			_screenSize.width / RankingImage->getContentSize().width);
	this->addChild(RankingImage);

	Label* label_gamestart = Label::createWithTTF("Ranking", "fonts/arial.ttf",
			32);
	label_gamestart->setAnchorPoint(ccp(0.5f, 0.5f));
	label_gamestart->setPosition(
			ccp(_screenSize.width * 0.93f, _screenSize.height * 0.5f));
	label_gamestart->setRotation(90.0f);
	this->addChild(label_gamestart);

	// 1등
	CCSprite* mole1 = CCSprite::create("mole_02.png");
	mole1->setPosition(
			ccp(_screenSize.width * 0.78f, _screenSize.height * 0.78f));
	mole1->setScale(0.8f);

	// 2등
	CCSprite* mole2 = CCSprite::create("mole_01.png");
	mole2->setPosition(
			ccp(_screenSize.width * 0.63f, _screenSize.height * 0.77f));
	mole2->setScale(0.7f);
	this->addChild(mole2);

	this->addChild(mole1); // 이미지 덮히는 문제 때문에 2번 두더지 다음 1번 두더지를 그린다

	// 3등
	CCSprite* mole3 = CCSprite::create("rabbit.png");
	mole3->setPosition(
			ccp(_screenSize.width * 0.52f, _screenSize.height * 0.76f));
	mole3->setScale(0.5f);
	this->addChild(mole3);

	rankScore();
}

void Ranking::rankScore() {
//  test
	scoreList.push_back(100);
	scoreList.push_back(55);
	scoreList.push_back(5);
   scoreList.push_back(20);
    scoreList.push_back(77);
    scoreList.push_back(65);
    scoreList.push_back(2);
    scoreList.push_back(98);

	sort(scoreList.begin(), scoreList.end()); // 정렬
	reverse(scoreList.begin(), scoreList.end()); // 뒤집음
	scoreList.resize(scoreList.size() > 6 ? 6 : scoreList.size()); // 6개 넘으면 6등까지만 자름

	for (int i = 0; i < scoreList.size(); i++) // 6등까지
			{
		char scoreChar[50];
		sprintf(scoreChar, "%d.           point", i + 1);

		label_score[i][0] = Label::createWithTTF(scoreChar, "fonts/arial.ttf",
				26);
		label_score[i][0]->setAnchorPoint(ccp(0.5f, 0.5f));
		label_score[i][0]->setPosition(
				ccp(_screenSize.width * (0.125f * (7 - i) - 0.12f),
						_screenSize.height * 0.37f));
		label_score[i][0]->setRotation(90.0f);
		this->addChild(label_score[i][0]);

		sprintf(scoreChar, "%d", scoreList[i]);

		label_score[i][1] = Label::createWithTTF(scoreChar, "fonts/arial.ttf",
				30);
		label_score[i][1]->setAnchorPoint(ccp(0.5f, 0.5f));
		label_score[i][1]->setPosition(
				ccp(_screenSize.width * (0.125f * (7 - i) - 0.12f),
						_screenSize.height * 0.41f));
		label_score[i][1]->setRotation(90.0f);
		label_score[i][1]->setTextColor(Color4B::YELLOW);
		this->addChild(label_score[i][1]);
	}

}

bool Ranking::onTouchBegan(Touch *touch, Event *unused_event) {

	// 다시 메인화면으로 돌아감
	Director::getInstance()->replaceScene(MainScene::scene());
	return true;
}
