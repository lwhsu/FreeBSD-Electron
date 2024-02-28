--- base/process/launch_posix.cc.orig	2024-02-21 00:20:30 UTC
+++ base/process/launch_posix.cc
@@ -61,6 +61,9 @@
 #error "macOS should use launch_mac.cc"
 #endif
 
+#if defined(OS_FREEBSD)
+#pragma weak environ
+#endif
 extern char** environ;
 
 namespace base {
