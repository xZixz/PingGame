#include "cocos2d.h"
#include "TileTheme.h"

USING_NS_CC;

class PTile : public Sprite {
public:

  static PTile* create(std::string themeName);
  static PTile* create();
  virtual bool init(std::string themeName);

  PTile();
  ~PTile();
private:
  TileTheme _theme;

};
