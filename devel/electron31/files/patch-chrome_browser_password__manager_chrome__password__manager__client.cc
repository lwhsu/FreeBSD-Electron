--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2024-06-18 21:43:23 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -488,7 +488,7 @@ bool ChromePasswordManagerClient::CanUseBiometricAuthF
 
 bool ChromePasswordManagerClient::CanUseBiometricAuthForFilling(
     device_reauth::DeviceAuthenticator* authenticator) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -712,7 +712,7 @@ void ChromePasswordManagerClient::NotifyKeychainError(
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   manage_passwords_ui_controller->OnKeychainError();
