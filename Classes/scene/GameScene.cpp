#include "GameScene.h"
#include "../Constants.h"

#define TILE_COLUMN_NUM 8
#define TILE_ROW_NUM 20
#define LEFT_PADDING 15
#define BOTTOM_PADDING 15
#define SPACING 10

Scene* GameScene::createScene() {
  auto scene = Scene::create();
  auto layer = GameScene::create();
  scene->addChild(layer);
  return scene;
}

bool GameScene::init() {

  if (Layer::init()) {

    _baseNode = Node::create();

    addChild(_baseNode);
    enableTouches();

    // Tile generates
    int rows = TILE_ROW_NUM;
    int columns = TILE_COLUMN_NUM;
    int leftPadding = LEFT_PADDING;
    int bottomPadding = BOTTOM_PADDING;
    int spacing = SPACING;
    std::string tileTheme = "default";
    for (int j = 0; j < columns; j ++) {
      for (int i = 0; i < rows; i++) {
        Vec2 pos;
        pos.x = leftPadding + i*(TILE_WIDTH + spacing);
        pos.y = bottomPadding + j*(TILE_WIDTH + spacing);
        PTile* tile = PTile::create(tileTheme);
        tile->setPosition(pos);
        _baseNode->addChild(tile);
      }
    }
    return true;
  }
  return false;
}

void GameScene::enableTouches() {
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchAllAtOnce::create();
  listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
  listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::onTouchesBegan(const std::vector<Touch*> touches, Event* event) {

}

void GameScene::onTouchesEnded(const std::vector<Touch*> touches, Event* event) {

}

GameScene::GameScene() {

}

GameScene::~GameScene() {

}
