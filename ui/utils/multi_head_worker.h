// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef INSTALLER_MULTI_HEAD_WORKER_H
#define INSTALLER_MULTI_HEAD_WORKER_H

#include <QObject>

namespace installer {

// Monitors XRR change notify
class MultiHeadWorker : public QObject {
  Q_OBJECT

 public:
  explicit MultiHeadWorker(QObject* parent = nullptr);
  ~MultiHeadWorker();

 signals:
  void screenCountChanged();

  void start();
  void stop();

 private:
  void initConnections();
  bool is_running_;

 private slots:
  void doStart();
  void doStop();
};

}  // namespace installer

#endif  // INSTALLER_MULTI_HEAD_WORKER_H