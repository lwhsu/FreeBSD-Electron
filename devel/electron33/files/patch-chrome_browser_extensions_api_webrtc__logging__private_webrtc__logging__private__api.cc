--- chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc.orig	2024-02-21 00:20:34 UTC
+++ chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc
@@ -29,7 +29,7 @@
 #include "extensions/browser/process_manager.h"
 #include "extensions/common/error_utils.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "extensions/common/permissions/permissions_data.h"
 #endif
 
@@ -38,7 +38,7 @@ bool CanEnableAudioDebugRecordingsFromExtension(
 bool CanEnableAudioDebugRecordingsFromExtension(
     const extensions::Extension* extension) {
   bool enabled_by_permissions = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (extension) {
     enabled_by_permissions =
         extension->permissions_data()->active_permissions().HasAPIPermission(
@@ -576,7 +576,7 @@ WebrtcLoggingPrivateGetLogsDirectoryFunction::Run() {
 
 ExtensionFunction::ResponseAction
 WebrtcLoggingPrivateGetLogsDirectoryFunction::Run() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Unlike other WebrtcLoggingPrivate functions that take a RequestInfo object,
   // this function shouldn't be called by a component extension on behalf of
   // some web code. It returns a DirectoryEntry for use directly in the calling
