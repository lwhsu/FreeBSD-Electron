--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -16,7 +16,7 @@
 #include "services/screen_ai/public/cpp/utilities.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "base/files/file_util.h"
 #endif
@@ -26,7 +26,7 @@ bool IsDeviceCompatible() {
 const char kMinExpectedVersion[] = "124.2";
 
 bool IsDeviceCompatible() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
