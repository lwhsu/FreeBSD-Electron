--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -123,16 +123,16 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/commerce/product_specifications_ui.h"
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/whats_new/whats_new_ui.h"
 #endif
 
@@ -412,7 +412,7 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
   if (page_url.host_piece() == chrome::kChromeUINewTabPageHost)
     return NewTabPageUI::GetFaviconResourceBytes(scale_factor);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (page_url.host_piece() == chrome::kChromeUIWhatsNewHost)
     return WhatsNewUI::GetFaviconResourceBytes(scale_factor);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -440,7 +440,7 @@ base::RefCountedMemory* ChromeWebUIControllerFactory::
     return ManagementUI::GetFaviconResourceBytes(scale_factor);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (page_url.host_piece() == commerce::kChromeUICompareHost) {
     return commerce::ProductSpecificationsUI::GetFaviconResourceBytes(
         scale_factor);
