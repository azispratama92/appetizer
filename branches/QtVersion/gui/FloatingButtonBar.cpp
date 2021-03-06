/*
  Copyright (C) 2008-2010 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include <stable.h>

#include <Application.h>
#include <FloatingButtonBar.h>
#include <Style.h>

using namespace appetizer;


FloatingButtonBar::FloatingButtonBar(GraphicsWindow* parentWindow): GraphicsItem(parentWindow) {
  for (int i = 0; i < 3; i++) {
    FloatingButton* b = new FloatingButton(this->parentWindow());
    if (i == 0) b->setAction("Eject");
    if (i == 1) b->setAction("Minimize");
    if (i == 2) b->setAction("Close");
    buttons_.push_back(b);
    QObject::connect(b, SIGNAL(clicked()), this, SLOT(button_clicked()));
    addItem(b);
  }
}


void FloatingButtonBar::button_clicked() {
  FloatingButton* button = static_cast<FloatingButton*>(QObject::sender());

  if (button->action() == "Minimize") {
    Application::instance()->scheduleMinimize();
  } else if (button->action() == "Close") {
    Application::instance()->scheduleClose();
  }
}


int FloatingButtonBar::width() const {
  int count = (int)buttons_.size();
  if (count == 0) return 0;
  return count * buttons_[0]->width() + (count - 1) * Style::floatingButton.hGap;
}


int FloatingButtonBar::height() const {
  if (buttons_.size() == 0) return 0;
  return buttons_[0]->height();
}


void FloatingButtonBar::applySkin() {
  for (int i = (int)buttons_.size() - 1; i >= 0; i--) {
    FloatingButton* b = buttons_.at(i);
    b->applySkin();
  }
}


void FloatingButtonBar::updateDisplay() {
	GraphicsItem::updateDisplay();
	
  int buttonX = 0;
  int buttonY = 0;
  for (int i = 0; i < (int)buttons_.size(); i++) {
    FloatingButton* b = buttons_.at(i);
    b->move(buttonX, buttonY);
    buttonX += b->width() + Style::floatingButton.hGap;
  }
}