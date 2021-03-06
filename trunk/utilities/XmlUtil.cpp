﻿/*
  Copyright (C) 2008 Laurent Cozic. All right reserved.
  Use of this source code is governed by a GNU/GPL license that can be
  found in the LICENSE file.
*/

#include "../stdafx.h"

#include "XmlUtil.h"
#include "StringUtil.h"


void XmlUtil::AppendTextElement(TiXmlElement* targetElement, const char* elementName, const char* elementText) {
  TiXmlElement* element = new TiXmlElement(elementName);
  element->LinkEndChild(new TiXmlText(elementText));
  targetElement->LinkEndChild(element);
}


void XmlUtil::AppendTextElement(TiXmlElement* targetElement, const char* elementName, int elementText) {
  wxString s;
  s << elementText;
  XmlUtil::AppendTextElement(targetElement, elementName, s.mb_str());
}


void XmlUtil::AppendTextElement(TiXmlElement* targetElement, const char* elementName, bool elementText) {
  wxString s = elementText ? _T("1") : _T("0");
  XmlUtil::AppendTextElement(targetElement, elementName, s.mb_str());
}


void XmlUtil::AppendTextElement(TiXmlElement* targetElement, const char* elementName, wxString elementText) {
  XmlUtil::AppendTextElement(targetElement, elementName, elementText.ToUTF8());
}


wxString XmlUtil::ReadElementText(TiXmlHandle handle, const char* elementName, const wxString& defaultValue) {
  TiXmlElement* element = handle.Child(elementName, 0).ToElement();
  if (element) {
    const char* cString = element->GetText();
    if (!cString) return defaultValue;
    wxString output = wxString::FromUTF8(cString);
   
    return output;
  }
  return defaultValue;
}


bool XmlUtil::ReadElementTextAsBool(TiXmlHandle handle, const char* elementName, bool defaultValue) {
  wxString s = XmlUtil::ReadElementText(handle, elementName, defaultValue ? _T("1") : _T("0"));
  return s.Upper() == _T("TRUE") || s == _T("1");
}


int XmlUtil::ReadElementTextAsInt(TiXmlHandle handle, const char* elementName, int defaultValue) {
  wxString s = XmlUtil::ReadElementText(handle, elementName);
  long tempLong;
  if (!s.ToLong(&tempLong)) {
    return defaultValue;
  } else {
    return (int)tempLong;
  }
}


bool XmlUtil::ReadElementTextAsRect(TiXmlHandle handle, const char* elementName, wxRect& resultRect) {
  wxString s = XmlUtil::ReadElementText(handle, elementName);

  wxArrayString splitted;
  StringUtil::Split(s, splitted, _T(","));
  if (splitted.Count() < 4) return false;

  long x; if (!splitted[0].ToLong(&x)) return false;
  long y; if (!splitted[1].ToLong(&y)) return false;
  long w; if (!splitted[2].ToLong(&w)) return false;
  long h; if (!splitted[3].ToLong(&h)) return false;

  resultRect = wxRect(x, y, w, h);
  return true;
}


bool XmlUtil::ReadElementTextAsPoint(TiXmlHandle handle, const char* elementName, wxPoint& resultPoint) {
  wxString s = XmlUtil::ReadElementText(handle, elementName);

  wxArrayString splitted;
  StringUtil::Split(s, splitted, _T(","));
  if (splitted.Count() < 2) return false;

  long x; if (!splitted[0].ToLong(&x)) return false;
  long y; if (!splitted[1].ToLong(&y)) return false;

  resultPoint = wxPoint(x, y);
  return true;
}


bool XmlUtil::ReadElementTextAsColor(TiXmlHandle handle, const char* elementName, wxColour& resultColor) {
  wxString s = XmlUtil::ReadElementText(handle, elementName);

  wxArrayString splitted;
  StringUtil::Split(s, splitted, _T(","));
  if (splitted.Count() < 3) return false;

  long r; if (!splitted[0].ToLong(&r)) return false;
  long g; if (!splitted[1].ToLong(&g)) return false;
  long b; if (!splitted[2].ToLong(&b)) return false;
  
  long a = 255;
  if (splitted.Count() >= 4) splitted[3].ToLong(&a);

  resultColor = wxColour(r,g,b,a);
  return true;
}


bool XmlUtil::ReadElementTextAsArrayString(TiXmlHandle handle, const char* elementName, wxArrayString& result) {
  wxString s = XmlUtil::ReadElementText(handle, elementName);

  wxArrayString splitted;
  StringUtil::Split(s, result, _T(","));

  return true;
}