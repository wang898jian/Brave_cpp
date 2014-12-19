#include "StartScene.h"
#include "VisibleRect.h"
#include "CustomTool.h"
#include "SelectScene.h"

bool StartScene::init()
{
	if(!Layer::init())
		return false;
	log("StartLayer::init");

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/role.plist","image/role.pvr.ccz");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/ui.plist","image/ui.pvr.ccz");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/saber.plist","image/saber.pvr.ccz");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/heroking.plist","image/heroking.pvr.ccz");
	auto background = Sprite::create("image/select1.jpg");
	background->setPosition(VisibleRect::center());
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/start_button.plist","image/start_button.pvr.ccz");
	this->addChild(background);

	auto item = CustomTool::createMenuItemImage("start_button1.png", "start_button2.png", CC_CALLBACK_1(StartScene::onStart,this));
	auto menu = Menu::createWithItem(item);
	menu->setPosition(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/4);
	this->addChild(menu);
	return true;
}


Scene* StartScene::createScene()
{
    auto scene = Scene::create();   
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}


void StartScene::onStart(Ref* obj)
{
	log("StartLayer::onStart");
	auto scene = SelectScene::createScene();
	Director::getInstance()->replaceScene(scene);
}