// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef INSTALLER_UI_FRAMES_INNER_PARTITION_TABLE_WARNING_FRAME_H
#define INSTALLER_UI_FRAMES_INNER_PARTITION_TABLE_WARNING_FRAME_H

#include <QFrame>
class QLabel;

namespace installer {

class CommentLabel;
class ExpandedNavButton;
class TitleLabel;

// Displayed when partition table type and system boot method does not match.
class PartitionTableWarningFrame : public QFrame {
  Q_OBJECT

 public:
  explicit PartitionTableWarningFrame(QWidget* parent = nullptr);

  // Get/set device_path_.
  QString devicePath() const;
  void setDevicePath(const QString& device_path);

 signals:
  // Emitted when reboot button is clicked.
  void reboot();

  // Emitted when continue button is clicked.
  // |device_path| is the device disk path to be formatted.
  void confirmed(const QString& device_path);

 protected:
  void changeEvent(QEvent* event) override;

 private:
  void initConnections();
  void initUI();

  TitleLabel* title_label_ = nullptr;
  CommentLabel* comment_label_ = nullptr;
  QLabel* list_title1_ = nullptr;
  QLabel* list_item1_ = nullptr;
  QLabel* list_title2_ = nullptr;
  QLabel* list_item2_ = nullptr;
  QLabel* list_title3_ = nullptr;
  QLabel* list_item3_ = nullptr;
  ExpandedNavButton* reject_button_ = nullptr;
  ExpandedNavButton* accept_button_ = nullptr;

  QString device_path_;

 private slots:
  void onConfirmButtonClicked();
};

}  // namespace installer

#endif  // INSTALLER_UI_FRAMES_INNER_PARTITION_TABLE_WARNING_FRAME_H
