--- chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -216,7 +216,7 @@ CertificateManagerPageHandler::GetCertSource(
                 CERTIFICATE_TRUST_TYPE_DISTRUSTED,
             profile_, &remote_client_);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager_v2::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
