--- content/public/common/content_features.h.orig	2023-03-30 00:33:51 UTC
+++ content/public/common/content_features.h
@@ -115,7 +115,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kFractionalScrollO
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGetDisplayMediaSet);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGetDisplayMediaSetAutoSelectAllScreens);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGreaseUACH);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kHandleRendererThreadTypeChangesInBrowser);
 #endif
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kIdleDetection);
