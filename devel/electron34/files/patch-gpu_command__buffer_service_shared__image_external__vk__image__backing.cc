--- gpu/command_buffer/service/shared_image/external_vk_image_backing.cc.orig	2025-01-27 17:37:37 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing.cc
@@ -57,7 +57,7 @@
 #include "ui/gl/gl_version_info.h"
 #include "ui/gl/scoped_binders.h"
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
 #include "gpu/command_buffer/service/shared_image/external_vk_image_dawn_representation.h"
 #if BUILDFLAG(DAWN_ENABLE_BACKEND_OPENGLES)
 #include "gpu/command_buffer/service/shared_image/dawn_gl_texture_representation.h"
@@ -702,7 +702,7 @@ std::unique_ptr<DawnImageRepresentation> ExternalVkIma
     wgpu::BackendType backend_type,
     std::vector<wgpu::TextureFormat> view_formats,
     scoped_refptr<SharedContextState> context_state) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
   auto wgpu_format = ToDawnFormat(format());
 
   if (wgpu_format == wgpu::TextureFormat::Undefined) {
