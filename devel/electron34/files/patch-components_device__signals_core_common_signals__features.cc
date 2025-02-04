--- components/device_signals/core/common/signals_features.cc.orig	2025-01-27 17:37:37 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -50,7 +50,7 @@ bool IsNewFunctionEnabled(NewEvFunction new_ev_functio
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
