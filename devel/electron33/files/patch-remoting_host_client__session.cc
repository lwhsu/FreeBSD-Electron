--- remoting/host/client_session.cc.orig	2024-10-16 21:31:37 UTC
+++ remoting/host/client_session.cc
@@ -161,7 +161,7 @@ void ClientSession::NotifyClientResolution(
   if (desktop_environment_options_.enable_curtaining()) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
