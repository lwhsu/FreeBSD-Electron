--- remoting/host/heartbeat_sender.cc.orig	2022-05-19 03:45:37 UTC
+++ remoting/host/heartbeat_sender.cc
@@ -111,7 +111,7 @@ const net::BackoffEntry::Policy kBackoffPolicy = {
 std::string GetHostname() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag
 // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return net::GetHostName();
 #elif BUILDFLAG(IS_WIN)
   wchar_t buffer[MAX_PATH] = {0};
