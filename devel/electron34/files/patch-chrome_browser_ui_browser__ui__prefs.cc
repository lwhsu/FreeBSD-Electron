--- chrome/browser/ui/browser_ui_prefs.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -72,7 +72,7 @@ void RegisterBrowserPrefs(PrefRegistrySimple* registry
   registry->RegisterIntegerPref(prefs::kDefaultBrowserDeclinedCount, 0);
   registry->RegisterTimePref(prefs::kDefaultBrowserFirstShownTime,
                              base::Time());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -182,7 +182,7 @@ void RegisterBrowserUserPrefs(user_prefs::PrefRegistry
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForProfile,
