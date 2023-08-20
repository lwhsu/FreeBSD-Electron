--- chrome/browser/enterprise/connectors/analysis/content_analysis_delegate.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/enterprise/connectors/analysis/content_analysis_delegate.cc
@@ -52,7 +52,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/ui_base_types.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/content_analysis_sdk_manager.h"  // nogncheck
 #endif
 
@@ -557,7 +557,7 @@ void ContentAnalysisDelegate::PageRequestCallback(
 bool ContentAnalysisDelegate::UploadData() {
   upload_start_time_ = base::TimeTicks::Now();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If this is a local content analysis, check if the local agent is ready.
   // If not, abort early.  This is to prevent doing a lot of work, like reading
   // files into memory or calcuating SHA256 hashes and prevent a flash of the
