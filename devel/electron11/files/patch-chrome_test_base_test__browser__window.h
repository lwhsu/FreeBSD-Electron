--- chrome/test/base/test_browser_window.h.orig	2021-01-07 00:36:26 UTC
+++ chrome/test/base/test_browser_window.h
@@ -179,7 +179,7 @@ class TestBrowserWindow : public BrowserWindow {
       bool is_source_keyboard) override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsBubble(const std::string& site_id) override {}
 #endif
 
