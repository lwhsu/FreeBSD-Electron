--- chrome/browser/ui/passwords/manage_passwords_ui_controller.cc.orig	2024-10-16 21:31:02 UTC
+++ chrome/browser/ui/passwords/manage_passwords_ui_controller.cc
@@ -93,7 +93,7 @@ using Logger = autofill::SavePasswordProgressLogger;
 
 using Logger = autofill::SavePasswordProgressLogger;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Should be kept in sync with constant declared in
 // bubble_controllers/relaunch_chrome_bubble_controller.cc.
 constexpr int kMaxNumberOfTimesKeychainErrorBubbleIsShown = 3;
@@ -513,7 +513,7 @@ void ManagePasswordsUIController::OnKeychainError() {
 }
 
 void ManagePasswordsUIController::OnKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!dialog_controller_);
   PrefService* prefs =
       Profile::FromBrowserContext(web_contents()->GetBrowserContext())
