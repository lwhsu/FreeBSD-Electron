--- components/feature_engagement/public/feature_constants.h.orig	2025-01-27 17:37:37 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -20,7 +20,7 @@ BASE_DECLARE_FEATURE(kIPHDummyFeature);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 BASE_DECLARE_FEATURE(kEsbDownloadRowPromoFeature);
 #endif
@@ -261,7 +261,8 @@ BASE_DECLARE_FEATURE(kDefaultBrowserTriggerCriteriaExp
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillCreditCardBenefitFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillDisabledVirtualCardSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
@@ -314,7 +315,7 @@ BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 BASE_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunchAppInTab);
 BASE_DECLARE_FEATURE(kIPHToolbarManagementButtonFeature);
