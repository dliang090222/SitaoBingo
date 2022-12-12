#include "game.h"
#include <algorithm>
#include <random>

#include "game_info.h"
#include "qlogging.h"
#include <iostream>

const std::string prefix = ":/images/";

Game::Game(GameId id) : id_(id), currentImage_(0) {}

Game::~Game() {
  for (auto image : images_) {
    delete image;
  }
}

void Game::AddImage(const Image &image) {
  ImageNamePair *i = new ImageNamePair();
  i->image.load(QString::fromStdString(prefix + image.filename));
  i->name = image.name;
  images_.emplace_back(i);
  if (image.chosen) {
    needToChoose_.emplace_back(i);
  }
}

void Game::RenderCurrent(Ui::MainWindow *ui) {
  ImageNamePair *image = images_[currentImage_];
  RenderImage(ui, *image);
}

void Game::RenderImage(Ui::MainWindow *ui, const ImageNamePair &image) {
  int w = ui->imageArea->width();
  int h = ui->imageArea->height();
  ui->imageArea->setPixmap(
      QPixmap::fromImage(image.image).scaled(w, h, Qt::KeepAspectRatio));
  ui->nameArea->setText(QString::fromStdString(image.name));
};

void Game::RenderLast(Ui::MainWindow *ui) {
  const int size = images_.size();
  currentImage_ = (currentImage_ - 1 + size) % size;
  RenderCurrent(ui);
}

void Game::RenderNext(Ui::MainWindow *ui) {
  const int size = images_.size();
  currentImage_ = (currentImage_ + 1 + size) % size;
  RenderCurrent(ui);
}

void Game::Bingo(Ui::MainWindow *ui) {
  if (needToChoose_.size() == 0) {
    return;
  }
  ImageNamePair *image = needToChoose_.back();
  needToChoose_.pop_back();
  RenderImage(ui, *image);
  // Shuffle();
}

void Game::Shuffle() {
  auto rd = std::random_device{};
  auto rng = std::default_random_engine{rd()};
  std::shuffle(std::begin(images_), std::end(images_), rng);
  std::shuffle(std::begin(needToChoose_), std::end(needToChoose_), rng);
}
