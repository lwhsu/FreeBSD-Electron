--- chrome/app/chrome_main_delegate.cc.orig	2023-08-10 01:48:31 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -139,7 +139,7 @@
 #include "components/about_ui/credit_utils.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -183,16 +183,16 @@
 #include "v8/include/v8.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/message_loop/message_pump_libevent.h"
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -330,7 +330,7 @@ void AdjustLinuxOOMScore(const std::string& process_ty
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -415,7 +415,7 @@ bool HandleVersionSwitches(const base::CommandLine& co
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -529,7 +529,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -618,7 +618,7 @@ void RecordMainStartupMetrics(base::TimeTicks applicat
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::RecordStartupProcessCreationTime(
@@ -967,7 +967,7 @@ void ChromeMainDelegate::CommonEarlyInitialization() {
   base::InitializeCpuReductionExperiment();
   base::sequence_manager::internal::SequenceManagerImpl::InitializeFeatures();
   base::sequence_manager::internal::ThreadController::InitializeFeatures();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   base::MessagePumpLibevent::InitializeFeatures();
 #elif BUILDFLAG(IS_MAC)
   base::PlatformThread::InitFeaturesPostFieldTrial();
@@ -1106,7 +1106,7 @@ absl::optional<int> ChromeMainDelegate::BasicStartupCo
 
   // TODO(crbug.com/1052397): Revisit the macro expression once build flag
   // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -1136,7 +1136,7 @@ absl::optional<int> ChromeMainDelegate::BasicStartupCo
 #if BUILDFLAG(IS_CHROMEOS)
   chromeos::dbus_paths::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if BUILDFLAG(ENABLE_NACL) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   nacl::RegisterPathProvider();
 #endif
 
@@ -1510,7 +1510,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     CHECK(!loaded_locale.empty()) << "Locale could not be found for " << locale;
   }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
     if (command_line.HasSwitch(switches::kPreCrashpadCrashTest)) {
@@ -1612,7 +1612,7 @@ absl::variant<int, content::MainFunctionParams> Chrome
 
   // This entry is not needed on Linux, where the NaCl loader
   // process is launched via nacl_helper instead.
-#if BUILDFLAG(ENABLE_NACL) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(ENABLE_NACL) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
     {switches::kNaClLoaderProcess, NaClMain},
 #else
     {"<invalid>", nullptr},  // To avoid constant array of size 0
