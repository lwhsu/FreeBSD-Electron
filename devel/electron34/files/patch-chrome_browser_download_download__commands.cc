--- chrome/browser/download/download_commands.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/download/download_commands.cc
@@ -26,7 +26,7 @@
 #include "ui/base/clipboard/scoped_clipboard_writer.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/scoped_tabbed_browser_displayer.h"
@@ -165,7 +165,7 @@ void DownloadCommands::ExecuteCommand(Command command)
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 Browser* DownloadCommands::GetBrowser() const {
   if (!model_)
