/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "../stdafx.h"

#ifndef __azIcon_H
#define __azIcon_H


#include "../FolderItemRenderer.h"
#include "azWrapper.h"


class azIcon : public azWrapper {

public:

  azIcon(FolderItemRenderer* r);
  azIcon(lua_State *L);
  
  int getDockItem(lua_State *L);
  
  static const char className[];
  static Lunar<azIcon>::RegType methods[];

  FolderItemRenderer* Get() const;

private:

  int rendererId_;
  
};


#endif // __azIcon_H