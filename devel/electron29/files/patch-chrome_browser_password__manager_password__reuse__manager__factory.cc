--- chrome/browser/password_manager/password_reuse_manager_factory.cc.orig	2024-02-21 00:20:35 UTC
+++ chrome/browser/password_manager/password_reuse_manager_factory.cc
@@ -136,7 +136,7 @@ PasswordReuseManagerFactory::BuildServiceInstanceForBr
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
