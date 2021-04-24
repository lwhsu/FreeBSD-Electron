--- net/base/network_change_notifier_posix.cc.orig	2021-04-14 01:08:52 UTC
+++ net/base/network_change_notifier_posix.cc
@@ -93,7 +93,7 @@ void NetworkChangeNotifierPosix::GetCurrentMaxBandwidt
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPosix::NetworkChangeCalculatorParamsPosix() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::TimeDelta::FromMilliseconds(4000);
