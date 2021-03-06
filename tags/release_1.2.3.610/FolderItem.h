﻿/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "stdafx.h"

#ifndef __FolderItem_H
#define __FolderItem_H


#include "Constants.h"
#include "TypeDefinitions.h"
#include "ExtendedMenuItem.h"
#include "utilities/XmlUtil.h"


// Forward declaration so that we can create the typedef below
class FolderItem;

typedef std::vector<FolderItem*> FolderItemVector;


WX_DECLARE_HASH_MAP(int, wxIcon*, wxIntegerHash, wxIntegerEqual, IconHashMap);
WX_DECLARE_HASH_MAP(int, FolderItem*, wxIntegerHash, wxIntegerEqual, FolderItemIdHashMap);


class FolderItem : public wxEvtHandler {

public:

  FolderItem(bool isGroup = false);
  ~FolderItem();
  static FolderItem* CreateFolderItem(bool isGroup = false);
  static FolderItem* GetFolderItemById(int id);
  void Dispose();
  bool IsDisposed();

  wxString GetUUID();
  int GetId() const;
  void AutoSetName();
  wxString GetName(bool returnUnnamedIfEmpty = false);
  wxString GetResolvedPath();
  wxString GetFileName(bool includeExtension = true);
  wxString GetFilePath();
  wxIcon* GetIcon(int iconSize);
  void SetFilePath(const wxString& filePath);
  void SetName(const wxString& name);  
  void ClearCachedIcons();  

  static wxIcon* CreateSpecialItemIcon(const wxString& path, int iconSize);
  static wxIcon* CreateDefaultGroupIcon(int iconSize);

  wxString GetIconDiskCacheHash();
  static void CacheIconToDisk(const wxString& hash, wxIcon* icon, int iconSize);
  static wxIcon* GetIconFromDiskCache(const wxString& hash, int iconSize);

  void AppendAsMenuItem(wxMenu* parentMenu, int iconSize = SMALL_ICON_SIZE, const wxString& menuItemName = _T("folderItem"));
  wxMenu* ToMenu(int iconSize = SMALL_ICON_SIZE, const wxString& menuItemName = _T("folderItem"));
  ExtendedMenuItem* ToMenuItem(wxMenu* parentMenu, int iconSize = SMALL_ICON_SIZE, const wxString& menuItemName = _T("folderItem"));

  void Launch();
  void LaunchWithArguments(const wxString& arguments);
  static void Launch(const wxString& filePath, const wxString& arguments = wxEmptyString);

  TiXmlElement* ToXml();
  void FromXml(TiXmlElement* xml);

  void SetParameters(const wxString& parameters);
  wxString GetParameters();

  bool GetAutomaticallyAdded();
  void SetAutomaticallyAdded(bool automaticallyAdded);

  void SetCustomIcon(const wxString& filePath, int index = 0);
  wxString GetCustomIconPath();
  int GetCustomIconIndex();

  void AddToMultiLaunchGroup();
  void RemoveFromMultiLaunchGroup();
  bool BelongsToMultiLaunchGroup();  

  static wxString ResolvePath(const wxString& filePath, bool normalizeToo = true);
  static wxString ConvertToRelativePath(const wxString& filePath);
  static wxString GetDisplayName(const wxString& unresolvedFilePath);

  static void DestroyStaticData();
  
  bool DoMultiLaunch();
  
  // ***************************************************************
  // Methods to work with children
  // ***************************************************************
  bool ContainsGroups();
  FolderItemVector GetAllGroups(bool recursively = true);

  bool IsGroup();
  FolderItemVector GetChildren();  
  FolderItem* GetParent();
  void SetParent(FolderItem* folderItem);
  void RemoveChild(FolderItem* folderItem);
  void MoveChild(FolderItem* folderItemToMove, int insertionIndex);
  FolderItem* SearchChildByFilename(const wxString& filename, int matchMode = 2);

  int ChildrenCount();

  FolderItem* GetChildAt(int index);
  FolderItem* GetChildById(int folderItemId, bool recurse = true);
  FolderItem* GetChildByUUID(const wxString& uuid, bool recurse = true);
  FolderItem* GetChildByResolvedPath(const wxString& filePath);

  void InsertChildBefore(FolderItem* toAdd, FolderItem* previousFolderItem);
  void InsertChildAfter(FolderItem* toAdd, FolderItem* previousFolderItem);
  void PrependChild(FolderItem* toAdd);
  void AddChild(FolderItem* folderItem);

  void OnMenuItemClick(wxCommandEvent& evt);   

private:

  void ConvertOldVariablesToNew(wxString& s);

  static int uniqueID_;

  wxString parameters_;
  bool isGroup_;
  FolderItem* parent_;
  int id_;
  FolderItemVector children_;
  bool belongsToMultiLaunchGroup_;
  wxString name_;
  wxString filePath_;
  IconHashMap icons_;
  wxString uuid_;
  bool automaticallyAdded_;
  wxString iconCacheHash_;
  wxString customIconPath_;
  int customIconIndex_;
  wxString resolvedPath_;
  bool isDisposed_;
  static std::map<std::pair<wxString, int>, wxIcon*> defaultIcons_;
  
  static FolderItemIdHashMap folderItemIdHashMap_;

};


#endif // __FolderItem_H