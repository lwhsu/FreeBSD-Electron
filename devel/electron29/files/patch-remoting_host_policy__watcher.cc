--- remoting/host/policy_watcher.cc.orig	2023-11-29 21:40:08 UTC
+++ remoting/host/policy_watcher.cc
@@ -191,7 +191,7 @@ base::Value::Dict PolicyWatcher::GetDefaultPolicies() 
              true);
   result.Set(key::kRemoteAccessHostAllowEnterpriseFileTransfer, false);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   result.Set(key::kRemoteAccessHostMatchUsername, false);
 #endif
 #if !BUILDFLAG(IS_CHROMEOS)
