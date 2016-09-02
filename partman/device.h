// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#ifndef DEEPIN_INSTALLER_REBORN_PARTMAN_DEVICE_H
#define DEEPIN_INSTALLER_REBORN_PARTMAN_DEVICE_H

#include <QList>

#include "partman/partition.h"
#include "partman/structs.h"

namespace partman {

class Device {
 public:
  Device();

  void reset();

  PartitionList partitions;
  QString model;
  QString path;
  Sector length;  // device length
  Sector heads;
  Sector sectors;
  Sector cylinders;
  Sector cylsize;
  QString disk_type;
  ByteValue sector_size;  // logical sector size
  int max_prims;
  bool read_only;

  PartitionTableType table;
};

typedef QList<Device> DeviceList;

}  // namespace partman

#endif  // DEEPIN_INSTALLER_REBORN_PARTMAN_DEVICE_H