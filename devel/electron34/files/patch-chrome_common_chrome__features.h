--- chrome/common/chrome_features.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/common/chrome_features.h
@@ -60,13 +60,13 @@ BASE_DECLARE_FEATURE(kUseAdHocSigningForWebAppShims);
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kAutofillAddressSurvey);
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kAutofillCardSurvey);
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kAutofillPasswordSurvey);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 BASE_DECLARE_FEATURE(kBackgroundModeAllowRestart);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -163,7 +163,7 @@ BASE_DECLARE_FEATURE(kDesktopPWAsTabStripSettings);
 COMPONENT_EXPORT(CHROME_FEATURES)
 BASE_DECLARE_FEATURE(kDesktopPWAsTabStripSettings);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kChromeAppsDeprecation);
 COMPONENT_EXPORT(CHROME_FEATURES)
 BASE_DECLARE_FEATURE(kShortcutsNotApps);
@@ -218,7 +218,7 @@ COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE
 
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kGeoLanguage);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kGlic);
 #endif
 
@@ -493,7 +493,7 @@ BASE_DECLARE_FEATURE(kKAnonymityServiceStorage);
 COMPONENT_EXPORT(CHROME_FEATURES)
 BASE_DECLARE_FEATURE(kKAnonymityServiceStorage);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kLinuxLowMemoryMonitor);
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::FeatureParam<int> kLinuxLowMemoryMonitorModerateLevel;
@@ -501,7 +501,7 @@ extern const base::FeatureParam<int> kLinuxLowMemoryMo
 extern const base::FeatureParam<int> kLinuxLowMemoryMonitorCriticalLevel;
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES) BASE_DECLARE_FEATURE(kListWebAppsSwitch);
 #endif
 
