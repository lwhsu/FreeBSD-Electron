--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -117,7 +117,7 @@ namespace web_app {
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
              "DesktopPWAsForceUnregisterOSIntegration",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
