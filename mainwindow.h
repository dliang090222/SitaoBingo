#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QTimer"
#include "game.h"
#include "game_info.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  Ui::MainWindow *GetUi();

private slots:
  void RightArrowSlot();
  void LeftArrowSlot();
  void Bingo();
  void BingoProcess();
  void GameOne();
  void GameTwo();
  void GameThree();

private:
  void LoadGames();
  void LoadImages();
  void RenderImage();

  Ui::MainWindow *ui_;
  QTimer *timer_;
  std::map<GameId, Game *> games_;
  int counter_;
  Game *currentGame_;
};

#endif // MAINWINDOW_H
