/*
  Copyright (C) 2008-2010 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include <stable.h>

#include <Application.h>
#include <MainPanel.h>
#include <Style.h>

using namespace appetizer;


PageData::PageData() {
  tab_ = NULL;
  iconPanel_ = NULL;
}


PageData::~PageData() {
  SAFE_DELETE(tab_);
  SAFE_DELETE(iconPanel_);
}


TabSprite* PageData::tab() const {
  return tab_;
}


IconPanel* PageData::iconPanel() const {
  return iconPanel_;
}


void PageData::setTab(TabSprite* tab) {
  tab_ = tab;
}


void PageData::setIconPanel(IconPanel* iconPanel) {
  iconPanel_ = iconPanel;
}


MainPanel::MainPanel() {
  rootFolderItemId_ = -1;
  pageIndex_ = 0;

  backgroundSprite_ = new NineSliceItem();
  backgroundSprite_->loadBackgroundImage("s:\\Docs\\PROGS\\C++\\Appetizer\\source\\branches\\QtVersion\\Data\\Skin\\Default\\Background.png");
  addItem(backgroundSprite_);

  lastDrawnMaskSize_ = QSize(0, 0);
}


FolderItem* MainPanel::rootFolderItem() {
  return FolderItem::getFolderItemById(rootFolderItemId_);
}


void MainPanel::loadFolderItems(int rootFolderItemId) {
  // TODO: delete existing pages

  rootFolderItemId_ = rootFolderItemId;

  FolderItem* rootFolderItem = this->rootFolderItem();
  if (!rootFolderItem) {
    qCritical() << "This folder item doesn't exist:" << rootFolderItemId;
    return;
  }

  for (int i = 0; i < rootFolderItem->numChildren(); i++) {
    FolderItem* sectionFolderItem = rootFolderItem->getChildAt(i);
    
    if (sectionFolderItem->type() != FolderItem::Type_Section) {
      qCritical() << "Folder item structure is wrong - section expected:" << rootFolderItemId;
      return;
    }

    TabSprite* tab = new TabSprite();
    addItem(tab);
    connect(tab, SIGNAL(mouseReleased()), this, SLOT(tab_clicked()));
    tab->loadFolderItem(sectionFolderItem->id());

    PageData* page = new PageData();
    page->setTab(tab);
    pages_.push_back(page);
  }

  pageIndex_ = 0;
  showPage(0);
  invalidate();
}


void MainPanel::tab_clicked() {
  TabSprite* sender = static_cast<TabSprite*>(QObject::sender());
  
  int pageIndex = -1;
  for (int i = 0; i < (int)pages_.size(); i++) {
    PageData* d = pages_[i];
    if (d->tab() == sender) {
      pageIndex = i;
      break;
    }
  }

  if (pageIndex < 0) {
    qCritical() << "No page associated with this tab";
    return;
  }

  showPage(pageIndex);
}


PageData* MainPanel::getPage(int index) {
  return pages_[index];

  //if (index < pages_.size() && pages_[index]) return pages_[index];

  //while (pages_.size() < index) pages_.push_back(NULL);

  //PageData* page = new PageData();
  //TabSprite* tab = new TabSprite();
  //IconPanel* iconPanel = new IconPanel();

  //FolderItem* pageFolderItem = rootFolderItem()->getChildAt(index);

  //page->setTab(tab);
  //page->setIconPanel(iconPanel);

  //iconPanel->loadFolderItems(pageFolderItem->id());

  //pages_.push_back(page);

  //return page;
}


PageData* MainPanel::showPage(int index) {
  PageData* page = getPage(index);

  return page;
}


NineSliceItem* MainPanel::backgroundSprite() const {
  return backgroundSprite_;
}


void MainPanel::drawMask(QPainter* painter, int x, int y, int width, int height) {
  if (lastDrawnMaskSize_.width() != width || lastDrawnMaskSize_.height() != height) {
    maskNineSlicePainter_.loadImage("s:\\Docs\\PROGS\\C++\\Appetizer\\source\\branches\\QtVersion\\Data\\Skin\\Default\\Background.png");
    maskPixmap_ = QPixmap(width, height);
    lastDrawnMaskSize_ = QSize(width, height);
  }
  
  maskNineSlicePainter_.drawImage(painter, x, y, width, height);
}


void MainPanel::updateDisplay() {
  GraphicsItem::updateDisplay();

  backgroundSprite_->resize(width(), height());

  //iconPanel_->setX(Style::background.padding.left);
  //iconPanel_->setY(Style::background.padding.top + 30);
  //iconPanel_->resize(width() - Style::background.padding.width, height() - Style::background.padding.height);

  int tabX = Style::background.padding.left + Style::tab.margin.left;
  int tabY = Style::background.padding.top + Style::tab.margin.top;
  int tabWidth = 0;
  if (pages_.size() > 0) {
    tabWidth = (width() - Style::background.padding.width - Style::tab.margin.width * pages_.size() + Style::tab.margin.right) / pages_.size();
  }

  for (int i = 0; i < (int)(pages_.size()); i++) {
    PageData* page = pages_[i];
    TabSprite* tab = page->tab();
    tab->move(tabX, tabY);
    tab->setWidth(tabWidth);

    tabX += tab->width() + Style::tab.margin.right;
  }
}