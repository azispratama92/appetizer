/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#ifndef __FilePaths_H
#define __FilePaths_H

#include "wx/wx.h"

class FilePaths {

public:

  static wxString GetApplicationDrive();
  static wxString GetApplicationDirectory();
  static wxString GetDataDirectory();
  static wxString GetSettingsDirectory();
  static wxString GetBaseSkinDirectory();
  static wxString GetSkinDirectory();
  static wxString GetLocalesDirectory();
  static wxString GetHelpDirectory();
  static wxString GetIconsDirectory();
  static wxString GetSettingsFile();
  static wxString GetFolderItemsFile();
  static wxString GetWindowFile();

  static void CreateSettingsDirectory();
  static void InitializePaths();

private:

  static wxString ApplicationDrive_;
  static wxString ApplicationDirectory_;
  static wxString DataDirectory_;
  static wxString SettingsDirectory_;
  static wxString BaseSkinDirectory_;
  static wxString SkinDirectory_;
  static wxString LocalesDirectory_;
  static wxString HelpDirectory_;
  static wxString IconsDirectory_;
  static wxString SettingsFile_;
  static wxString FolderItemsFile_;
  static wxString WindowFile_;

};

#endif // __FilePaths_H