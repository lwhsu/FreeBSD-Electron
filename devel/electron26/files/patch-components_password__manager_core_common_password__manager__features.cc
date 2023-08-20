--- components/password_manager/core/common/password_manager_features.cc.orig	2023-08-10 01:48:40 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -96,7 +96,7 @@ BASE_FEATURE(kPasswordManagerLogToTerminal,
              "PasswordManagerLogToTerminal",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -211,7 +211,7 @@ BASE_FEATURE(kRevampedPasswordManagementBubble,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
