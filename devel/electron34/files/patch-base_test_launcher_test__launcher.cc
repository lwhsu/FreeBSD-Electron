--- base/test/launcher/test_launcher.cc.orig	2025-01-27 17:37:37 UTC
+++ base/test/launcher/test_launcher.cc
@@ -75,6 +75,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
