#include <stable.h>
#include <azApplication.h>
#include <azIconData.h>
#include <azIconUtil.h>
#include <azNineSliceItem.h>
#include <azMainWindow.h>


int main(int argc, char *argv[]) {
  azApplication app(argc, argv);
  app.setOrganizationName("Trolltech");
  app.setApplicationName("Application Example");

  azMainWindow mainWindow;
  mainWindow.show();

  //QGraphicsScene scene;

  //azNineSliceItem item;
  //item.loadBackgroundImage("c:\\Users\\Laurent_2\\Desktop\\200.PNG");

  //scene.addItem(&item);

  //scene.addText("Hello, world!");

  //azIconData iconData = azIconUtil::getFolderItemIcon("C:\\Program Files\\Adobe\\Adobe Photoshop CS4\\Photoshop.exe", 256);
  //scene.addPixmap(QPixmap::fromWinHICON(iconData.hIcon));

  //iconData = azIconUtil::getFolderItemIcon("C:\\Program Files\\Adobe\\Adobe Illustrator CS4\\Support Files\\Contents\\Windows\\AI_Application_Icon.ico", 48);
  //scene.addPixmap(QPixmap::fromWinHICON(iconData.hIcon));

  //QGraphicsView view(&scene); 
  //view.show();

  return app.exec();
}