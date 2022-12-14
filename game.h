#ifndef GAME_H
#define GAME_H

#include "./ui_mainwindow.h"
#include "QImage"
#include "game_info.h"
#include <string>
#include <vector>

struct ImageNamePair {
  QImage image;
  std::string name;
};

class Game {
public:
  Game() = default;
  explicit Game(GameId id);
  ~Game();

  void AddImage(const Image &image);
  void RenderLast(Ui::MainWindow *ui);
  void RenderNext(Ui::MainWindow *ui);
  void RenderCurrent(Ui::MainWindow *ui);
  void Bingo(Ui::MainWindow *ui);
  void Shuffle();
  void RenderImage(Ui::MainWindow *ui, const ImageNamePair &image);

private:
  GameId id_;
  std::vector<ImageNamePair *> images_;
  std::vector<ImageNamePair *> needToChoose_;
  std::vector<ImageNamePair *> chosen_;
  int currentImage_;
};

#endif // GAME_H
