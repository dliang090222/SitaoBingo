#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QPixmap"
#include "QThread"
#include "QTimer"
#include "game.h"
#include <iostream>
#include <QResizeEvent>

const int delays[] = {20, 10, 8, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 8, 10, 20};
const int kDelaySize = sizeof(delays) / sizeof(int);
int iDelay = 0;
int counter = delays[0];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow), timer_(new QTimer(this)),
      counter_(0) {
  ui_->setupUi(this);

  // style
  ui_->imageArea->setAlignment(Qt::AlignCenter);
  QFont font;
  font.setPointSize(80);
  ui_->nameArea->setFont(font);
  ui_->nameArea->setAlignment(Qt::AlignCenter);

  // setup
  LoadGames();
  LoadImages();

  // slots
  connect(timer_, SIGNAL(timeout()), this, SLOT(BingoProcess()));
  connect(ui_->leftArrow, SIGNAL(clicked()), this, SLOT(LeftArrowSlot()));
  connect(ui_->rightArrow, SIGNAL(clicked()), this, SLOT(RightArrowSlot()));
  connect(ui_->bingo, SIGNAL(clicked()), this, SLOT(Bingo()));
  connect(ui_->GameOne, SIGNAL(clicked()), this, SLOT(GameOne()));
  connect(ui_->GameTwo, SIGNAL(clicked()), this, SLOT(GameTwo()));
  connect(ui_->GameThree, SIGNAL(clicked()), this, SLOT(GameThree()));

  RenderImage();
}

MainWindow::~MainWindow() {
  delete ui_;
  delete timer_;
  for (auto game : games_) {
    delete game.second;
  }
}

Ui::MainWindow *MainWindow::GetUi() { return ui_; }

void MainWindow::LoadImages() {
  for (const Image &image : images) {
    games_.at(image.gameId)->AddImage(image);
  }
  games_.at(GameId::one)->Shuffle();
  games_.at(GameId::two)->Shuffle();
  games_.at(GameId::three)->Shuffle();
};

void MainWindow::LoadGames() {
  games_.insert({GameId::one, new Game()});
  games_.insert({GameId::two, new Game()});
  games_.insert({GameId::three, new Game()});
  currentGame_ = games_.at(GameId::one);
};

void MainWindow::RenderImage() { currentGame_->RenderCurrent(ui_); }

// Slots

void MainWindow::LeftArrowSlot() { currentGame_->RenderLast(ui_); }

void MainWindow::RightArrowSlot() { currentGame_->RenderNext(ui_); }

void MainWindow::Bingo() { timer_->start(50); }

void MainWindow::BingoProcess() {
  counter--;
  if (counter == 0) {
    iDelay++;
    currentGame_->RenderNext(ui_);
    counter = delays[iDelay];
  }
  if (iDelay == kDelaySize) {
    timer_->stop();
    iDelay = 0;
    counter = delays[0];
    currentGame_->Bingo(ui_); // Fake Bingo
  }
}

void MainWindow::GameOne() {
  currentGame_ = games_.at(GameId::one);
  RenderImage();
}

void MainWindow::GameTwo() {
  currentGame_ = games_.at(GameId::two);
  RenderImage();
}

void MainWindow::GameThree() {
  currentGame_ = games_.at(GameId::three);
  RenderImage();
}
