--- electron/shell/browser/api/electron_api_base_window.h.orig	2025-03-10 00:01:50 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -250,7 +250,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   void SetAppDetails(const gin_helper::Dictionary& options);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin_helper::Arguments* args);
 #endif
