--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2024-08-14 20:54:51 UTC
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -204,7 +204,7 @@ void PasswordManualFallbackFlow::DidAcceptSuggestion(
                          payload.password));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       if (payload.is_cross_domain) {
         cross_domain_confirmation_popup_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
