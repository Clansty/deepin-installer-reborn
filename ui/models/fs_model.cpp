// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "fs_model.h"

#include "ui/delegates/partition_util.h"

namespace installer {

FsModel::FsModel(const FsTypeList& fs_list, QObject* parent)
    : QAbstractListModel(parent),
      fs_list_(fs_list),
      inited_fs_list_(fs_list) {
  this->setObjectName("fs_model");
}

QVariant FsModel::data(const QModelIndex& index, int role) const {
  if (role != Qt::DisplayRole) {
    return QVariant();
  }

  const int row = index.row();
  if (index.isValid() && row >= 0 && row < fs_list_.length()) {
    const FsType fs = fs_list_.at(index.row());
    return GetLocalFsTypeName(fs);
  } else {
    return QVariant();
  }
}

int FsModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return fs_list_.length();
}

FsType FsModel::getFs(int index) const {
  Q_ASSERT(index < fs_list_.length());
  if (index >= 0 && index < fs_list_.length()) {
    return fs_list_.at(index);
  } else {
    return FsType::Unknown;
  }
}

int FsModel::index(FsType fs_type) const {
  // Might return -1.
  return fs_list_.indexOf(fs_type);
}

void FsModel::setEfiEnabled(bool efi_enabled) {
  this->beginResetModel();

  fs_list_ = inited_fs_list_;
  if (!efi_enabled) {
    fs_list_.removeOne(FsType::EFI);
  }

  this->endResetModel();
}

}  // namespace installer