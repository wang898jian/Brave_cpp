//add by sa14225023
#include "SelectScene.h"
#include "MainScene.h"
#include "VisibleRect.h"
#include "CustomTool.h"

bool SelectScene::init()
{
	if(!Layer::init())
		return false;
	log("SelectLayer::init");	
	auto background = Sprite::create("image/select.jpg");
	background->setPosition(VisibleRect::center());
	this->addChild(background);

	auto saber = CustomTool::createMenuItemImage("saber11.png", "saber22.png", CC_CALLBACK_0(SelectScene::onStartSaber,this));
	auto menu1 = Menu::createWithItem(saber);
	Vec2 centerPosition = VisibleRect::center();
	auto vSize = Director::getInstance()->getVisibleSize();
	menu1->setPosition(vSize.width/3*2,vSize.height/2);
	auto nomble = CustomTool::createMenuItemImage("heroking.png", "heroking2.png", CC_CALLBACK_0(SelectScene::onStartGoldKing,this));
	auto menu2 = Menu::createWithItem(nomble);
	menu2->setPosition(vSize.width/3,vSize.height/2);
	this->addChild(menu1);
	this->addChild(menu2);
	return true;
}


Scene* SelectScene::createScene()
{
	auto scene = Scene::create();   
	auto layer = SelectScene::create();
	scene->addChild(layer);
	return scene;
}

//modify by sa14225023
void SelectScene::onStartSaber(/*Ref* obj*/)
{
	log("StartLayer::onStart");
	Player::PlayerType saberType=Player::PlayerType::SABER;
	auto scene = MainScene::createScene(saberType);
	Director::getInstance()->replaceScene(scene);
}

void SelectScene::onStartGoldKing(/*Ref* obj*/)
{
	log("StartLayer::onStart");
	Player::PlayerType goldType=Player::PlayerType::GOLDKING;
	auto scene = MainScene::createScene(goldType);
	Director::getInstance()->replaceScene(scene);
}

