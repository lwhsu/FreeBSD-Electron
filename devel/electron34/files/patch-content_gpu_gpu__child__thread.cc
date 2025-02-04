--- content/gpu/gpu_child_thread.cc.orig	2025-01-27 17:37:37 UTC
+++ content/gpu/gpu_child_thread.cc
@@ -58,7 +58,7 @@
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -146,7 +146,8 @@ void GpuChildThread::Init(const base::TimeTicks& proce
 
   viz_main_.gpu_service()->set_start_time(process_start_time);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   SandboxedProcessThreadTypeHandler::NotifyMainChildThreadCreated();
 #endif
 
