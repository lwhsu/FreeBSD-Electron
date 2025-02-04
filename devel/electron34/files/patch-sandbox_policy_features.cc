--- sandbox/policy/features.cc.orig	2025-01-27 17:37:37 UTC
+++ sandbox/policy/features.cc
@@ -20,7 +20,11 @@ BASE_FEATURE(kNetworkServiceSandbox,
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
@@ -132,7 +136,7 @@ BASE_FEATURE(kSpectreVariant2Mitigation,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabling the kNetworkServiceSandbox feature automatically enables Spectre
 // variant 2 mitigations in the network service. This can lead to performance
 // regressions, so enabling this feature will turn off the Spectre Variant 2
