--- components/feature_engagement/public/feature_constants.cc.orig	2023-08-10 01:48:40 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kUseClientConfigIPH,
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillFeedbackNewBadgeFeature,
              "IPH_AutofillFeedbackNewBadge",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -508,7 +508,8 @@ BASE_FEATURE(kIPHiOSPromoPostRestoreDefaultBrowserFeat
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature,
              "IPH_AutofillExternalAccountProfileSuggestion",
              base::FEATURE_ENABLED_BY_DEFAULT);
