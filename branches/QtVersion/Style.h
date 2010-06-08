/*
  Copyright (C) 2008-2010 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include <stable.h>

#ifndef Appetizer_Style_H
#define Appetizer_Style_H

namespace appetizer {


class RectangleStyle { public:
  int left;
  int right;
  int bottom;
  int top;
  int width;
  int height;
  void fromRect(const QRect& rect);
};

class TextFormat { public:
  TextFormat();
  void fromXml(TiXmlHandle handle);

  QColor color;
  int size;
  bool bold;
  QString family;
  QFont font();

  private:

    bool fontInitialized_;
    QFont font_;
};

class IconStyle { public:
  RectangleStyle padding;
  int labelGap;
};

class BackgroundStyle { public:
  RectangleStyle padding;
};

class TabStyle { public:
  RectangleStyle padding;
  RectangleStyle margin;
  TextFormat textFormat;
};


class Style {

public:

  static IconStyle icon;
  static BackgroundStyle background;
  static TabStyle tab;

  static void loadSkinFile(const QString& filePath);

};

}
#endif // Appetizer_Style_H