--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2024-10-16 21:31:30 UTC
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -142,7 +142,7 @@ constexpr SharedImageUsageSet kSupportedUsage =
 }  // namespace
 
 constexpr SharedImageUsageSet kSupportedUsage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
     SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
     SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
     SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
