--- chrome/browser/ui/ui_features.h.orig	2024-10-16 21:31:02 UTC
+++ chrome/browser/ui/ui_features.h
@@ -78,7 +78,7 @@ BASE_DECLARE_FEATURE(kAccessCodeCastUI);
 BASE_DECLARE_FEATURE(kAccessCodeCastUI);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -258,7 +258,7 @@ BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer)
 
 BASE_DECLARE_FEATURE(kTopChromeWebUIUsesSpareRenderer);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUpdateTextOptions);
 extern const base::FeatureParam<int> kUpdateTextOptionNumber;
 #endif
@@ -283,7 +283,7 @@ BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWin
 
 BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWindow);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
