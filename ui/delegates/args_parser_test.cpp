// Copyright (c) 2016 Deepin Ltd. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "ui/delegates/args_parser.h"

#include "third_party/googletest/include/gtest/gtest.h"

namespace installer {
namespace {

TEST(ArgsParserTest, Parser) {
  ArgsParser parser;
  const QString conf_file("/tmp/installer.conf");
  const QString log_file("/tmp/installer.log");
  QStringList args;
  args << "app-name" << "--conf-file" << conf_file
       << "--log-file" << log_file << "--auto-install";
  EXPECT_TRUE(parser.parse(args));
  EXPECT_TRUE(parser.isAutoInstallSet());
  EXPECT_EQ(parser.getConfFile(), conf_file);
  EXPECT_EQ(parser.getLogFile(), log_file);
}

}  // namespace
}  // namespace installer