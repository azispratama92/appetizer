﻿/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "stdafx.h"

#ifndef __FolderItemRenderer_H
#define __FolderItemRenderer_H


#include "bitmap_controls/BitmapControl.h"
#include "imaging/NineSlicesPainter.h"
#include "FolderItem.h"
#include "utilities/MathUtil.h"
#include "TypeDefinitions.h"



class FolderItemRenderer: public BitmapControl {

public:

  FolderItemRenderer(wxWindow *owner, int id, wxPoint point, wxSize size);
  ~FolderItemRenderer();
  void DeleteSkinObjects();
  void LoadData(int folderItemId);
  void UpdateControlBitmap();
  void FitToContent();
  FolderItem* GetFolderItem();
  void ApplySkin();  
  wxMenu* GetPopupMenu();  

private:

  static int addToGroupMenuItemOffset_;

  static int uniqueID_;

  bool mouseInside_;
  bool mousePressed_;
  bool draggingStarted_;
  int folderItemId_;
  NineSlicesPainter* iconOverlayPainterUp_;
  NineSlicesPainter* iconOverlayPainterDown_;
  NineSlicesPainter* iconOverlayPainterInactive_;
  wxPoint pressPosition_;
  wxBitmap* multiLaunchIcon_;
  wxMenu* popupMenu_;

  void OnEnterWindow(wxMouseEvent& evt);
  void OnLeaveWindow(wxMouseEvent& evt);
  void OnLeftDown(wxMouseEvent& evt);
  void OnLeftUp(wxMouseEvent& evt);
  void OnMotion(wxMouseEvent& evt);
  void OnRightDown(wxMouseEvent& evt);
  void OnMouseCaptureLost(wxMouseCaptureLostEvent& evt);

  void OnMenuItemClick(wxCommandEvent& evt);

  DECLARE_EVENT_TABLE()

};


#endif // __FolderItemRenderer_H