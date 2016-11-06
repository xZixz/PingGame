#include "GameScene.h"
#include "../Constants.h"
#include "../Utils.h"

#define TILE_COLUMN_NUM 8
#define TILE_ROW_NUM 10
#define LEFT_PADDING 25
#define BOTTOM_PADDING 25
#define SPACING 10

Scene* GameScene::createScene() {
  auto scene = Scene::create();
  auto layer = GameScene::create();
  scene->addChild(layer);
  return scene;
}

bool GameScene::init() {

  if (LayerColor::initWithColor(Color4B::WHITE)) {

    _baseNode = Node::create();
    _baseNode->setPosition(Vec2::ZERO);

    addChild(_baseNode);
    enableTouches();

    _screenSize = Director::getInstance()->getWinSize();

    // Tile generates
    int rows = TILE_ROW_NUM;
    int columns = TILE_COLUMN_NUM;
    int leftPadding = LEFT_PADDING;
    int bottomPadding = BOTTOM_PADDING;
    int spacing = SPACING;
    std::string tileTheme = "default";
    for (int j = 0; j < rows; j ++) {
      for (int i = 0; i < columns; i++) {
        Vec2 pos;
        pos.x = leftPadding + i*(TILE_WIDTH + spacing) + TILE_WIDTH / 2;
        pos.y = bottomPadding + j*(TILE_WIDTH + spacing) + TILE_WIDTH / 2;
        PTile* tile = PTile::create(tileTheme);
        tile->setPosition(pos);
        _baseNode->addChild(tile);
        _currentTiles.push_back(tile);
        tile->setSceneDelegate(this);
      }
    }

    // Score Label
    _score = 0;
   addScore(0);

    return true;
  }
  return false;
}

void GameScene::enableTouches() {
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);
  listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
  listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool GameScene::onTouchBegan(const Touch* touch, Event* event) {
	Vec2 touchPoint = touch->getLocation();
  int xIndex = (int)(touchPoint.x - LEFT_PADDING) / (TILE_WIDTH + SPACING);
  int yIndex = (int)(touchPoint.y - BOTTOM_PADDING) / (TILE_WIDTH + SPACING);
  int blockIndex = yIndex * TILE_COLUMN_NUM + xIndex;
  PTile* tile = _currentTiles.at(blockIndex);
  tile->onClick();
  return true;
}

void GameScene::onTouchEnded(const Touch* touch, Event* event) {

}

void GameScene::addScore(int score) {
  _score += score;
  std::string scoreString = PUtils::to_string(_score);
  if (_scoreLabel == nullptr) {
    _scoreLabel = Label::createWithTTF(scoreString, "fonts/arial.ttf", 24);
    _scoreLabel->setColor(Color3B::BLACK);
    _scoreLabel->setPosition(_screenSize.width - 20, _screenSize.height - 20);
    addChild(_scoreLabel);
  } else {
    _scoreLabel->setString(scoreString);
  }
}

void GameScene::tileEndAct() {
  addScore(1);
}

GameScene::GameScene():_scoreLabel(nullptr) {

}

GameScene::~GameScene() {

}
