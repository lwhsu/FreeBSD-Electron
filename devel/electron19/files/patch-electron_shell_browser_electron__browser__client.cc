--- electron/shell/browser/electron_browser_client.cc.orig	2022-06-30 15:53:29 UTC
+++ electron/shell/browser/electron_browser_client.cc
@@ -186,7 +186,7 @@
 #include "content/public/common/child_process_host.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !defined(MAS_BUILD)
+#if BUILDFLAG(IS_LINUX) && !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
 #include "components/crash/core/app/breakpad_linux.h"  // nogncheck
