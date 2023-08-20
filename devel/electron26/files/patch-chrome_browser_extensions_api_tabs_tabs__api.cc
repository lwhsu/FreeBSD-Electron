--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -833,7 +833,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // ui::SHOW_STATE_MINIMIZED above, on Linux the window is not created as
 // minimized.
 // TODO(crbug.com/1410400): Remove this workaround when linux is fixed.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1410400): Find a fix for wayland as well.
 
 // Must be defined inside IS_LINUX to compile on windows/mac.
