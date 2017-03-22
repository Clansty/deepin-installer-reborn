// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef INSTALLER_UI_DELEGATES_ADVANCED_PARTITION_ANIMATIONS_H
#define INSTALLER_UI_DELEGATES_ADVANCED_PARTITION_ANIMATIONS_H

#include <QObject>
class QGraphicsOpacityEffect;
class QParallelAnimationGroup;
class QPropertyAnimation;

namespace installer {

// All animations of AdvancedPartitionFrame are defined and implemented in
// this class.
class AdvancedPartitionAnimations : public QObject {
  Q_OBJECT

 public:
  explicit AdvancedPartitionAnimations(QObject* parent = nullptr);

 public slots:
  // Show |widget| with animations. And |widget| shall be placed in a
  // QVBoxLayout.
  //  * opacity: 0% -> 100%
  //  * height: 80% -> 100%
  void showWidget(QWidget* widget);

  // Hide |widget| with animations. And |widget| shall be placed in a
  // QVBoxLayout.
  //  * opacity: 100% -> 0%
  //  * height: 100% -> 80%
  void hideWidget(QWidget* widget);

 private:
  void initAnimations();

  QParallelAnimationGroup* animation_group_ = nullptr;
  QGraphicsOpacityEffect* opacity_effect_ = nullptr;
  QPropertyAnimation* opacity_animation_ = nullptr;
  QPropertyAnimation* height_animation_ = nullptr;
};

}  // namespace installer

#endif  // INSTALLER_UI_DELEGATES_ADVANCED_PARTITION_ANIMATIONS_H