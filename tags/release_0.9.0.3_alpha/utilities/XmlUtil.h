#ifndef __XmlUtil_H
#define __XmlUtil_H

#include <wx/wx.h>
#include "../third_party/tinyxml/tinyxml.h"


class XmlUtil {

public:

  static void AppendTextElement(TiXmlElement* targetElement, const char* elementName, const char* elementText); 
  static void AppendTextElement(TiXmlElement* targetElement, const char* elementName, wxString elementText); 
  static void AppendTextElement(TiXmlElement* targetElement, const char* elementName, bool elementText); 
  static void AppendTextElement(TiXmlElement* targetElement, const char* elementName, int elementText);
  
  static wxString ReadElementText(TiXmlHandle handle, const char* elementName, const wxString& defaultValue = wxEmptyString);
  static bool ReadElementTextAsBool(TiXmlHandle handle, const char* elementName, bool defaultValue = false);
  static int ReadElementTextAsInt(TiXmlHandle handle, const char* elementName, int defaultValue = 0);

};

#endif // __XmlUtil_H